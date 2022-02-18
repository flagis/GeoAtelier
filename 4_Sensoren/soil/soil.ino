const int soil_in = 15;// D8 op de  wemos d1 mini v3

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
