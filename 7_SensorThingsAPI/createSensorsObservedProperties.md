# Sensors & ObservedProperties

## Bending Sensor

![MB060](res/MB060.png)

### Sensor:
```javascript
{
  "name": "MB060",
  "description": "The Flex sensor can be used to measure bending movements",
  "encodingType": "application/pdf",
  "metadata": "http://www.taiwanalpha.com/downloads?target=products&id=22"
}
```

### ObservedProperty:
```javascript
{
  "name": "AngleRange",
  "description": "Bending movements between 0 and 180 degrees",
  "definition": "https://en.wikipedia.org/wiki/Bending"
}
```

## Weighing Scale 
![HX711](res/HX711.png)
### Sensor:
```javascript
{
  "name": "HX711",
  "description": "Read load cells to measure weight",
  "encodingType": "application/pdf",
  "metadata": "https://cdn.sparkfun.com/assets/b/f/5/a/e/hx711F_EN.pdf"
}
```

### ObservedProperty:
```javascript
{
  "name": "Weight",
  "description": "The force with which a body is attracted toward an astronomical body",
  "definition": "http://www.qudt.org/qudt/owl/1.0.0/quantity/Instances.html#Weight"
}
```

## Axis Compass Magnetometer  
![hmc5883](res/hmc5883.png)
### Sensor:
```javascript
{
  "name": "HMC5883",
  "description": "Compassing and magnetometry",
  "encodingType": "application/pdf",
  "metadata": "https://www.farnell.com/datasheets/1683374.pdf"
}
```

### ObservedProperty:
```javascript
{
  "name": "Magnetic fields",
  "description": "Direction and the magnitude of Earth’s magnetic fields",
  "definition": "http://www.qudt.org/qudt/owl/1.0.0/quantity/Instances.html#MagneticField"
}
```

## Digital Barometer  
![bmp180](res/bmp180.png)
### Sensor:
```javascript
{
  "name": "BMP180",
  "description": "Barometric Pressure/Temperature/Altitude Sensor",
  "encodingType": "application/pdf",
  "metadata": "https://www.tinytronics.nl/shop/nl/sensoren/lucht/druk/bmp180-digitale-barometer-druk-sensor-module"
}
```

### ObservedProperties:
```javascript
{
  "name": "Barometric Pressure",
  "description": "The pressure exerted at a point due to the presence of an atmosphere",
  "definition": "http://www.qudt.org/qudt/owl/1.0.0/quantity/Instances.html#AtmosphericPressure"
}
```

```javascript
{
  "name": "Temperature",
  "description": "Temperature is a physical quantity that expresses the degree of hotness or coldness of a substance",
  "definition": "http://www.qudt.org/qudt/owl/1.0.0/quantity/Instances.html#ThermodynamicTemperature"
}
```

## Temperature and Humidity  
![am2320](res/am2320.png)
### Sensor:
```javascript
{
  "name": "AM2320",
  "description": "Digital Temperature and Humidity Sensor",
  "encodingType": "application/pdf",
  "metadata": "https://www.adafruit.com/product/3721"
}
```

### ObservedProperty:
```javascript
{
  "name": "Humidity",
  "description": "Absolute humidity is the mass of water in a particular volume of air. It is a measure of the density of water vapor in an atmosphere",
  "definition": "http://www.qudt.org/qudt/owl/1.0.0/quantity/Instances.html#AbsoluteHumidity"
}
```
```javascript
{
  "name": "Temperature",
  "description": "Temperature is a physical quantity that expresses the degree of hotness or coldness of a substance",
  "definition": "http://www.qudt.org/qudt/owl/1.0.0/quantity/Instances.html#ThermodynamicTemperature"
}
```
## Gas Sensor 
![ags02ma](res/ags02ma.png)
### Sensor:
```javascript
{
  "name": "AGS02MA",
  "description": "Gas Sensor",
  "encodingType": "application/pdf",
  "metadata": "https://www.tinytronics.nl/shop/en/sensors/air/gas/asair-ags02ma-tvoc-gas-sensor"
}
```

### ObservedProperty:
```javascript
{
  "name": "TVOC",
  "description": "Total Volatile Organic Compounds",
  "definition": "https://en.wikipedia.org/wiki/Volatile_organic_compound"
}
```

## Accelerometer  
![adxl345](res/adxl345.png)
### Sensor:
```javascript
{
  "name": "ADXL345",
  "description": "3-axis accelerometer",
  "encodingType": "application/pdf",
  "metadata": "https://www.analog.com/media/en/technical-documentation/data-sheets/ADXL345.pdf"
}
```

### ObservedProperty:
```javascript
{
  "name": "Acceleration",
  "description": "Acceleration is the (instantaneous) rate of change of velocity",
  "definition": "http://www.qudt.org/qudt/owl/1.0.0/quantity/Instances.html#Acceleration"
}
```

## xxxx 
![MAX4466](res/MAX4466.png)
### Sensor:
```javascript
{
  "name": "MAX4466",
  "description": "Microphone Amplifier Module",
  "encodingType": "application/pdf",
  "metadata": "https://www.farnell.com/datasheets/1815587.pdf"
}
```

### ObservedProperty:
```javascript
{
  "name": "SignalStrength",
  "description": "vibration of air molecules",
  "definition": "http://www.qudt.org/qudt/owl/1.0.0/quantity/Instances.html#SignalStrength"
}
```

## Touch Module
![TTP224](res/TTP224.png)
### Sensor:
```javascript
{
  "name": "Touch Module",
  "description": "4 capacitive type jog mode touch switch module",
  "encodingType": "application/pdf",
  "metadata": "https://www.instructables.com/TTP224-Module-Options/"
}
```

### ObservedProperty:
```javascript
{
  "name": "State",
  "description": "State up or down",
  "definition": "n/a"
}
```

## RCWL1601 
![RCWL1601](res/RCWL1601.png)
### Sensor:
```javascript
{
  "name": "RCWL1601",
  "description": "Ultrasonic Distance Sensor",
  "encodingType": "application/pdf",
  "metadata": "https://media.digikey.com/pdf/Data%20Sheets/Adafruit%20PDFs/4007_Web.pdf"
}
```

### ObservedProperty:
```javascript
{
  "name": "Distance",
  "description": "Distance is a numerical measurement of how far apart objects or points are",
  "definition": "https://en.wikipedia.org/wiki/Distance"
}
```
