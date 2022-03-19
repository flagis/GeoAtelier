//#include "sensors/ADXL345.h"
//#include "sensors/BMP085.h"
//#include "sensors/BMP180.h"
//#include "sensors/buttons.h"
//#include "sensors/HMC5883.h"
//#include "sensors/HX711.h"
#include "sensors/HCSR04.h"

#include "logging.h"

void setup() {
  setupLogging();
  setupSensors();
}

void loop() {
  loopSensors();
}
