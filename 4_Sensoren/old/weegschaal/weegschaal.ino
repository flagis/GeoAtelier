#include "HX711.h" // https://github.com/RobTillaart/HX711

HX711 scale; // instance 

const uint8_t dataPin = D2;
const uint8_t clockPin = D3;

float weight = 0.0f;

void setup()
{
  scale.begin(dataPin, clockPin);

  // Scale resolution max 5kg
  scale.set_scale(476); // manually calibrated
 
  scale.tare(); // reset the scale to zero = 0
}

void loop()
{
  weight = scale.get_units(5);
  Serial.println(f);
  delay(250); // continuously measure, 4x per second
}
