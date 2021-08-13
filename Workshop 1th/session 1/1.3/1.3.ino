int led1 = 13;
int led2 = 12;
int pot = A0;


void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(pot, INPUT);
}

void loop()
{
  int value = analogRead (pot);
  int potvalue = map (value , 0 , 1023 , 0 , 255);
  analogWrite (led1 , potvalue);
  analogWrite (led2 , 255-potvalue);
  
}