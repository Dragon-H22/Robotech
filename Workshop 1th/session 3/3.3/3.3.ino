#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 5, 6, 7, 8, 9);
int temp = A0;
int trig = 3, echo = 2;

byte degree[8] =
{
  B11100,
  B10100,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
};


void setup()
{
  lcd.begin(16, 2);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(temp, INPUT);
}

void loop()
{
  float duration, distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(0.0001);
  digitalWrite(trig, HIGH);
  delayMicroseconds(0.0001);
  duration = pulseIn(echo, HIGH);
  distance = (duration / 29) / 2;
  
  
  int value = analogRead(temp);
  float mv = value/1023.0;
  mv = mv * 5;
  mv = mv - 0.5;
  mv = mv * 1000;
  float cl = mv/10;
  
  
  lcd.setCursor(0,0);
  lcd.print(distance);
  lcd.print(" cm");
  
  lcd.setCursor(0,1);
  lcd.print(cl);
  lcd.createChar(1, degree);
  lcd.setCursor(6,1);
  lcd.write(1);
  
  
}