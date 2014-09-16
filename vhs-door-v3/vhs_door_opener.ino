// VHS dopor opener
#include "HardwareSerial.h"

unsigned char disengagePin = 2;
unsigned char engagePin = 3;

void engage() 
{
  digitalWrite(engagePin, HIGH);
  delay(100);
  digitalWrite(engagePin, LOW);
}

void disengage() 
{
  digitalWrite(disengagePin, HIGH);
  delay(100);
  digitalWrite(disengagePin, LOW);
}

void enablecontrol()
{
  engage();
  delay(10000);
  disengage();
}


void setup() 
{
  Serial.begin(2400);
  
  pinMode(engagePin, OUTPUT);     
  pinMode(disengagePin, OUTPUT); 

  enablecontrol();  
}

void loop() 
{
   
    if (Serial.available() > 0)
    {
        unsigned char command = Serial.read();
        switch(command)
        {
            case 'e':
            {
                enablecontrol();
                break;
            }
        }
    }

}
