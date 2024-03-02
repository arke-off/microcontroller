//definicionesLedWs2811
#include <Adafruit_NeoPixel.h>
#define PIN_LED 5
#define NUM_LEDS 1
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN_LED, NEO_GRB + NEO_KHZ800);

//funcionesLedWs2811
void encenderRojo()
{
  strip.setPixelColor(0, strip.Color(155, 0, 0));
  strip.show(); // Actualiza los LEDs con los cambios
};

void encenderVerde()
{
  strip.setPixelColor(0, strip.Color(0, 155, 0));
  strip.show(); // Actualiza los LEDs con los cambios
};

void apagarLeds()
{
  strip.clear();
  strip.show(); // Actualiza los LEDs con los cambios
};




void setup ()
{
  //setupLedWs2811
  strip.begin();
  strip.show();
}

void loop()
{
  
  encenderRojo();
  delay(1000);
  apagarLeds();
  delay(1000);
  encenderRojo();
  delay(1000);
  apagarLeds();
  delay(1000);
  encenderVerde();
  delay(1000);
  apagarLeds();
  delay(1000);
  encenderVerde();
  delay(1000);
  apagarLeds();
  delay(1000);



}