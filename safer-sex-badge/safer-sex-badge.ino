#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

// Based off an arduino strandtest exampe sketch. 
// 

#define PIN 3

Adafruit_NeoPixel strip = Adafruit_NeoPixel(3, PIN, NEO_RGB + NEO_KHZ800);

void setup() 
{
  strip.begin();
  strip.show();
}

void loop() 
{
  cum(strip.Color(127,   0,   0), 250); // Red
}

void cum(uint32_t c, uint8_t wait) 
{
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0x020215);    //turn every third pixel on
      }
      strip.show();
     
      delay(wait);
     
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0x0B4A55);        //turn every third pixel off
      }
    }
  }
}
