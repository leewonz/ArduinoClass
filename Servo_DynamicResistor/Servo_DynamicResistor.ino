#include <Servo.h>


Servo servo;

const int PIN_DYN = A0;
const int PIN_PWM = 3;

void setup() {
  // put your setup code here, to run once:
  servo.attach(PIN_PWM);
}

void loop() {
  int dynValue = analogRead(PIN_DYN);

  dynValue = map(dynValue, 0, 1023, 0, 180);
  
  servo.write(dynValue);

}
