//definicionesPulsador
#define TTP223 2
int value;

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

  // Verifica si el temporizador ha alcanzado los 3 segundos
  if (tiempoInicio > 0 && millis() - tiempoInicio >= 3000)
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
}

void loop()
{

temporizadorPulsador();

}


