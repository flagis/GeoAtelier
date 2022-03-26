const uint32_t datastreamId = 13; //

void setupSensors() {

}

void loopSensors() {
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
  observation["FeatureOfInterest"] = featureOfInterest;

  observation["result"] = 12.3f;
  transmitValue(datastreamId, observation);

  delay(5000); // 10Hz
}
