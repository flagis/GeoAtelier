# Read and Transmit to an OGC SensorThings API

## What & where OGC SensorThings API??

An implementation of the OGC SensorThings API spec is running on the Synology NAS: Fraunhofer's FROST. We connect to it using HTTP (MQTT is also enabled, but is not used here today)

```cpp
const char protocol[] = "http";
const char host[] = "192.168.0.105";
const uint16_t port = 49154;
const char path[] = "/v1.1";

auto domain = String(host) + ":" + port + "/FROST-Server";
auto base_url = String(protocol) + "://" + domain + path;
```

## Sending observations

### Observations & Measurements (O&M)

### The datastream, really tied the room together
The datastream is where this Thing, Sensor, ObservedProperty and Observation are tied together. The Datastream is the (OData) base to create (POST) the Observation.

### The code:

```cpp
void transmitValue(const int datastreamId, const JSONVar& observation)
{
  String url = base_url + "/Datastream(" + datastreamId + ")/Observations";
  Serial.println(url);
 
  String httpRequestData = JSON.stringify(observation);
  Serial.println(httpRequestData);

  WiFiClient client;
  HTTPClient http;
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
}
```

