//******************************************************************************* 
// Project : 74hc595 LCD in Learing Kit 
// Board : Arduino Uno  
// By : Kit Plus 
//******************************************************************************* 
  
int latchPin = 11;    //Pin connected to ST_CP of 74HC595 
int clockPin = 8;   //Pin connected to SH_CP of 74HC595 
int dataPin = 12;    //Pin connected to DS of 74HC595 
  
byte leds = 0; 
  
void setup() { 
  pinMode(latchPin, OUTPUT); 
  pinMode(dataPin, OUTPUT);   
  pinMode(clockPin, OUTPUT); 
} 
  
void loop() { 
  leds = 0; 
  updateShiftRegister(); 
  delay(500); 
  for (int i = 0; i < 8; i++)  { 
    bitSet(leds, i); 
    updateShiftRegister(); 
    delay(100); 
 
  } 
} 
  
void updateShiftRegister() { 
   digitalWrite(latchPin, LOW); 
   shiftOut(dataPin, clockPin, LSBFIRST, leds); 
   digitalWrite(latchPin, HIGH); 
} 
