#include <Adafruit_NeoPixel.h>


#define PIN_LED 5
#define NUM_LEDS 1
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN_LED, NEO_GRB + NEO_KHZ800);


void setup ()
{
  strip.begin();
  strip.show();
}

void loop()
{
  
  // Enciende el primer LED en color rojo
  strip.setPixelColor(0, strip.Color(155, 0, 0));
  strip.show(); // Actualiza los LEDs con los cambios
  delay(1000);  // Espera 1 segundo

  // Apaga todos los LEDs
  strip.clear();
  strip.show(); // Actualiza los LEDs con los cambios
  delay(1000);   

  // Enciende el primer LED en color verde
  strip.setPixelColor(0, strip.Color(0, 155, 0));
  strip.show(); // Actualiza los LEDs con los cambios
  delay(1000); 

  // Apaga todos los LEDs
  strip.clear();
  strip.show(); // Actualiza los LEDs con los cambios
  delay(1000);   

}