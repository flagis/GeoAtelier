#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Arduino_JSON.h> // from https://github.com/arduino-libraries/Arduino_JSON

#include "logging.h"
#include "credentials.h"
#include "settings.h"
#include "wifi.h"

void setup()
{
  startLogging();

  connect2Wifi(ssid, pass);
}

void runInsert()
{
  WiFiClient client;
  HTTPClient http;

  http.begin(client, "http://stapi.snuffeldb.synology.me/FROST-Server/v1.0");
  http.addHeader("Content-Type", "application/json");
  String httpRequestData = "{}";
  auto httpResponseCode = http.POST();
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
  runInsert();

  delay(60000); // wait a minute
}
