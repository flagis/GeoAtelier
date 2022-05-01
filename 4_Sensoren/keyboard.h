
void setupSensors() {
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  pinMode(D4, INPUT);
}

void loopSensors() {
  auto k1 = digitalRead(D1);
  auto k2 = digitalRead(D2);
  auto k3 = digitalRead(D3);
  auto k4 = digitalRead(D4);

  byte sum = 0;
  if (k1) bitSet(sum, 0);
  if (k2) bitSet(sum, 1);
  if (k3) bitSet(sum, 2);
  if (k4) bitSet(sum, 3);

  Serial.print(k1);
  Serial.print(" ");
  Serial.print(k2);
  Serial.print(" ");
  Serial.print(k3);
  Serial.print(" ");
  Serial.print(k4);
  Serial.print(" ");
  Serial.print(sum, BIN);
  Serial.println();
}
