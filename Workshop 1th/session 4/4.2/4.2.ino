#include <Keypad.h>
#include <Servo.h>

Servo myservo;

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {7, 12, 11, 10};
byte colPins[COLS] = {9, 8, 1, 0};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup()
{
  myservo.attach(6);
  myservo.write(0);
}

void loop()
{
  char arr[3];
  for (int i = 0 ; i < 3 ; i++)
  {
    char customKey = customKeypad.waitForKey();
   arr[i] = customKey;
  }
  String value = arr;
  
  int v = value.toInt();
  myservo.write(v);
  delay (2000);
  myservo.write(0);
}