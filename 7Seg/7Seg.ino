//*******************************************************************************
// Project : FND 7 segement in Learing Kit
// Board : Arduino Uno
// By : Kit Plus
//*******************************************************************************
#define ANODE_TYPE
int num_array[10][7] = { { 1,1,1,1,1,1,0 }, // 0
{ 0,1,1,0,0,0,0 }, // 1
{ 1,1,0,1,1,0,1 }, // 2
{ 1,1,1,1,0,0,1 }, // 3
{ 0,1,1,0,0,1,1 }, // 4
{ 1,0,1,1,0,1,1 }, // 5
{ 1,0,1,1,1,1,1 }, // 6
{ 1,1,1,0,0,0,0 }, // 7
{ 1,1,1,1,1,1,1 }, // 8
{ 1,1,1,0,0,1,1 }}; // 9
//display fnd
void Num_Write(int);
void setup()
{
// set pin modes
pinMode(2, OUTPUT); //a
pinMode(3, OUTPUT); //b
pinMode(4, OUTPUT); //c
pinMode(5, OUTPUT); //d
pinMode(6, OUTPUT); //e
pinMode(7, OUTPUT); //f
pinMode(8, OUTPUT); //b
for (int j=2; j <= 8; j++) {
digitalWrite(j, HIGH);
}
}
void loop()
{
for (int counter = 10; counter > 0; --counter)
{
delay(1000);
Num_Write(counter-1);
}
delay(3000);
}
void Num_Write(int number)
{
int pin= 2;
for (int j=0; j < 7; j++){
#ifdef ANODE_TYPE
digitalWrite(pin, !num_array[number][j]);
#else
digitalWrite(pin, num_array[number][j]);
#endif
pin++;
}
}
