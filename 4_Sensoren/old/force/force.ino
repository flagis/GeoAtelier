void setup() {
  Serial.begin(115200);
  while (Serial) {}
  delay(1000);
}

void loop() {
  auto sensorValue = analogRead(A0);
  
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1000);
}
