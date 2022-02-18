const int soil_in = D8;

void setup()
{
  Serial.begin(115200);
  while (!Serial) {}
  delay(1000);

  pinMode(soil_in, INPUT);
}

void loop()
{
  if (digitalRead(soil_in) == false)
  {
    Serial.println("plant needs watering ");
  }
}
