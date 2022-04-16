const uint8_t flexPin = A0;

// more info: https://www.instructables.com/How-to-use-a-Flex-Sensor-Arduino-Tutorial/

void setupSensors() {
  // A0 for analog in
}

void loopSensors() {
  auto value = analogRead(flexPin);         //Read and save analog value from potentiometer
  Serial.println(value);               //Print value

  delay(200);
}
