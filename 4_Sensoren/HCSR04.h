// zie: https://create.arduino.cc/projecthub/abdularbi17/ultrasonic-sensor-hc-sr04-with-arduino-tutorial-327ff6

const uint8_t trigPin = 15; // digital ??
const uint8_t echoPin = 13; // digital ??

float distance = 0.0f;

void setupSensor() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loopSensor() {
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 

  auto duration = pulseIn(echoPin, HIGH); // duration in xxx
  distance = (duration / 2) / 29.1; // wat is dit magisch nummer?
}
