#include <Wire.h> // standard library, no need to install
#include <ADXL345.h> // url:

int x, y, z;
double xyz[3];

void setupSensor() {
  adxl.powerOn();
}

void loopSensor() {
  adxl.readXYZ(&x, &y, &z); //read the accelerometer values and store them in variables  x,y,z
  adxl.getAcceleration(xyz);

  delay(500);
}
