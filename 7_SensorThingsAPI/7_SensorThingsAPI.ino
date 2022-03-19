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
#include "dateTime.h"
#include "gps.h"

void setup()
{
  setupLogging();
  //  setupSensor();
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
  //  loopSensor();
  loopGPS();

  JSONVar point;
  point["type"] = "Point";
  JSONVar coordinates;
  coordinates[0] = lat;
  coordinates[1] = lng;
  point["coordinates"] = coordinates;

  JSONVar featureOfInterest;
  featureOfInterest["name"] = "hier"; // TODO
  featureOfInterest["description"] = "iets meer naar ginder"; // TODO
  featureOfInterest["encodingType"] = "application/vnd.geo+json";
  featureOfInterest["feature"] = point;

  JSONVar observation;
  observation["phenomenonTime"] = getISO8601dateTime();
  observation["result"] = 3.14f;
  observation["FeatureOfInterest"] = featureOfInterest;

  transmitValue(1, observation);
}
