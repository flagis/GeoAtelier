#include <AGS02MA.h> // https://github.com/RobTillaart/AGS02MA

AGS02MA AGS(26); // 26 =

void setupSensor() {
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

void loopSensor() {
  Serial.print("PPM:\t");
  Serial.print(AGS.readPPM(), 3);
  Serial.print("\t");
  Serial.print(AGS.dataReady(), HEX);
  Serial.print("\t");
  Serial.print(AGS.lastStatus(), HEX);
  Serial.print("\t");
  Serial.print(AGS.lastError(), HEX);
  Serial.println();
}
