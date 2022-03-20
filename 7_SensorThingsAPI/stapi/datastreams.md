# Datastreams

Participants choose their sensor. When seated again at the table, note the Thing @iot.id below.

Once the sensor is coupled with the thing, the datastream can be created.
The sensor `@iot.id` is encoded, on a white sticker, in blue (left), the ObserverProperty `@iot.id` in pencil (dark grey, right angled)

After the Datastreams have been created, note the `@iot.id` in the tables below. (The Datastream `@iot.id` needs to be used when posting observations!)

POST:
`http://<host>/FROST-Server/v1.0/Things(x)/Datastreams`

## Taiwan Alpha Flex Sensor - 60mm

| **Thing** `@iot.id` | **Datastream** `@iot.id`
|-|-
|.|.
|.|.

```javascript
{
  "name": "AngleRange DS",
  "description": "Datastream for recording AngleRange",
  "observationType": "http://www.opengis.net/def/observationType/OGC-OM/2.0/OM_Measurement",
  "unitOfMeasurement": {
    "name": "degrees",
    "symbol": "deg",
    "definition": "http://www.qudt.org/qudt/owl/1.0.0/unit/Instances.html#DegreeAngle"
  },
  "ObservedProperty":{"@iot.id": 29},
  "Sensor":{"@iot.id": 38}
}
```
## HX711 weight scale
| **Thing** `@iot.id` | **Datastream** `@iot.id`
|-|-
|.|.
|.|.
```javascript
{
  "name": "Weight DS",
  "description": "Datastream for recording Weight",
  "observationType": "http://www.opengis.net/def/observationType/OGC-OM/2.0/OM_Measurement",
  "unitOfMeasurement": {
    "name": "kilograms",
    "symbol": "kg",
    "definition": "http://www.qudt.org/qudt/owl/1.0.0/unit/Instances.html#Kilogram"
  },
  "ObservedProperty":{"@iot.id": 30},
  "Sensor":{"@iot.id": 39}
}
```
## HMC5883L 3-Axis Kompas Magnetometer Sensor Module 3V-5V V2
| **Thing** `@iot.id` | **Datastream** `@iot.id`
|-|-
|.|.
|.|.
```javascript
{
  "name": "Magnetic fields DS",
  "description": "Datastream for recording magnetic fields",
  "observationType": "http://www.opengis.net/def/observationType/OGC-OM/2.0/OM_Measurement",
  "unitOfMeasurement": {
    "name": "Ampere per Meter",
    "symbol": "A/m",
    "definition": "http://www.qudt.org/qudt/owl/1.0.0/unit/Instances.html#AmperePerMeter"
  },
  "ObservedProperty":{"@iot.id": 31},
  "Sensor":{"@iot.id": 40}
}
```
## BMP180 Digitale Barometer Druk Sensor Module
| **Thing** `@iot.id` | **Datastream** `@iot.id`
|-|-
|.|.
|.|.
```javascript
{
  "name": "Barometric Pressure DS",
  "description": "Datastream for recording barometric pressure",
  "observationType": "http://www.opengis.net/def/observationType/OGC-OM/2.0/OM_Measurement",
  "unitOfMeasurement": {
    "name": "KiloPascal",
    "symbol": "KPa",
    "definition": "http://www.qudt.org/qudt/owl/1.0.0/unit/Instances.html#KiloPascal"
  },
  "ObservedProperty":{"@iot.id": 32},
  "Sensor":{"@iot.id": 41}
}
```
## AM2320 Thermometer Temperatuur en Vochtigheids Sensor
| **Thing** `@iot.id` | **Datastream** `@iot.id`
|-|-
|.|.
|.|.

Note: The AM2320 has 2 sensors embedded and will have 2 Datastreams!

