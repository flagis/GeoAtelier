// zie: https://create.arduino.cc/projecthub/abdularbi17/ultrasonic-sensor-hc-sr04-with-arduino-tutorial-327ff6

const uint8_t trigPin = D8;
const uint8_t echoPin = D7;

float distance = -1.0f;

void setupSensors() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loopSensors() {
  delay(10);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  auto duration = pulseIn(echoPin, HIGH); // duration in xxx
  distance = (duration) * 0.0343 / 2; // Speed of sound (343 m/s) divided by 2 (to go and back)

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  transmitValue(distance);
}
