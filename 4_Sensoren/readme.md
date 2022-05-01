# Reading values from the sensors

## Identify your sensor!
What sensor did you receive?
* ADXL345
* BMP085
* BMP180
* buttons
* HMC5883
* HX711
* HCSR04

## Activate the code

Uncomment the include file for your sensor:

In the below example, the HCSR04 is activiate. Only 1 sensor can be activated at a time.
```cpp
//#include "ADXL345.h"
//#include "BMP085.h"
//#include "BMP180.h"
//#include "buttons.h"
//#include "HMC5883.h"
//#include "HX711.h"
#include "HCSR04.h"
```