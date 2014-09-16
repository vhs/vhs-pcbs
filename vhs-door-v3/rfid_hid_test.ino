// wiegand protocol reader for Arduino
//
// uses a timer to determine when all the bits have been read to allow
// for variable message length


#include "TimerOne.h"
#include "LiquidCrystal/LiquidCrystal.h"
#include "HardwareSerial.h"

// initialize the library with the numbers of the interface pins
static const unsigned char backlightPin = 4;
static const unsigned char beepPin  = 5;
static const unsigned char greenPin = 6;
static const unsigned char lcdpin_rs =  4;
static const unsigned char lcdpin_en =  8;
static const unsigned char lcdpin_d4 =  9;
static const unsigned char lcdpin_d5 = 10;
static const unsigned char lcdpin_d6 = 11;
static const unsigned char lcdpin_d7 = 12;

LiquidCrystal lcd(lcdpin_rs, lcdpin_en, lcdpin_d4, lcdpin_d5, lcdpin_d6, lcdpin_d7);

volatile unsigned char toggle = 0;

volatile unsigned long long value = 0;
volatile unsigned char newScan = 0;
volatile unsigned char bitCount = 0;
volatile unsigned char zeroCount = 0;
volatile unsigned char oneCount = 0;
volatile unsigned char lastBitCount = 0;
volatile unsigned char timerRunning = 0;

static const unsigned char beepPacing = 100;

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

static void zeroCallback()
{
    ++bitCount;
    ++zeroCount;
    value <<= 1;
}

static void oneCallback()
{
    ++bitCount;
    ++oneCount;
    value <<= 1;
    value |= 1;
}

static unsigned char ledbit = 0;

static void timerCallback()
{
    digitalWrite(led, ledbit);   // turn the LED on (HIGH is the voltage level)
    ledbit ^= 1;

    if (bitCount == lastBitCount)
    {
        bitCount = 0;
        newScan = 1;
    }
    else if (bitCount != 0)
    {
        // next timer interrupt we'll declare the code valid
        lastBitCount = bitCount;
    }
}

void playTune()
{
    digitalWrite(5, LOW);
    delay(beepPacing*2);
    digitalWrite(5, HIGH);
    delay(beepPacing*2);
    digitalWrite(5, LOW);
    delay(beepPacing);
    digitalWrite(5, HIGH);
    delay(beepPacing);
    digitalWrite(5, LOW);
    delay(beepPacing);
    digitalWrite(5, HIGH);
    delay(beepPacing);
    digitalWrite(5, LOW);
    delay(beepPacing);
    digitalWrite(5, HIGH);
    delay(beepPacing*2);
    digitalWrite(5, LOW);
    delay(beepPacing);
    digitalWrite(5, HIGH);
    delay(beepPacing*3);
    digitalWrite(5, LOW);
    delay(beepPacing);
    digitalWrite(5, HIGH);
    delay(beepPacing*3);
    digitalWrite(5, LOW);
    delay(beepPacing);
    digitalWrite(5, HIGH);
    delay(beepPacing);
}

void setup() 
{

    value = 0;
    toggle = 0;
    newScan = 0;
    bitCount = 0;
    lastBitCount = ~0;

    pinMode(led, OUTPUT);     

    Serial.begin(2400);
    Serial1.begin(2400);
  
    pinMode(greenPin, OUTPUT); 
    pinMode(beepPin, OUTPUT);
    pinMode(backlightPin, OUTPUT);
  
    digitalWrite(beepPin, HIGH); // active low, turn off
    digitalWrite(greenPin, HIGH); // active low, turn off
    Timer1.initialize(1000000);
    Timer1.attachInterrupt(timerCallback);

    attachInterrupt(0, oneCallback, RISING);
    attachInterrupt(4, zeroCallback, RISING);

    // set up the LCD's number of columns and rows: 
    lcd.begin(16, 2);
    lcd.print("Hi");
}

void loop() 
{
    if (newScan == 1)
    {
        Serial1.print("v");
        Serial1.print((unsigned long)(value >> 32), HEX);
        Serial1.println((unsigned long)value, HEX);
#if 0
        lcd.clear();
        lcd.print((unsigned long)(value >> 32), HEX);
        lcd.print((unsigned long)value, HEX);
#endif
        value = 0;
        newScan = 0;
        zeroCount = 0;
        oneCount = 0;
    }
   
    if (Serial1.available() > 0)
    {
        unsigned char command = Serial1.read();
        switch(command)
        {
            case 'b':
            {
                while (Serial1.available() == 0);
                unsigned char value = Serial1.read();
                digitalWrite(beepPin, value == '0' ? HIGH : LOW);
                break;
            }
            case 'c':
            {
                lcd.clear();
                break;
            }
            case 'd':
            case 'e':
            {
                unsigned char row = (command == 'e') 1 : 0;
                lcd.setCursor(0, row);
                while (true)
                {
                    while (Serial1.available() == 0);
                    unsigned char value = Serial1.read();
                    if (value == '\n' || value == '\r') break;
                    lcd.write(value);
                }
                break;
            }
            case 'g':
            {
                while (Serial1.available() == 0);
                unsigned char value = Serial1.read();
                digitalWrite(greenPin, value == '0' ? HIGH : LOW);
                break;
            }
            case 't':
            {
                playTune();
                break;
            }
        }
    }
}
