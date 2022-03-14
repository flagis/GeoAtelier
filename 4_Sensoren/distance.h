const uint8_t trigPin = 15;
const uint8_t echoPin = 13;

float distance = 0.0f;

void start() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void measure() {
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 

  auto duration = pulseIn(echoPin, HIGH); // duration in xxx
  distance = (duration / 2) / 29.1; // wat is dit magisch nummer?
}
