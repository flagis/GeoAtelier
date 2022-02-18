#define trigPin 15
#define echoPin 13

void setup() {
  Serial.begin(115200);
  while (!Serial){}
  delay(1000);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 

  auto duration = pulseIn(echoPin, HIGH); // duration in xxx
  auto distance = (duration / 2) / 29.1; // wat is dit magisch nummer?
  Serial.println(distance);
}
