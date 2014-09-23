// VHS door opener
#include "HardwareSerial.h"

unsigned char disengagePin = 3;
unsigned char engagePin = 2;


char inData[20]; // Allocate some space for the string
char inChar=-1; // Where to store the character read
byte index = 0; // Index into array; where to store the character

#define BUFF_SIZE 6

#define DEBUG 1

void engage() {
  if( DEBUG ) Serial1.println( "Engage..." );
  digitalWrite(engagePin, HIGH);
  delay(100);
  digitalWrite(engagePin, LOW);
}

void disengage() {
  if( DEBUG ) Serial1.println( "Disengage..." );
  digitalWrite(disengagePin, HIGH);
  delay(100);
  digitalWrite(disengagePin, LOW);
}

void enablecontrol() {
  if( DEBUG ) Serial1.println( "Enable control..." );
  engage();
  delay(10000);
  disengage();
  Serial1.println( "opened" );
}

int counter = 0;

void setup() {
//  Serial1.begin(2400);
  Serial1.begin( 2400 );

  if( DEBUG ) Serial1.println( "Initializing pins..." );
  pinMode( engagePin, OUTPUT );     
  pinMode( disengagePin, OUTPUT ); 

  if( DEBUG ) Serial1.println( "Bringing up lock..." );
  //enablecontrol();
  
  Serial1.println( "ONLINE" );
}

int readNb(char *buffer, int length, int timeout)
{
    long         previousMillis = 0;
    int          bread          = 0;
    char         c;
    
    previousMillis = millis();
    while((millis()-previousMillis)<timeout)
    {
        if(Serial1.available()>0)
        {
            c             = Serial1.read();
            if(bread>length)
            {
                return(-1); // string received is too long
            }
            else
            {
                buffer[bread]=c;
            }
            bread++;
        }
    }
    return(bread);
}


void loop() {


  if (Serial1.available() > 0) {
    char c = Serial1.read();
        Serial1.write(c);
    if(c == '*') {
      Serial1.write("Ctrl Char");
      if(readNb(inData, 6, 1000) == -1) {
        Serial1.write("Too long");
      } else {
        Serial1.write("Next");
        if(strcmp(inData,"sesame")  == 0){
          Serial1.write("Open!");
          enablecontrol();
        } else {
          Serial1.write("Not Open!");
          Serial1.write(inData);
        }
      }
    }
  }
    for(int i=0;i<7;i++){
      inData[i]=0;
    }
        
}
