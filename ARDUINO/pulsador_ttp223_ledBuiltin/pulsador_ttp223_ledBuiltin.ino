#define TTP223 2
int value;
void setup ()
{
  Serial.begin(9600);
  pinMode(TTP223 , INPUT_PULLUP);
}

void loop()
{
  value = digitalRead(TTP223);
  Serial.println(value);
  delay(1000);
}