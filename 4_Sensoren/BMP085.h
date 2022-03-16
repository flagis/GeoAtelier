#include <Wire.h>
#include <BMP085.h>

BMP085 myBarometer;

float temperature;
float pressure;

void startSensor() {
  myBarometer.init();
}

void readSensor() {
  temperature = myBarometer.bmp085GetTemperature(myBarometer.bmp085ReadUT());
  pressure = myBarometer.bmp085GetPressure(myBarometer.bmp085ReadUP());
}
