#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

/* Assign a unique ID to this sensor at the same time */
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

void setupSensors() {
  if (!mag.begin())
    Serial.println("Ooops, no HMC5883 detected ... Check your wiring!");
}

void loopSensors()
{
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
  observation["FeatureOfInterest"] = featureOfInterest;

  observation["result"] = measureDistance();
  transmitValue(3, observation);

  delay(100); // 10Hz
}