#include <Wire.h> // standard library, no need to install
#include <ADXL345.h> // url:

int x, y, z;
double xyz[3];

void setupSensors() {
  adxl.powerOn();
}

void loopSensors()
{
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

  adxl.readXYZ(&x, &y, &z); //read the accelerometer values and store them in variables  x,y,z
  adxl.getAcceleration(xyz);

  //  observation["result"] = measureTemperature();
  transmitValue(3, observation);

  //  observation["result"] = measurePressure();
  transmitValue(4, observation);

  delay(100); // 10Hz
}
