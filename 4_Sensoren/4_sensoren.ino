#include "utils/logging.h"

//#include "1234.h"
//#include "ADXL345.h"
//#include "BMP085.h"
//#include "BMP180.h"
//#include "buttons.h"
//#include "HMC5883.h"
//#include "HX711.h"
//#include "HCSR04.h"
//#include "MB060.h"
//#include "MAX4466.h"
//#include "AM2320.h"
//#include "AGS02MA.h"

void setup() {
  setupLogging();
  setupSensors();
}

void loop() {
  loopSensors();
}
