#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Arduino_JSON.h> // from https://github.com/arduino-libraries/Arduino_JSON

#include "logging.h"
#include "credentials.h"
#include "stapi_settings.h"
#include "wifi.h"

void setup()
{
  startLogging();

  connect2Wifi(ssid, pass);
}

void runGET()
{
  WiFiClient client;
  HTTPClient http;

  Serial.print("HTTP GET ");
  Serial.println(base_url);

  http.begin(client, base_url);
  auto httpResponseCode = http.GET();
  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    String payload = http.getString();
    Serial.println(payload);
  } else {
    Serial.print("HTTP failed with code");
    Serial.println(httpResponseCode);
  }
  http.end();
}

void loop()
{
  runGET();

  delay(60000); // wait a minute
}
