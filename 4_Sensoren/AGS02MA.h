//  AGS02MA PIN layout             AGS02MA COLOR   PIN
//  ==================================================
//   bottom view  DESCRIPTION     COLOR
//       +---+
//       |o  |       VDD          RED
//       |o  |       SDA          YELLOW          D2
//       |o  |       GND          BLACK
//       |o  |       SCL          GREEN           D1
//       +---+
//
#include <AGS02MA.h> // https://github.com/RobTillaart/AGS02MA

AGS02MA AGS(26);

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
  Serial.print("MODE:\t");
  Serial.print(b);
  Serial.print("\t");
  Serial.println(m);
}

void loopSensors() {
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
