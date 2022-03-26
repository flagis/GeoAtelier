#include <Wire.h>
#include <Adafruit_BMP085.h> // from library manager: Adafruit BMP085 library (1.2.1) (non unified)

Adafruit_BMP085 bmp;

const uint32_t datastreamId1 = 666; //
const uint32_t datastreamId2 = 666; //

const float measureTemperature()
{
  return bmp.readTemperature();
}

const float measurePressure()
{
  return bmp.readPressure();
}

void setupSensors() {
  if (!bmp.begin())
    Serial.println("error initializing BMO085");
}

void loopSensors() {
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

  JSONVar observation;
  observation["phenomenonTime"] = getISO8601dateTime();
  observation["FeatureOfInterest"] = featureOfInterest;

  observation["result"] = measureTemperature();
  transmitValue(datastreamId1, observation);

  observation["result"] = measurePressure();
  transmitValue(datastreamId2, observation);

  delay(100); // 10Hz
}
