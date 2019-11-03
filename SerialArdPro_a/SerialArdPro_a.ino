const int LED = 6;
const int LDR = 5;
int val = 0;
byte inByte = 0;

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  val = analogRead(LED);
  Serial.println(val);
  analogWrite(LED, val/4);
  if (Serial.available() >0)
  {
    inByte = Serial.read();
  }
  delay(100);
}
