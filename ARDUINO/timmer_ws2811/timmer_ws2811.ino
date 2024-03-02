//definicionesPulsador
#define TTP223 2
int value;

  //definicionesLedWs2811
  #include <Adafruit_NeoPixel.h>
  #define PIN_LED 5
  #define NUM_LEDS 1
  Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN_LED, NEO_GRB + NEO_KHZ800);


    //pulsadorFuncionTimmer
    bool estadoAnterior = HIGH; // Estado anterior del pulsador
    unsigned long tiempoInicio = 0; // Tiempo en que se inició la pulsación
    void temporizadorPulsador()
    {
    bool estadoActual = digitalRead(TTP223);

      // Verifica si el pulsador ha sido presionado
      if (estadoActual == HIGH && estadoAnterior == LOW) 
      {
      tiempoInicio = millis(); // Inicia el temporizador al presionar el pulsador
      }

      // Verifica si el pulsador ha sido liberado
      if (estadoActual == LOW && estadoAnterior == HIGH)
      {
      tiempoInicio = 0; // Reinicia el temporizador al liberar el pulsador
      }

      // Verifica si el temporizador ha alcanzado los 1.5 segundos
      if (tiempoInicio > 0 && millis() - tiempoInicio >= 1500)
      {
      // Cambia el estado del LED
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));

      tiempoInicio = 0; // Reinicia el temporizador después de cambiar el estado del LED
      }

    // Almacena el estado actual para la siguiente iteración
    estadoAnterior = estadoActual;
    }



void setup ()
{
//setupPulsadorTimmer
pinMode(TTP223 , INPUT_PULLUP);
pinMode(LED_BUILTIN, OUTPUT);

  //setupLedWs2811
  strip.begin();
  strip.show();
}

void loop()
{

temporizadorPulsador();

int estado;
estado  = digitalRead(LED_BUILTIN);

if(estado==0)
  {
  strip.clear();                                    // apagaLeds
  strip.show();                                     // actualiza los LEDs con los cambios
  strip.setPixelColor(0, strip.Color(155, 0, 0));   // enciendeRojo
  strip.show();
  }else
  {  
  strip.clear();
  strip.show(); 
  strip.setPixelColor(0, strip.Color(0, 155, 0));   //enciendeVerde
  strip.show(); 
  }

}