#include "Tlc5940.h"

struct COLOR {
  int r;
  int g;
  int b;
};

struct RGB {
  int rPin;
  int gPin;
  int bPin;
};

COLOR BLACK = {0, 0, 0};
COLOR RED = {4095, 0, 0};
COLOR ORANGE = {4095, 1023, 0};
COLOR YELLOW = {4095, 4095, 0};
COLOR GREEN = {0, 4095, 0};
COLOR CYAN = {0, 4095, 4095};
COLOR BLUE = {0, 0, 4095};
COLOR MAGENTA = {4095, 0, 4095};

COLOR COLORS[] = {RED, ORANGE, YELLOW, GREEN, BLUE}; //, MAGENTA, CYAN};

RGB sec01 = {0, 1, 2};
RGB sec02 = {3, 4, 5};
RGB sec03 = {6, 7, 8};
RGB sec04 = {9, 10, 11};
RGB sec05 = {12, 13, 14};

RGB RGBS[] = {sec01, sec02, sec03, sec04, sec05};

int colorCycle = 0;

class LedHandler
{
  public:
  void init();
  
  void setRgbColor(RGB l, COLOR c);
  void solidRainbow(COLORS[] cs);
};

void LedHandler::init()
{
  Tlc.init();
};

void LedHandler::setRgbColor(RGB l, COLOR c)
{
  Tlc.set(l.rPin, c.r);
  Tlc.set(l.gPin, c.g);
  Tlc.set(l.bPin, c.b);
}

void LedHandler::solidRainbow(COLORS[] cs)
{
  //do something here
}

LedHandler ledHandler;

void setup()
{
  ledHandler.init();
  Serial.begin(9600);
}

void loop()
{
  Tlc.clear();
  int resetCycle = colorCycle;
  Serial.println("loop");
  Serial.println(resetCycle);
  
  for(int l = 0;l < 5; l++)
  {
    //Serial.println(colorCycle);
    ledHandler.setRgbColor(RGBS[l], COLORS[colorCycle]);
    Serial.println(colorCycle);
    
    if(colorCycle == 4)
    {
      colorCycle = 0;
    }
    else
    {
      colorCycle++;
    }
    
    //delay(1000);
  }
  Tlc.update();
  Serial.println(resetCycle);
  if(resetCycle == 4)
  {
    colorCycle = 0;
    Serial.println("true");
  }
  else
  {
    colorCycle = resetCycle + 1;
    Serial.println("else");
  }  
  
  delay(100);
}

