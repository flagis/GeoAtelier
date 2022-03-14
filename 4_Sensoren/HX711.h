#include <HX711.h> // https://github.com/RobTillaart/HX711

HX711 scale; // instance

const uint8_t dataPin = D2;
const uint8_t clockPin = D3;

void start() {
  scale.begin(dataPin, clockPin);

  // Scale resolution max 5kg
  scale.set_scale(476); // manually calibrated

  // reset the scale to zero = 0
  scale.tare();

}

void measure() {
  auto f = scale.get_units(5);
}
