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
  int cdsValue = analogRead(PIN_CDS);

  cdsValue = map(cdsValue, 0, 1023, 0, 180);
  
  servo.write(cdsValue);

}
