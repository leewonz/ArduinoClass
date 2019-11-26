#define MAXSPEED 500
#define ACCDEACC 1600

int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;

long counter = 0;

int steps = 0;

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void SetPins(bool p1, bool p2, bool p3, bool p4)
{
  if (p1) {digitalWrite(IN1, HIGH);}
  else {digitalWrite(IN1, LOW);}
  if (p2) {digitalWrite(IN2, HIGH);}
  else {digitalWrite(IN2, LOW);}
  if (p3) {digitalWrite(IN3, HIGH);}
  else {digitalWrite(IN3, LOW);}
  if (p4) {digitalWrite(IN4, HIGH);}
  else {digitalWrite(IN4, LOW);}
}

void runMotor(int dir, int interval, int durationMilli)
{
  int durationMicro = 0;
  while(durationMilli >= 0)
  {
    steps += dir;
    
    if (steps > 7)
    {
      steps -= 8;
    }
    if (steps < 0)
    {
      steps += 8;
    }

    //steps %= 8;
    
    durationMicro -= interval;
    while (durationMicro < 0)
    {
      durationMicro += 1000;
      durationMilli -= 1;
    }
    delayMicroseconds(interval);
    
    switch(steps){
      case 0:
        SetPins(false,false,false, true);
        break;
      case 1:
        SetPins(false,false,true, true);
        break;
      case 2:
        SetPins(false,false,true, false);
        break;
      case 3:
        SetPins(false,true,true, false);
        break;
      case 4:
        SetPins(false,true,false, false);
        break;
      case 5:
        SetPins(true,true,false, false);
        break;
      case 6:
        SetPins(true,false,false, false);
        break;
      case 7:
        SetPins(true,false,false, true);
        break;
    }
  }
}

void loop()
{
  runMotor(1, 4000, 500);
  runMotor(-1, 4000, 500);
  runMotor(1, 2000, 500);
  runMotor(-1, 2000, 500);
  runMotor(1, 1000, 500);
  runMotor(-1, 1000, 500);
}
