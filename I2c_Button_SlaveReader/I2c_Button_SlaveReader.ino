int PIN_BTN = 2;

#include <Wire.h>

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output

  pinMode(PIN_BTN, OUTPUT);
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  /*n
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
  */
  char c = Wire.read(); 
  Serial.print(c);
  if (c == 'H')
  {
    Serial.print("1");
    digitalWrite(PIN_BTN, HIGH);
  }
  else if (c == 'L')
  {
    Serial.print("0");
    digitalWrite(PIN_BTN, LOW);
  }
}
