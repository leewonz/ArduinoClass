const int PIN_LED1 = 10;
const int PIN_LED2 = 11;
const int PIN_BTN1 = 5;
const int PIN_BTN2 = 6;
const int DEBOUNCE_DELAY = 10;
const float CHANGE_SPEED = 0.02;

int btn1Val = 0;
int btn1Val_last = 0;
int btn2Val = 0;
int btn2Val_last = 0;
float led1Val = 0;
float led2Val = 0;

void setup() {
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  pinMode(PIN_BTN1, INPUT); 
  pinMode(PIN_BTN2, INPUT); 

  btn1Val_last = btn1Val = digitalRead(PIN_BTN1);
  btn2Val_last = btn2Val = digitalRead(PIN_BTN2);
}

void loop() {

  // read button
  btn1Val = digitalRead(PIN_BTN1);

  // debounce
  if (btn1Val != btn1Val_last)
  {
    delay(DEBOUNCE_DELAY);
    btn1Val_last = btn1Val = digitalRead(PIN_BTN1);
  }

  // read button
  btn2Val = digitalRead(PIN_BTN2);

  // debounce
  if (btn2Val != btn2Val_last)
  {
    delay(DEBOUNCE_DELAY);
    btn2Val_last = btn2Val = digitalRead(PIN_BTN2);
  }
  
  // change led value
  if (btn1Val == 1 &&  btn2Val == 1)
  {
    led1Val -= CHANGE_SPEED;
    led2Val -= CHANGE_SPEED;
  }
  else if (btn1Val == 1)
  {
    led1Val += CHANGE_SPEED;
  }
  else if (btn2Val == 1)
  {
    led2Val += CHANGE_SPEED;
  }

  //clamp
  if (led1Val < 0)
  {led1Val = 0;}
  
  if (led2Val < 0)
  {led2Val = 0;}
  
  if (led1Val > 255)
  {led1Val = 255;}
  
  if (led2Val > 255)
  {led2Val = 255;}

  // write to led
  {
    analogWrite(PIN_LED1, (int)led1Val);
    analogWrite(PIN_LED2, (int)led2Val);
  }
}
