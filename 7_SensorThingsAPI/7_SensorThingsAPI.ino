#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Arduino_JSON.h> // from https://github.com/arduino-libraries/Arduino_JSON
#include <NTPClient.h>

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
  //  setupSensor();

  connect2Wifi(ssid, pass);
}

void transmitValue(int datastreamId, JSONVar observation)
{
  WiFiClient client;
  HTTPClient http;

  String httpRequestData = JSON.stringify(observation);

  http.begin(client, base_url + "/Datastream(" + datastreamId + ")/Observations");
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
  //  loopSensor();
  //  loopGPS();

  JSONVar point;
  point["type"] = "Point";
  JSONVar coordinates;
  coordinates[0] = 1; // TODO from GPS
  coordinates[1] = 2; // TODO from GPS
  point["coordinates"] = coordinates;

  JSONVar featureOfInterest;
  featureOfInterest["name"] = ""; // TODO
  featureOfInterest["description"] = ""; // TODO
  featureOfInterest["encodingType"] = "application/vnd.geo+json";
  featureOfInterest["feature"] = point;

  JSONVar observation;
  observation["phenomenonTime"] = "2017-02-07T18:02:00.000Z"; // TODO, from Wifi
  observation["result"] = 3.14f;
  observation["FeatureOfInterest"] = featureOfInterest;

  transmitValue(1, observation);
}
