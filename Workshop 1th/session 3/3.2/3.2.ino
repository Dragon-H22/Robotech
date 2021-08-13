int sensor = A0, led = 2;
void setup()
{
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  int senvalue = analogRead(sensor);
  if ( senvalue >= 511)
    digitalWrite(led, HIGH);
  else
    digitalWrite(led, LOW);
  float value = (senvalue / 1023.0)*5.0;
  unsigned long res = (1000 * value )/(5 - value);
  Serial.println(senvalue);
  delay(10);
}