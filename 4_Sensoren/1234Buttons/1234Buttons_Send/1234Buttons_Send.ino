const uint8_t button1 = D1;
const uint8_t button2 = D2;

bool button1state = false;
bool button2state = false;

void setup() {
  Serial.begin(115200);
  while (!Serial) {};

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

  button1state =  digitalRead(D1);
  button2state =  digitalRead(D2);
}

// the loop function runs over and over again forever
void loop() {
  auto currentButton1state = digitalRead(D1);
  auto currentButton2state = digitalRead(D2);

  if (currentButton1state != button1state) {
    button1state = currentButton1state;
    Serial.print("button1 ");
    Serial.println(button1state);
  }
  if (currentButton2state != button2state) {
    button2state = currentButton2state;
    Serial.print("button2 ");
    Serial.println(button2state);
  }
}
