#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Arduino_JSON.h> // from https://github.com/arduino-libraries/Arduino_JSON

//#include "ADXL345.h"
//#include "BMP085.h"
//#include "BMP180.h"
//#include "buttons.h"
//#include "HMC5883.h"
//#include "HX711.h"
//#include "HCSR04.h"

#include "logging.h"
#include "credentials.h"
#include "stapi_settings.h"
#include "wifi.h"

void setup()
{
  setupLogging();
 // setupSensor();

  connect2Wifi(ssid, pass);
}

void runInsert()
{
  WiFiClient client;
  HTTPClient http;

  JSONVar myObject;
  myObject["phenomenonTime"] = "2017-02-07T18:02:00.000Z";
  myObject["result"] = 48.756080;
  String httpRequestData = JSON.stringify(myObject);

  http.begin(client, base_url + "/Datastream(" + "1" + ")/Observations");
  http.addHeader("Content-Type", "application/json");
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
 // loopSensor();
  runInsert();
}
