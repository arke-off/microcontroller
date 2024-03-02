/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
*/


void ledParpadeoSerial(){
  int estado;

  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)

  estado = digitalRead(LED_BUILTIN);
  serialEstado(estado);


  delay(2000);                      // wait for a second

  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW

  estado = digitalRead(LED_BUILTIN);
  serialEstado(estado);

  delay(2000);                      // wait for a second
}


void serialEstado(int estado){

  if (estado == 1){
      Serial.println("Led encendido |•|");

  }else {
    Serial.println  ("Led apagado   |○|");
  }

}








// the setup function runs once when you press reset or power the board
//declaras que pintes de entrada o salidas vas a usar
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}








// the loop function runs over and over again forever
void loop() {
 
ledParpadeoSerial();




}
