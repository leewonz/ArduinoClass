import processing.serial.*;
int light = 0;
Serial port;
color c;
String buffer = "";
PFont font;

int xspacing = 16;   // How far apart should each horizontal location be spaced
int w;              // Width of entire wave

float theta = 0.0;  // Start angle at 0
float amplitude = 75.0;  // Height of wave
float period = 500.0;  // How many pixels before the wave repeats
float dx;  // Value for incrementing X, a function of period and xspacing
float[] yvalues;  // Using an array to store height values for the wave

void setup()
{
  size(640, 360);
  w = width+16;
  dx = (TWO_PI / period) * xspacing;
  yvalues = new float[w/xspacing];
 
  println((Object[])Serial.list());
  String arduinoPort = Serial.list()[0];
  port = new Serial(this, arduinoPort, 9600);
}

void draw()
{
  amplitude = light / 8;
  
  background(0);
  calcWave();
  renderWave();
 
  if(port.available() > 0)
  {
    int inByte = port.read();
    if (inByte != 10)
    {
      buffer = buffer + char(inByte);
    }
    else
    {
      if (buffer.length() != 0)
      {
        buffer = buffer.substring(0,buffer.length() - 1);
        light = int(buffer);
      }
      buffer = "";
      port.clear();
    }
  }
}


void calcWave() {
  // Increment theta (try different values for 'angular velocity' here
  theta += 0.02;

  // For every x value, calculate a y value with sine function
  float x = theta;
  for (int i = 0; i < yvalues.length; i++) {
    yvalues[i] = sin(x)*amplitude;
    x+=dx;
  }
}

void renderWave() {
  noStroke();
  fill(255);
  // A simple way to draw the wave with an ellipse at each location
  for (int x = 0; x < yvalues.length; x++) {
    ellipse(x*xspacing, height/2+yvalues[x], 16, 16);
  }
}
