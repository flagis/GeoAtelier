#include <AGS02MA.h> // https://github.com/RobTillaart/AGS02MA

AGS02MA AGS(26); // 26 =

const uint32_t datastreamId = xxx; //

const float measurePPM()
{
  return AGS.readPPM();
}

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

void loopSensors()
{
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
  
  /*
    JSONVar point;
    point["type"] = "Point";
    JSONVar coordinates;
    coordinates[0] = lat;
    coordinates[1] = lng;
    point["coordinates"] = coordinates;

    JSONVar featureOfInterest;
    featureOfInterest["name"] = "hier"; // TODO
    featureOfInterest["description"] = "iets meer naar ginder"; // TODO
    featureOfInterest["encodingType"] = "application/vnd.geo+json";
    featureOfInterest["feature"] = point;
  */
  JSONVar observation;
  //  observation["FeatureOfInterest"] = featureOfInterest;
  //  observation["phenomenonTime"] = getISO8601dateTime();
  observation["result"] = ppm;

  transmitValue(datastreamId, observation);

  delay(100); // 10Hz
}
