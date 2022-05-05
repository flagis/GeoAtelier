#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

const uint32_t datastreamId = xxx; //

void setupSensors() {
  accel.begin();

  /* Set the range to whatever is appropriate for your project */
  accel.setRange(ADXL345_RANGE_16_G);
  // accel.setRange(ADXL345_RANGE_8_G);
  // accel.setRange(ADXL345_RANGE_4_G);
  //accel.setRange(ADXL345_RANGE_2_G);
}

void loopSensors()
{
  /*
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
  */
  JSONVar observation;
  //  observation["FeatureOfInterest"] = featureOfInterest;
  //  observation["phenomenonTime"] = getISO8601dateTime();

  sensors_event_t event;
  accel.getEvent(&event);

  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  "); Serial.println("m/s^2 ");

  //  observation["result"] = measureTemperature();
  transmitValue(datastreamId, event.acceleration.x);

  delay(100); // 10Hz
}
