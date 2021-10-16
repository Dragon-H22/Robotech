//session4
/*************/
//pract1
//**********
int pin1=3;
int pin2=4;
int btn1=5;
int btn2=6;
void setup() {
 pinMode(pin1,OUTPUT);
 pinMode(pin2,OUTPUT);
 pinMode(btn1,INPUT);
 pinMode(btn2,INPUT);
 Serial.begin(9600);
}

void loop() {
 int val1=analogRead(btn1);
 int val2=analogRead(btn2);
 if(val1==1)
 {
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
  delay(1000);
  digitalWrite(pin2,LOW);
 }
 else if(val2==1)
 {
  digitalWrite(pin2,LOW);
  digitalWrite(pin1,HIGH);
  delay(1000);
  digitalWrite(pin1,LOW);
 }
 else
 {
  digitalWrite(pin2,LOW);
  digitalWrite(pin1,LOW)
 }
}

//*******************************************************************
//pract2
//********

#include<Servo.h>
Servo myservo;
int trig=3;
int echo=4;
void setup() {
 pinMode(trig,OUTPUT);
 pinMode(echo,INPUT);
 myservo.attach(5);
 myservo.write(0);
}
void loop() {
 digitalWrite(trig,LOW);
 delayMicroseconds(5);
 digitalWrite(trig,HIGH);
 delayMicroseconds(5);
 digitalWrite(trig,LOW);
 float duration=pulseIn(echo,HIGH);
 float dis=duration/2/29;
 int Map_value=map(dis,0,400,0,360);
 myservo.write(Map_value);
 delay(200);
}
