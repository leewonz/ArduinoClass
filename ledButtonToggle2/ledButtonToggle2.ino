const int PIN_LED1 = 10;
const int PIN_LED2 = 11;
const int PIN_BTN = 5;
const int DEBOUNCE_DELAY = 10;

int btnVal = 0;
int btnVal_last = 0;
int ledState = 0;

void setup() {
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
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
    digitalWrite(PIN_LED1, HIGH);
    digitalWrite(PIN_LED2, LOW);
  }
  else
  {
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, HIGH);
  }
}
