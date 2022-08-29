int distance;
  int trigpin1 = 4;
  int echopin1 = 2;
  int trigpin2 = 9;
  int echopin2 = 10;
  int vibrater1 = 3;
  int vibrater2 = 6;
  int vibrater3 = 8;
  int irpin = 0;
  int irval = 0;
  int led = 7;
  float duration;
  float cm;   
  void setup() {
  // initialize digital pin LED_BUILTIN as an output.
   Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(trigpin1, OUTPUT);
  pinMode(echopin1, INPUT);
  pinMode(trigpin2, OUTPUT);
  pinMode(echopin2, INPUT);
  pinMode(vibrater1,OUTPUT);
  pinMode(vibrater2,OUTPUT);
  pinMode(vibrater3,OUTPUT);
 }

// the loop function runs over and over again forever
void loop() 
  {
  digitalWrite(trigpin1,LOW);
  delay(2);
  digitalWrite(trigpin1,HIGH);
  delay(10);
  digitalWrite(trigpin1,LOW);
  duration=pulseIn(echopin1,HIGH);
  cm=(duration/58.82);
  distance=cm;
  Serial.print("Sonar1 Distance: ");
  Serial.print(distance);
  Serial.print(" - ");
  delay(100);
  if(distance<100)
  {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led,HIGH);
  digitalWrite(vibrater1,HIGH);
  delay(1);
  }// wait for a second
  else
  {
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(led,LOW);
  digitalWrite(vibrater1,LOW);
  delay(1000);
  }// wait for a second
 
  digitalWrite(trigpin2,LOW);
  delay(2);
  digitalWrite(trigpin2,HIGH);
  delay(10);
  digitalWrite(trigpin2,LOW);
  duration=pulseIn(echopin2,HIGH);
  cm=(duration/58.82);
  distance=cm;
  Serial.print("Sonar2 Distance: ");
  Serial.print(distance);
  Serial.print(" - ");
  delay(100);
  if(distance<100)
  {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led,HIGH);
  digitalWrite(vibrater2,HIGH);
  delay(1);
  }
  else
  {
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(led,LOW);
  digitalWrite(vibrater2,LOW);
  delay(1000);
  }

  irval = analogRead(irpin);       // reads the value of the sharp sensor
  Serial.print("IR State: ");
  delay(1);

  if(irval<100)
  {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led,HIGH);
  digitalWrite(vibrater3,HIGH);
  Serial.println(" 0 ");            // prints the value of the sensor to the serial monitor
  delay(100);                    // wait for this much time before printing next value
  
  }
  else
  {
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(led,LOW);
  digitalWrite(vibrater3,LOW);
  Serial.println(" 1 "); 
  delay(1000);
  }
  }
