  float distance;
  int trigpin1 = 3;
  int echopin1 = 2;
  int vibrater = 4;
  float duration;
  float cm;   
  void setup() {
  // initialize digital pin LED_BUILTIN as an output.
   Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(vibrater, OUTPUT);
  pinMode(trigpin1, OUTPUT);
  pinMode(echopin1, INPUT);
 }

// the loop function runs over and over again forever
void loop() 
  {
  digitalWrite(trigpin1,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin1,LOW);
  duration=pulseIn(echopin1,HIGH);
  Serial.print(duration);
  cm=(duration/58.82);
  distance=cm;
  Serial.print("Sonar1 Distance: ");
  Serial.print(distance);
  Serial.println(" - ");
  delayMicroseconds(100);

  if(distance<100)
  {
  digitalWrite(vibrater,HIGH);
  delay(1);
  }// wait for a second
  else
  {
  digitalWrite(vibrater,LOW);
  delay(1000);
  }
  
  }
