int m1p1 = 2, m1p2 = 3, temp = A0;
void setup()
{
  pinMode(m1p1, OUTPUT);
  pinMode(m1p2, OUTPUT);
  pinMode(temp, INPUT);
  Serial.begin(9600);
}
void loop()
{
  int value = analogRead(temp);
  float mv = value/1023.0;
  mv = mv * 5;
  mv = mv - 0.5;
  mv = mv * 1000;
  float cl = mv/10;
  Serial.println(cl);
  
  if (cl >= 37)
  {
    digitalWrite(m1p1, HIGH);
    digitalWrite(m1p2, LOW);
  }
  else
  {
    digitalWrite(m1p1, LOW);
    digitalWrite(m1p2, LOW);
  }
}