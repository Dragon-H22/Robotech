int pinbuz = 13;
int pinbottun = 7;
int led = 2 ;


void setup()
{
  Serial.begin(9600);
  pinMode(pinbuz, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(pinbottun, INPUT);
}

void loop()
{
  int x = digitalRead (pinbottun);
  Serial.println(x);
  if (x == 1)
  {
    digitalWrite (pinbuz, HIGH);
    digitalWrite (led, HIGH);
    delay(1000);
    digitalWrite (pinbuz, LOW);
    digitalWrite (led, LOW);
    delay(1000);
  }
  else
  {
    digitalWrite (pinbuz, LOW);
    digitalWrite (pinbuz, LOW);
  }
  
}