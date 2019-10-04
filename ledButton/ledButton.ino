const int led = 12;
const int button = 4;
int val = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT); 
}

void loop() {
  
  val = digitalRead(button);

  if (val == HIGH)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
  
}
