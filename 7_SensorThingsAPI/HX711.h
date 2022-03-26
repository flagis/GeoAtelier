#include <HX711.h> // https://github.com/RobTillaart/HX711

HX711 scale; // instance

const uint8_t dataPin = D2;
const uint8_t clockPin = D3;

const uint32_t datastreamId = 666; //

const float measureWeight()
{
  return scale.get_units(5);
}

void setupSensors() {
  scale.begin(dataPin, clockPin);

  // Scale resolution max 5kg
  scale.set_scale(476); // manually calibrated

  // reset the scale to zero = 0
  scale.tare();
}

void loopSensors()
{
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
  observation["result"] = measureWeight();

  transmitValue(datastreamId, observation);

  delay(100); // 10Hz
}
