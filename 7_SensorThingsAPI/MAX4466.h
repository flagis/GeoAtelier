const uint8_t soundPin = A0; // analoge uitgang van versterkt microfoon signaal

const uint32_t datastreamId = xxx; //

void setupSensors() {
  // A0 for analog in
}

float measureLevel()
{
  auto value = analogRead(soundPin);         //Read and save analog value from potentiometer

  Serial.print("level: ");
  Serial.println(value);

   return value;
}

void loopSensors() {
  JSONVar observation;
  //  observation["FeatureOfInterest"] = featureOfInterest;
  //  observation["phenomenonTime"] = getISO8601dateTime();
  observation["result"] = measureLevel();

  transmitValue(datastreamId, observation);

  delay(100); // 10Hz
}
