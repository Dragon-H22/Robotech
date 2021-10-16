//session 5
/*************/
/*pract1
**********/
#define led1 D4
#define led2 D0

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  delay(1000);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(1000); 
}

/************************************************************************************
pract2
********/

#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <TimeLib.h>

char ssid[] = "";
char pass[] = "";

WiFiUDP udp;
NTPClient timeClient(udp,"time.nist.gov",7200);
void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid,pass);
  
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print('.');
  }
   Serial.println("Connected");

   timeClient.begin();
}

void loop() {
    timeClient.update();

    // timeClient.getFormattedTime() ==> return time
    Serial.println("Time: " + String(timeClient.getFormattedTime()));
    // timeClient.getEpochTime() ==> return seconds since 1970

    // setTime(seconds since 1970) ==> return Date usin day(), month(), year() functions
    unsigned long long sec = timeClient.getEpochTime();
    setTime(sec);
    Serial.println("Date: " + String(day()) + "/" + String(month()) + "/" + String(year()));
    delay(1000);
}
