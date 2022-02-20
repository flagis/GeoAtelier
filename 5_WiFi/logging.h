#pragma once

void startLogging()
{
  Serial.begin(115200);
  while (!Serial);
  delay(1000);
  Serial.println("Booting");
}