```javascript
{
  "name": "Temperature DS",
  "description": "Datastream for recording Temperature",
  "observationType": "http://www.opengis.net/def/observationType/OGC-OM/2.0/OM_Measurement",
  "unitOfMeasurement": {
    "name": "Degree Centigrade",
    "symbol": "DegC",
    "definition": "http://www.qudt.org/qudt/owl/1.0.0/unit/Instances.html#DegreeCentigrade"
  },
  "ObservedProperty":{"@iot.id": 33},
  "Sensor":{"@iot.id": 42}
}
```
```javascript
{
  "name": "Humidity DS",
  "description": "Datastream for recording Humidity",
  "observationType": "http://www.opengis.net/def/observationType/OGC-OM/2.0/OM_Measurement",
  "unitOfMeasurement": {
    "name": "xxx DS",
    "symbol": "xxx",
    "definition": "http://www.qudt.org/qudt/owl/1.0.0/quantity/Instances.html#AbsoluteHumidity"
  },
  "ObservedProperty":{"@iot.id": 34},
  "Sensor":{"@iot.id": 42}
}
```
## ASAIR AGS02MA TVOC Gassensor
| **Thing** `@iot.id` | **Datastream** `@iot.id`
|-|-
|.|.
|.|.
```javascript
{
  "name": "TVOC DS",
  "description": "Datastream for recording TVOC",
  "observationType": "http://www.opengis.net/def/observationType/OGC-OM/2.0/OM_Measurement",
  "unitOfMeasurement": {
    "name": "Total Volatile Organic Compounds",
    "symbol": "xxx",
    "definition": "xxxx"
  },
  "ObservedProperty":{"@iot.id": 35},
  "Sensor":{"@iot.id": 43}
}
```
## ADXL345 Digitale 3-axis Accelerometer Module V2
| **Thing** `@iot.id` | **Datastream** `@iot.id`
|-|-
|.|.
|.|.
```javascript
{
  "name": "Acceleration DS",
  "description": "Datastream for recording acceleration",
  "observationType": "http://www.opengis.net/def/observationType/OGC-OM/2.0/OM_Measurement",
  "unitOfMeasurement": {
    "name": "Meter per second squared",
    "symbol": "m/s^2",
    "definition": "http://www.qudt.org/qudt/owl/1.0.0/unit/Instances.html#MeterPerSecondSquared"
  },
  "ObservedProperty":{"@iot.id": 36},
  "Sensor":{"@iot.id": 44}
}
```
## MAX4466 Microfoon Versterker Module met Microfoon
| **Thing** `@iot.id` | **Datastream** `@iot.id`
|-|-
|.|.
|.|.
```javascript
{
  "name": "SignalStrength DS",
  "description": "Datastream for recording SignalStrength",
  "observationType": "http://www.opengis.net/def/observationType/OGC-OM/2.0/OM_Measurement",
  "unitOfMeasurement": {
    "name": "dB-millivolts per metre",
    "symbol": "dBmV/m",
    "definition": "http://www.qudt.org/qudt/owl/1.0.0/quantity/Instances.html#SignalStrength"
  },
  "ObservedProperty":{"@iot.id": 37},
  "Sensor":{"@iot.id": 45}
}
```
## Touch Module TTP224 4-kanaals
| **Thing** `@iot.id` | **Datastream** `@iot.id`
|-|-
|.|.
|.|.
```javascript
{
  "name": "State DS",
  "description": "Datastream for recording State",
  "observationType": "http://www.opengis.net/def/observationType/OGC-OM/2.0/OM_Measurement",
  "unitOfMeasurement": {
    "name": "onOff",
    "symbol": "xxx",
    "definition": "xxxx"
  },
  "ObservedProperty":{"@iot.id": 38},
  "Sensor":{"@iot.id": 46}
}
```
## RCWL-1601 Ultrasonische Sensor
| **Thing** `@iot.id` | **Datastream** `@iot.id`
|-|-
|.|.
|.|.
```javascript
{
  "name": "Distance DS",
  "description": "Datastream for recording Distance",
  "observationType": "http://www.opengis.net/def/observationType/OGC-OM/2.0/OM_Measurement",
  "unitOfMeasurement": {
    "name": "Centimeter",
    "symbol": "cm",
    "definition": "http://www.qudt.org/qudt/owl/1.0.0/unit/Instances.html#Centimeter"
  },
  "ObservedProperty":{"@iot.id": 39},
  "Sensor":{"@iot.id": 47}
}
```
