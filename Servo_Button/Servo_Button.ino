#include <Servo.h>


Servo servo;

float val = 0;

const float SPD = 1;
const int PIN_PWM = 3;
const int PIN_BTN1 = 4;
const int PIN_BTN2 = 5;

void setup() {
  // put your setup code here, to run once:
  servo.attach(PIN_PWM);
  pinMode(PIN_BTN1,INPUT);
  pinMode(PIN_BTN2,INPUT);
}

void loop() {
  if (digitalRead(PIN_BTN1) == HIGH)
  {
    val += SPD;
  }
  if (digitalRead(PIN_BTN2) == HIGH)
  {
    val -= SPD;
  }
  val = constrain(val, 0, 180);
  servo.write(val);

  delay(10);
}
