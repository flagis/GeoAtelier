#include "../dateTime.h"

// zie: https://create.arduino.cc/projecthub/abdularbi17/ultrasonic-sensor-hc-sr04-with-arduino-tutorial-327ff6

const uint8_t trigPin = D8;
const uint8_t echoPin = D7;

float distance = -1.0f;

void setupSensors() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void measureDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  auto duration = pulseIn(echoPin, HIGH); // duration in xxx
  distance = (duration) * 0.0343 / 2; // Speed of sound (343 m/s) divided by 2 (to go and back)

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}

void loopSensors() {
  delay(100);

  JSONVar point;
  point["type"] = "Point";
  JSONVar coordinates;
  coordinates[0] = lat;
  coordinates[1] = lng;
  point["coordinates"] = coordinates;

  JSONVar featureOfInterest;
  featureOfInterest["name"] = "hier"; // TODO
  featureOfInterest["description"] = "iets meer naar ginder"; // TODO
  featureOfInterest["encodingType"] = "application/vnd.geo+json";
  featureOfInterest["feature"] = point;

  JSONVar observation;
  observation["phenomenonTime"] = getISO8601dateTime();
  observation["result"] = distance;
  observation["FeatureOfInterest"] = featureOfInterest;

  measureDistance();

  transmitValue(3, observation);
}
