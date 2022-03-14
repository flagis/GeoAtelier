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

bool measure()
{
  return true;
}

void runInsert()
{
  WiFiClient client;
  HTTPClient http;

  http.begin(client, base_url);
  http.addHeader("Content-Type", "application/json");
  String httpRequestData = "{ TODO }";
  auto httpResponseCode = http.POST(httpRequestData);
  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    String payload = http.getString();
    Serial.println(payload);
  }

  http.end();
}

void loop()
{
  if (measure())
    runInsert();

  delay(60000); // wait a minute
}
