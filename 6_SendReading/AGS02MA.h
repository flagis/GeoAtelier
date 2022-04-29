#include <AGS02MA.h> // https://github.com/RobTillaart/AGS02MA

AGS02MA AGS(26); // 26 =

void setupSensors() {
  Wire.begin();
  bool b = AGS.begin();

  Serial.println("\nWarming up (120 seconds = 24 dots)");
  while (AGS.isHeated() == false)
  {
    delay(5000);
    Serial.print(".");
  }
  Serial.println();

  b = AGS.setPPBMode();
  uint8_t m = AGS.getMode();
}

void loopSensors() {
  delay(500);

  auto ppm = AGS.readPPM();

  Serial.print("PPM:\t");
  Serial.print(ppm, 3);
  Serial.print("\t");
  Serial.print(AGS.dataReady(), HEX);
  Serial.print("\t");
  Serial.print(AGS.lastStatus(), HEX);
  Serial.print("\t");
  Serial.print(AGS.lastError(), HEX);
  Serial.println();

  transmitValue(ppm);
}
