const uint8_t flexPin = A0;

const uint32_t datastreamId = xxx; //

// more info: https://www.instructables.com/How-to-use-a-Flex-Sensor-Arduino-Tutorial/

void setupSensors() {
  // A0 for analog in
}

float measureFlex()
{
  auto value = analogRead(flexPin);         //Read and save analog value from potentiometer

  Serial.print("Flex: ");
  Serial.println(value);

  return value;
}

void loopSensors() {
  JSONVar observation;
  //  observation["FeatureOfInterest"] = featureOfInterest;
  //  observation["phenomenonTime"] = getISO8601dateTime();
  observation["result"] = measureFlex();

  transmitValue(datastreamId, observation);
}
