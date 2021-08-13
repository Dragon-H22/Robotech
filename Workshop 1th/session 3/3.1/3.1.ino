int ir = 2, buz = 3;
void setup()
{
  Serial.begin(9600);
  pinMode(ir, INPUT);
  pinMode(buz, OUTPUT);
}

void loop()
{
  int value = digitalRead(ir);
  if (value == 1)
    digitalWrite (buz, HIGH);
  else
    digitalWrite (buz, LOW);
    
  Serial.println(value);
}