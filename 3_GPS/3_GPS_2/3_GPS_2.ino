#include <TinyGPSPlus.h> // https://github.com/mikalhart/TinyGPSPlus
#include <SoftwareSerial.h>
#include <Arduino_JSON.h>

const uint8_t RXPin = D5;
const uint8_t TXPin = D6;
const uint32_t GPSBaud = 9600;

// The TinyGPSPlus object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

char dateTime[80];

void setup()
{
  Serial.begin(115200);
  while (!Serial) {}
  delay(1000);
  Serial.println();

  ss.begin(GPSBaud);
}

void loop()
{
  // Dispatch incoming characters
  while (ss.available() > 0)
    gps.encode(ss.read());

  if (gps.location.isUpdated() || gps.altitude.isUpdated())
  {
    if (gps.location.isValid() && gps.altitude.isValid()) {
      JSONVar coordinates;
      coordinates[0] = gps.location.lat();
      coordinates[1] = gps.location.lng();
      coordinates[2] = gps.altitude.meters();

      JSONVar location;
      location["type"] = "Point";
      location["coordinates"] = coordinates;

      Serial.println(location);
    }

  }
  if (gps.date.isUpdated() || gps.time.isUpdated())
  {
    if (gps.date.isValid() && gps.time.isValid()) {
      // make ISO8601 date time
      sprintf(dateTime, "%04d-%02d-%02dT%02d:%02d:%02d.%02dZ", gps.date.year(), gps.date.month(), gps.date.day(), gps.time.hour(), gps.time.minute(), gps.time.second(), gps.time.centisecond());

      Serial.println(dateTime);
    }
  }

  if (gps.charsProcessed() < 10)
    Serial.println(F("WARNING: No GPS data. Check wiring."));
}
