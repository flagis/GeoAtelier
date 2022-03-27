# Read and Transmit to an OGC SensorThings API

## What & where OGC SensorThings API??

An implementation of the OGC SensorThings API spec is running on the cloud (a Synology NAS): Fraunhofer's FROST. We connect to it using HTTP (MQTT is also enabled, you can subscribe to all messages coming in)

```cpp
const char protocol[] = "http";
const char host[] = "aardvark.local";
const uint16_t port = 80;
const char path[] = "/v1.1";

auto domain = String(host) + ":" + port + "/FROST-Server";
auto base_url = String(protocol) + "://" + domain + path;
```

## Sending observations

### Observations & Measurements (O&M)

### The datastream, really tied the room together
The `Datastream` is where the `Thing`, `Sensor`, `ObservedProperty` are tied together. The `Datastream` is the (OData) base to create (POST) the `Observations`.

### The (minimum single) Observation:

```cpp
JSONVar observation;
observation["result"] = measureDistance();
```

### The HTTP POST code:

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
  Serial.print("HTTP Response code: ");
  Serial.println(httpResponseCode);
  if (httpResponseCode > 0) {
    String payload = http.getString();
    Serial.println(payload);
  }

  http.end();
}
```

