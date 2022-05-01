
#include <Wire.h>
#include <ADXL345.h> // url:

ADXL345 adxl; // variable adxl is an instance of the ADXL345 library

void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  delay(1000);

  adxl.powerOn();
}

void loop()
{
  // Boring accelerometer stuff
  int x, y, z;
  adxl.readXYZ(&x, &y, &z); //read the accelerometer values and store them in variables  x,y,z

  // Output x,y,z values
  Serial.print("values of X , Y , Z: ");
  Serial.print(x);
  Serial.print(" , ");
  Serial.print(y);
  Serial.print(" , ");
  Serial.println(z);

  double xyz[3];
  adxl.getAcceleration(xyz);
  
  auto ax = xyz[0];
  auto ay = xyz[1];
  auto az = xyz[2];
  Serial.print("X=");
  Serial.print(ax);
  Serial.println(" g");
  Serial.print("Y=");
  Serial.print(ay);
  Serial.println(" g");
  Serial.print("Z=");
  Serial.print(az);
  Serial.println(" g");
  Serial.println("**********************");
  
  delay(500);
}
