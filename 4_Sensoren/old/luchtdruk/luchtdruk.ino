#include "BMP085.h"
#include <Wire.h>

BMP085 myBarometer;

void setup() {
  Serial.begin(115200);
  while (!Serial);
  delay(1000);

  myBarometer.init();
}

void loop() {
  auto temperature = myBarometer.bmp085GetTemperature(myBarometer.bmp085ReadUT()); //Get the temperature, bmp085ReadUT MUST be called first
  auto pressure = myBarometer.bmp085GetPressure(myBarometer.bmp085ReadUP());//Get the temperature

  /*
      To specify a more accurate altitude, enter the correct mean sea level
      pressure level.  For example, if the current pressure level is 1019.00 hPa
      enter 101900 since we include two decimal places in the integer value。
  */
  auto altitude = myBarometer.calcAltitude(101900);

  auto atm = pressure / 101325;

  Serial.print("Temperature: ");
  Serial.print(temperature, 2); //display 2 decimal places
  Serial.println(" Celsius");

  Serial.print("Pressure: ");
  Serial.print(pressure, 0); //whole number only.
  Serial.println(" Pa");

  Serial.print("Ralated Atmosphere: ");
  Serial.println(atm, 4); //display 4 decimal places

  Serial.print("Altitude: ");
  Serial.print(altitude, 2); //display 2 decimal places
  Serial.println(" m");

  Serial.println();

  delay(1000); //wait a second and get values again.
}
