# ObservedProperties

POST:
`http://<host>/FROST-Server/v1.0/ObservedProperties`

## Bending Sensor

![MB060](res/MB060.png)

```javascript
{
  "name": "AngleRange",
  "description": "Bending movements between 0 and 180 degrees",
  "definition": "https://en.wikipedia.org/wiki/Bending"
}
```

## Weighing Scale 
![HX711](res/HX711.png)

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

### ObservedProperty:
```javascript
{
  "name": "Distance",
  "description": "Distance is a numerical measurement of how far apart objects or points are",
  "definition": "https://en.wikipedia.org/wiki/Distance"
}
```
