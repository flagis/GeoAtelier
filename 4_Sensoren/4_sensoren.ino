#include "ADXL345.h"
//#include "BMP085.h"
//#include "BMP180.h"
//#include "buttons.h"
//#include "HMC5883.h"
//#include "HX711.h"
//#include "HCSR04.h"

#include "logging.h"

void setup() {
  startLogging();
  startSensor();
}

void loop() {
  readSensor();
}
