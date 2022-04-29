#include <Adafruit_BMP085.h>

// Connect VCC of the BMP085 sensor to 3.3V (NOT 5.0V!)
// Connect GND to Ground
// Connect SCL to i2c clock
// Connect SDA to i2c data

Adafruit_BMP085 myBarometer;

float pressure;

void setupSensors() {
  myBarometer.begin();
}

void loopSensors() {
  float pressure = myBarometer.readPressure() / 100;

  Serial.print(pressure, 2);
  Serial.println(" hPa");

  delay (100);
}
