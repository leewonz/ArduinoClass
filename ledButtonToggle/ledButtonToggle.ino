const int PIN_LED = 12;
const int PIN_BTN = 4;
const int DEBOUNCE_DELAY = 10;
int btnVal = 0;
int btnVal_last = 0;
int ledState = 0;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BTN, INPUT); 

  btnVal_last = btnVal = digitalRead(PIN_BTN);
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
  
  // write to led
  if (ledState == 1)
  {
    digitalWrite(PIN_LED, HIGH);
  }
  else
  {
    digitalWrite(PIN_LED, LOW);
  }
}
