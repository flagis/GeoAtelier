const uint8_t flexPin = A0;

// more info: https://www.instructables.com/How-to-use-a-Flex-Sensor-Arduino-Tutorial/

void setupSensors() {
  // A0 for analog in
}

void loopSensors() {
  auto value = analogRead(flexPin);
  Serial.println(value);               //Print value

  transmitValue(value);
}
