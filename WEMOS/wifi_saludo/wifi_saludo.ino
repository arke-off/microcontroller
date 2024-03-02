#include <WiFi.h>

const char *ssid = "BunkerSeguro";
const char *password = "wifi2262";

void setup() {
  Serial.begin(115200);

  // Conectar a la red WiFi
  connectToWiFi();
}

void loop() {
  // Enviar un mensaje al Monitor Serie
  Serial.println("¡Hola desde mi Wemos D1 R32!");
  delay(1000);
}

void connectToWiFi() {
  Serial.println("Conectando a WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando...");
  }

  Serial.println("Conectado a la red WiFi");
}
