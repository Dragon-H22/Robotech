//session6
/*************/
/*pract1
**********/
#include <ESP8266WiFi.h>
String apiWritekey = "ZITS4JAW5THXT4VK"; // replace with your THINGSPEAK WRITEAPI key here
const char* ssid = "Supernet"; // your wifi SSID name
const char* password = "5C-2B+7?GMhSyHs9" ;// wifi pasword
const char* server = "api.thingspeak.com";
int echoPin=D6; 
int trigPin=D5;
int duration;
int distance;
WiFiClient client;
 
void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  Serial.begin(115200);
  WiFi.disconnect();
  delay(10);
  WiFi.begin(ssid, password);
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("NodeMcu connected to wifi...");
  Serial.println(ssid);
  Serial.println();
}
 
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  //String val;
  if (client.connect(server,80))
  {  /*if (Serial.available()) {
   val=Serial.readString();
  }*/
    String tsData = apiWritekey;
           tsData +="&field1=";
           tsData += String(distance);
           tsData += "\r\n\r\n";
 
     client.print("POST /update HTTP/1.1\n");
     client.print("Host: api.thingspeak.com\n");
     client.print("Connection: close\n");
     client.print("X-THINGSPEAKAPIKEY: "+apiWritekey+"\n");
     client.print("Content-Type: application/x-www-form-urlencoded\n");
     client.print("Content-Length: ");
     client.print(tsData.length());
     client.print("\n\n");  // the 2 carriage returns indicate closing of Header fields & starting of data
     client.print(tsData);
     Serial.print("Distance ");
     Serial.print(distance);
     Serial.println("uploaded to Thingspeak server....");
  }
  client.stop();
 // thingspeak needs minimum 15 sec delay between updates
// delay(15000);
}

/******************************************************************************************************************************
pract2
********/

#include "UbidotsESPMQTT.h"
#define TOKEN "BBFF-MumnFdt3HttgT3pvSRHk9BtMigTNWB"     // Your Ubidots TOKEN
#define WIFINAME "Not for you"  // Your SSID
#define WIFIPASS "01017907319"  // Your Wifi Pass
#define DEVICE_LABEL "led"
#define VARIABLE1 "mcu"
int ledpin = D4;
String value1="";
Ubidots client(TOKEN);

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
  if (payload[0]==1)
  {
    digitalWrite(ledpin, HIGH);
    Serial.println("1");
  }
  else
  {
    digitalWrite(ledpin, LOW);
    Serial.println("0"); 
  }
}

void setup() 
{
  client.setDebug(true); 
  Serial.begin(115200);
  client.wifiConnection(WIFINAME, WIFIPASS);
  client.begin(callback);
  client.ubidotsSubscribe(DEVICE_LABEL, VARIABLE1);
  pinMode(ledpin, OUTPUT);
}

void loop() 
{
  if (!client.connected()) 
  {
    client.reconnect();
    client.ubidotsSubscribe(DEVICE_LABEL, VARIABLE1);
  }
  client.loop();
}
