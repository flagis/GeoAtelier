# Communication
In this GeoAtelier, focussed around IoT (Internet of Things), we use the internet to connect the thing with the service. The Wemos has *WiFi* build in and we'll use that. 

Other communication protocols are also available (not on-board the Wemos by default):

* Zigbee
* LoRa
* 2G/4G/LTE/5G
* BLE
* NB-IoT
* Sigfox

## WiFi connection

An WiFi WPA2 is available in the room, with SSID `FLAGIS`

(ssid and pass are set in the `utils/credentials.h` file)

```cpp
#include <ESP8266WiFi.h>

#include "utils/credentials.h"

...

void setup() {
  ...
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  ...
}
```

## What time is it?

Use the ESP8266 onboard date/time module to get the internet time using the NTP protocol.

`pool.ntp.org` will be used by NTP to help us get the time

```cpp
  configTime(0, 0, "pool.ntp.org"); // get time in zulu
```

`utils/dateTime.h` is a wrapper around the code that will give us an ISO8601 dateTime.

`getISO8601dateTime()` returns an ISO8601 compliant datetime.

```cpp
  Serial.println(getISO8601dateTime());
```

returns: `2022-03-19T14:36:46.123Z`