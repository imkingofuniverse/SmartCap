#include <SharpIR.h>
// Define model and input pin:
#define IRPin A6
#define model 20150
// Create variable to store the distance:
int distance_cm;
int vibrater1 = 3;
/* Model :
  GP2Y0A02YK0F --> 20150
  GP2Y0A21YK0F --> 1080
  GP2Y0A710K0F --> 100500
  GP2YA41SK0F --> 430
*/
// Create a new instance of the SharpIR class:
SharpIR mySensor = SharpIR(IRPin, model);
void setup() {
  // Begin serial communication at a baudrate of 9600:
  Serial.begin(9600);
  pinMode(vibrater1,OUTPUT);
}
void loop() {
  // Get a distance measurement and store it as distance_cm:
  distance_cm = mySensor.getDistance();
  // Print the measured distance to the serial monitor:
  Serial.print("distance ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  delay(100);
   if(distance_cm<100)
  {
  digitalWrite(vibrater1,HIGH);
  delay(1);
  }// wait for a second
  else
  {
  digitalWrite(vibrater1,LOW);
  delay(1000);
  }// wait for a second
}
