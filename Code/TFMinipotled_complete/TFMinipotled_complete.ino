#include <SoftwareSerial.h>

//Green=Tx . White=Rx
#include "TFMini.h"
TFMini tfmini;
 
SoftwareSerial SerialTFMini(2, 3);          //The only value that matters here is the first one, 2, Rx
 
void getTFminiData(int* distance, int* strength)
{
  static char i = 0;
  char j = 0;
  int checksum = 0;
  static int rx[9];
  if (SerialTFMini.available())
  {
    rx[i] = SerialTFMini.read();
    if (rx[0] != 0x59)
    {
      i = 0;
    }
    else if (i == 1 && rx[1] != 0x59)
    {
      i = 0;
    }
    else if (i == 8)
    {
      for (j = 0; j < 8; j++)
      {
        checksum += rx[j];
      }
      if (rx[8] == (checksum % 256))
      {
        *distance = rx[2] + rx[3] * 256;
        *strength = rx[4] + rx[5] * 256;
      }
      i = 0;
    }
    else
    {
      i++;
    }
  }
}
 
int in = 13;
int inp = 10;
int vib = 12;
int led = 5;
int gd = 8;
int gdn= 11;

void setup()
{
  Serial.begin(115200);       //Initialize hardware serial port (serial debug port)
  while (!Serial);            // wait for serial port to connect. Needed for native USB port only
  Serial.println ("Initializing...");
  SerialTFMini.begin(TFMINI_BAUDRATE);    //Initialize the data rate for the SoftwareSerial port
  tfmini.begin(&SerialTFMini);            //Initialize the TF Mini sensor
  pinMode(in, OUTPUT);
  pinMode(inp, OUTPUT);
  pinMode(vib, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(gd, OUTPUT);
  pinMode(gdn, OUTPUT);
}
 
void loop()
{
  digitalWrite(in, HIGH);
  digitalWrite(inp, HIGH);
  digitalWrite(gd, LOW);
  digitalWrite(gdn, LOW);
  int distance = 0;
  int strength = 0;
  int pot = analogRead(A0);
  int dist;
  Serial.println(dist);
 
  getTFminiData(&distance, &strength);
  while (!distance)
  {
    getTFminiData(&distance, &strength);
    if (distance)
    {
      Serial.print(distance);
      Serial.print("cm\t");
      Serial.print("strength: ");
      Serial.println(strength);
    }
  }

  if(pot<=350)
  {
    dist=150;
  }
  else if(350<pot<=700)
  {
    dist=200;
  }
  else if(700<pot)
  {
    dist=300;
  }
  
  if(distance<dist)
  {
    digitalWrite(vib, HIGH);
    digitalWrite(led, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(5);
  }
  else
  {
    digitalWrite(vib, LOW);
    digitalWrite(led, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    delay(5);
  }
  
  delay(100);
}
