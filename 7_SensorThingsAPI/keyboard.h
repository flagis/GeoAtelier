const uint32_t datastreamId = xxx; //

void setupSensors() {
  pinMode(D3, INPUT);
  pinMode(D4, INPUT);
}

void loopSensors() {
  auto k1 = digitalRead(D4);
  auto k2 = digitalRead(D3);

  byte sum = 0;
  if (k1) bitSet(sum, 0);
  if (k2) bitSet(sum, 1);

  Serial.print(k1);
  Serial.print(" ");
  Serial.print(k2);
  Serial.print(" ");
  Serial.print(sum, BIN);
  Serial.println();

  JSONVar observation;
  //  observation["FeatureOfInterest"] = featureOfInterest;
  //  observation["phenomenonTime"] = getISO8601dateTime();
  observation["result"] = sum;

  transmitValue(datastreamId, observation);
  
  delay(1000);
}
