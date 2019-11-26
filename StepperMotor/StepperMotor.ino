#define MAXSPEED 500
#define ACCDEACC 1600

int DirPin = 4;
int StepPin = 3;
int SyncPin = 10;

long counter = 0;

void setup()
{
  pinMode(DirPin, OUTPUT);
  pinMode(StepPin, OUTPUT);
  pinMode(SyncPin, OUTPUT);
  digitalWrite(SyncPin, HIGH);
}

void motorStep(long howMany, int dir)
{
  if(dir == 0)
  {
    digitalWrite(DirPin, HIGH);
    delayMicroseconds(5);
  }
  if(direc == 1)
  {
    digitalWrite(DirPin,LOW);
    delayMicroseconds(5);
  }

  int i = ACCDEACC;
  counter = 0;
  while(counter < howMany)
  {
    if(counter < ACCDEACC)
    {
      if(i > MAXSPEED)
      {
        i = i - 1;
      }
    }

    if(howMany - counter < ACCDEACC)
    {
      if(i < ACCDEACC)
      {
        i = i + 1;
      }
    }

    digitalWrite(SyncPin, LOW);
    digitalWrite(StepPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(StepPin, LOW);
    digitalWrite(SyncPin, HIGH);
    counter = counter + 1;
  }
}
void loop()
{
  motorstep(3000,1);
  delay(100);

  motorstep(10000,0);
  delay(100);

  motorstep(400,1);
  delay(100);

  motorstep(200,0);
  delay(100);

  motorstep(200,1);
  delay(100);

  motorstep(10000,1);
  delay(100);

  motorstep(400,0);
  delay(100);
}
