//pract1
//********
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','A'},
  {'7','8','9','A'},
  {'*','0','#','A'}
};
byte rowPins[ROWS] = {11, 10, 9, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7,6, 5, 4}; //connect to the column pinouts of the keypad
String pass="1234";
String Enter_pass="";
int i=0;
Keypad customkey = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  pinMode(3,OUTPUT);
}
  
void loop(){
  while(i<4)
  {
    char cust=customkey.waitForKey();
    Enter_pass+=cust;
    Serial.println(Enter_pass);
    i++;
  }
  
  if (Enter_pass==pass){
    int x=analogRead(A0);
    int pot_Map=map(x,0,1023,0,255);
    analogWrite(3,pot_Map);
    Serial.println("Successful");
  }
  else
  {
    Serial.println("Faild");
    Enter_pass="";
    i=0;
  }
}
//*************************************************************************************
//pract2
//*******

#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
bool flag=true;
void setup() {
  lcd.begin(16, 2);
 pinMode(7,INPUT);
 Serial.begin(9600);
}

void loop() {
  lcd.setCursor(0, 1);
  int val=analogRead(7);
  if(val==1&& flag==true)
  {
    Serial.print("someone is here");
    flag=false;
  }
  else if(val==0&& flag==false)
  {
//    Serial.clear();
//  lcd.clear();
    flag=true;
  }
  // print the number of seconds since reset:
//  lcd.print(millis() / 1000);
}
//**********************************************************************

int echo=12;
int trig=11;
int buzzer=13;
void setup() {
  // put your setup code here, to run once:
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(buzzer,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
  delayMicroseconds(5);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  int duration=pulseIn(echo,HIGH);
  int distance=duration/2/29;
  if(distance < 50)
  {
    digitalWrite(buzzer,HIGH);
  }
  else
  {
    digitalWrite(buzzer,LOW`);
  }
  
  
}
