#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Arduino_JSON.h> // from https://github.com/arduino-libraries/Arduino_JSON

#include "utils/logging.h"
#include "utils/credentials.h"
#include "utils/stapi_settings.h"
#include "utils/wifi.h"
#include "utils/gps.h"
#include "utils/dateTime.h"

// forward declaration, so it can be used in readSensors
void transmitValue(const int datastreamId, const JSONVar& observation);

// Uncomment the line below, corresponding with the used sensors
//#include "ADXL345.h"
//#include "BMP085.h"
//#include "BMP180.h"
//#include "buttons.h"
//#include "HMC5883.h"
#include "HX711.h"
//#include "HCSR04.h"
//#include "MB060.h"
//#include "MAX4466.h"

void setup()
{
  setupLogging();
  setupSensors();
  setupGPS();

  connect2Wifi(ssid, pass);
}

void transmitValue(const int datastreamId, const JSONVar& observation)
{
  String url = base_url + "/Datastreams(" + datastreamId + ")/Observations";
  Serial.println(url);

  String httpRequestData = JSON.stringify(observation);
  Serial.println(httpRequestData);

  WiFiClient client;
  HTTPClient http;
  http.begin(client, url);
  http.addHeader("Content-Type", "application/json");
  auto httpResponseCode = http.POST(httpRequestData);
  Serial.print("HTTP Response code: ");
  Serial.println(httpResponseCode);
  if (httpResponseCode > 0) {
    String payload = http.getString();
    Serial.println(payload);
  }

  http.end();
}

void loop()
{
  loopGPS();
  loopSensors();
}
