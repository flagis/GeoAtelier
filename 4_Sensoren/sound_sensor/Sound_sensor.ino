const int sound_in = D8;// D8 op de  wemos d1 mini v3
int trigger = 0;// interupt is niet getriggerd(standaard waarde)

void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  delay(1000);

  Serial.println("started");
  pinMode(sound_in, INPUT);
  // functie die zegt welke pin de interupt geld, welke functie er uitgevoerd moet worden en wanneer het moet triggeren
  attachInterrupt(digitalPinToInterrupt(sound_in), sound_triggerd, FALLING);
}

void loop()
{
  if (trigger == 1)
  {
    Serial.println("The button is Pressed");
    delay (5000);
    trigger = 0;
    // functie die zegt welke pin de interupt geld, welke functie er uitgevoerd moet worden en wanneer het moet triggeren
    attachInterrupt(digitalPinToInterrupt(sound_in), sound_triggerd, FALLING);
  }
}

// functie die getriggerd wordt door de interupt
IRAM_ATTR void sound_triggerd()
{
  detachInterrupt(sound_in);
  trigger = 1;
}
