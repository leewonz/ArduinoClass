import processing.serial.*;
int light = 0;
Serial port;
color c;
String buffer = "";
PFont font;

void setup()
{
  size(300,300);
  frameRate(20);
 
  font = loadFont("3270Medium-48.vlw");
  fill(255);
  textFont(font,32);
 
  println((Object[])Serial.list());
  String arduinoPort = Serial.list()[0];
  port = new Serial(this, arduinoPort, 9600);
}

void draw()
{
  background(c);
  text("knob level", 10, 100);
 
  text(light, 200, 100);
 
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
