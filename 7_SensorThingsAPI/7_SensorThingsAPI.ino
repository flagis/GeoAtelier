#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Arduino_JSON.h> // from https://github.com/arduino-libraries/Arduino_JSON

#include "logging.h"
#include "credentials.h"
#include "stapi_settings.h"
#include "wifi.h"
#include "gps.h"

void transmitValue(int datastreamId, JSONVar observation);

//#include "sensors/ADXL345.h"
//#include "sensors/BMP085.h"
//#include "sensors/BMP180.h"
//#include "sensors/buttons.h"
//#include "sensors/HMC5883.h"
//#include "sensors/HX711.h"
#include "sensors/HCSR04.h"

void setup()
{
  setupLogging();
  setupSensors();
  setupGPS();

  connect2Wifi(ssid, pass);
}

void transmitValue(int datastreamId, JSONVar observation)
{
  WiFiClient client;
  HTTPClient http;

  String httpRequestData = JSON.stringify(observation);

  String url = base_url + "/Datastream(" + datastreamId + ")/Observations";
  Serial.println(url);
  Serial.println(httpRequestData);
  /*
    http.begin(client, url);
    http.addHeader("Content-Type", "application/json");
    auto httpResponseCode = http.POST(httpRequestData);
    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      String payload = http.getString();
      Serial.println(payload);
    }

    http.end();
  */
}

void loop()
{
  loopGPS();
  loopSensors();
}
