#include <AM232X.h> // https://github.com/RobTillaart/AM232X

AM232X AM2320;

void setup()
{
  Serial.begin(115200);
  while (!Serial) {};

  AM2320.begin();
  AM2320.wakeUp();
  delay(2000);

  Serial.println("\nHumidity (%),\tTemperature (C)");
}

void loop()
{
  if (AM232X_OK == AM2320.read())
  {
    Serial.print(AM2320.getHumidity(), 1);
    Serial.print(",\t\t");
    Serial.println(AM2320.getTemperature(), 1);
  }
  else
    Serial.println(".");

  delay(2000);
}
