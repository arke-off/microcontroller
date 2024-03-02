/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID           "TMPL2hXEAWtLw"
#define BLYNK_TEMPLATE_NAME         "PlantillaWEMOS"
#define BLYNK_AUTH_TOKEN            "rhX39_vaVil3gCrVDozZU-J5xZv45Q-l"


// activar mensajes por puerto serial del WEMOS D1 Comment this out to disable prints and save space 
#define BLYNK_PRINT Serial



#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "BunkerSeguro";
char pass[] = "wifi2262";



/*crea una instancia proporcionando una manera de 
manejar tareas temporales o repetitivas en el programa Blynk*/
BlynkTimer timer;   






// esta función es llamada cada vez que cambia el estado del pin virtual 0
BLYNK_WRITE(V0)
{
  //  guarda el valor entrante del pin V0 en una variable llamada value
  int value = param.asInt();



  // Update state
  /*se utiliza para enviar datos desde tu dispositivo a la aplicación Blynk.
  Puedes usar esto para actualizar el estado de widgets en la aplicación, como 
  un indicador, un gráfico, o cualquier otro widget asociado a un pin virtual.
  */
  Blynk.virtualWrite(V1, value);



  // (test propio) Imprime el valor de V0 en el monitor serial,enciende el led interno del WEMOS 
  if (value==0)
  {
    Serial.print("Valor en el pin V0: ");
    Serial.println(value);
    Serial.println("apagado");
    digitalWrite(LED_BUILTIN, LOW);
  }
  else 
  {
    Serial.print("Valor en el pin V0: ");
    Serial.println(value);
    Serial.println("encendido");
    digitalWrite(LED_BUILTIN, HIGH);
  }
  

}


void estadosensor(){

  int estado;

  estado = digitalRead(22);

  if (estado == HIGH){
  Blynk.virtualWrite(V2, 1);
  }
	else
  {
  Blynk.virtualWrite(V2, 0);
	}

}


// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}






// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V2, millis() / 1000);
}






void setup()
{
  // Debug console
  Serial.begin(115200);


  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);


  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);

  //(test) funciona Configura el pin interno del LED como salida
  pinMode(LED_BUILTIN, OUTPUT);

  //(test) Configura el pin GPIO22 como entrada de sensor magnético
	pinMode(22, INPUT_PULLUP);
}






void loop()
{
  Blynk.run();
  timer.run();
  // Remember to avoid delay() function!

  //(test sensor)
  estadosensor();
}