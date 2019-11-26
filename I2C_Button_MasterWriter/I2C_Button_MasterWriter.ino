const int PIN_BTN = 4;
const int DEBOUNCE_DELAY = 10;
const float SEND_INTERVAL = 500;
int btnVal = 0;
int btnVal_last = 0;
int ledState = 0;

float lastSendTime = 0;

#include <Wire.h>

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  
  pinMode(PIN_BTN, INPUT); 

  btnVal_last = btnVal = digitalRead(PIN_BTN);

  Serial.begin(9600);
}

void loop() {

  // read button
  btnVal = digitalRead(PIN_BTN);

  // debounce
  if (btnVal != btnVal_last)
  {
    delay(DEBOUNCE_DELAY);
    btnVal_last = btnVal = digitalRead(PIN_BTN);

    // set led state
    if (btnVal == HIGH)
    {
      ledState = 1 - ledState;
    }
  }

  if (millis() > lastSendTime + SEND_INTERVAL)
  {
    lastSendTime = millis();

    Wire.beginTransmission(8); // transmit to device #8
    if (ledState == 0)
    {
      Wire.write("L");        // sends one byte
      Serial.write("L");
    }
    else if (ledState == 1)
    {
      Wire.write("H");        // sends one byte
      Serial.write("H");
    }
    Wire.endTransmission();    // stop transmitting
    
  }
}
