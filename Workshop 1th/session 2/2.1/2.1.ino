
int blue = 12;
int buz = 11;
int pinbottun = 7;

void setup()
{

  pinMode(blue, OUTPUT);
  pinMode(buz, OUTPUT);
  pinMode(pinbottun, INPUT);
  Serial.begin(9600);
}
void loop()
{
  int x = digitalRead (pinbottun);
  if (x == 1)
  {
    Serial.write("push button is pressed");
    delay(1000);
  }
  
  if (Serial.available()>0)
  {
    char data=Serial.read();
    if (data == 'I')
    {
      digitalWrite(buz, LOW);
      digitalWrite(blue, HIGH);
      delay(1000);
      digitalWrite(blue, LOW);
    }
    else if (data == 'b')
    {

      digitalWrite(blue, LOW);
      digitalWrite(buz, HIGH);
      delay(1000);
      digitalWrite(buz, LOW);
    }
  }
  
  
}