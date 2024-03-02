unsigned long tiempoInicio = 0; // Tiempo en que se inició el parpadeo
unsigned long intervaloParpadeo = 1000; // Intervalo de parpadeo en milisegundos (1 segundo)

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  parpadearLED();
}

void parpadearLED() {
  unsigned long tiempoActual = millis(); // Obtiene el tiempo actual

  // Verifica si ha pasado el intervalo de parpadeo
  if (tiempoActual - tiempoInicio >= intervaloParpadeo) {
    // Cambia el estado del LED
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));

    // Actualiza el tiempo de inicio para el próximo parpadeo
    tiempoInicio = tiempoActual;
  }
  
  // Puedes realizar otras operaciones aquí si es necesario
}