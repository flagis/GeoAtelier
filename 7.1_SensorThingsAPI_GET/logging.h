#pragma once

void setupLogging(uint32_t baudrate = 115200)
{
  Serial.begin(baudrate);
  while (!Serial);
  delay(1000);
  Serial.println("\nBooting");
}
