#include <HX711.h> // https://github.com/RobTillaart/HX711

HX711 scale; // instance

const uint8_t dataPin = D2;
const uint8_t clockPin = D3;

uint16 calibrate = 476; // manually calibrated, magic number

void setupSensors() {
  scale.begin(dataPin, clockPin);

  // Scale resolution max 5kg
  scale.set_scale(calibrate); // manually calibrated

  // reset the scale to zero = 0
  scale.tare();
}

const float measureWeight()
{
  auto weight = scale.get_units(5);

  Serial.print("Weight: ");
  Serial.print(weight);
  Serial.println(" g");

  return weight;
}

void loopSensors() {
  auto value = measureWeight();

  transmitValue(value);
}
