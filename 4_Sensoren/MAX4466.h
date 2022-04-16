const uint8_t soundPin = A0; // analoge uitgang van versterkt microfoon signaal

void setupSensors() {
  // A0 for analog in
}

void loopSensors() {
  auto value = analogRead(soundPin);         //Read and save analog value from potentiometer

  Serial.print("level: ");
  Serial.println(value);
}
