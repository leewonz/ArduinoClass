
int cds = A0;
int led = 3;

const int INPUT_MIN = 900;
const int INPUT_MAX = 450;
const int OUTPUT_MIN = 0;
const int OUTPUT_MAX = 255;
 

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}
 

void loop() {

  //read CdS
  int cdsValue = analogRead(cds);
  int cdsValue_Mapped = cdsValue;

  //print as serial
  Serial.print("cds =  ");
  Serial.println(cdsValue);

  //map CdS value to LED value
  if (INPUT_MIN < INPUT_MAX)
  {
    cdsValue_Mapped = constrain(cdsValue_Mapped, INPUT_MIN, INPUT_MAX);
  }
  else
  {
    cdsValue_Mapped = constrain(cdsValue_Mapped, INPUT_MAX, INPUT_MIN);
  }
  cdsValue_Mapped = map(cdsValue_Mapped, INPUT_MIN, INPUT_MAX, OUTPUT_MIN, OUTPUT_MAX);
  //cdsValue_Mapped = map_pow(cdsValue_Mapped, OUTPUT_MIN, OUTPUT_MAX, 2);

  //write to LED
  analogWrite(led, cdsValue_Mapped);
  
}

// map some value to power of that value
float map_pow(float val, float valMin, float valMax, float exponent)
{
  return pow((val - valMin) / (valMax - valMin), exponent) * (valMax - valMin) + valMin;
}
