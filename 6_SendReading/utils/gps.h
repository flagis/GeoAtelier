#pragma once

#include <TinyGPSPlus.h> // https://github.com/mikalhart/TinyGPSPlus
#include <SoftwareSerial.h>

const uint8_t RXPin = D5;
const uint8_t TXPin = D6;
const uint32_t GPSBaud = 9600;

TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);

void setupGPS()
{
  ss.begin(GPSBaud);
}


void loopGPS()
{
  while (ss.available() > 0)
    gps.encode(ss.read());

  if (gps.location.isUpdated())
  {
    lat = gps.location.lat();
    lng = gps.location.lng();
  }
}
