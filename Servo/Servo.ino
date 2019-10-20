#include <Servo.h>


Servo servo;
int pos = 0;

const int PIN_CDS = A0;
const int PIN_PWM = 3;

void setup() {
  // put your setup code here, to run once:
  servo.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  for(pos = 0; pos < 180; pos++)
  {
    servo.write(pos);
    delay(15);  
  */

  for (pos = 0; pos <= 99999; pos++)
  {
    servo.write((sin(pos * 0.05)) * 90 + 90);
    delay(1);
  }
}
