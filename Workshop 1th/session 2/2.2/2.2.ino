#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 13);

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','e'},
  {'4','5','6','g'},
  {'7','8','9','C'},
  {'.','0','#','D'}
};
byte rowPins[ROWS] = {7, 12, 11, 10};
byte colPins[COLS] = {9, 8, 1, 0};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
char pass1[7];
char pass2[7] = {'e','g','.','1','2','3','4'};
int c = 0;
void setup()
{
  lcd.begin(16, 2);
}
  
void loop()
{
  lcd.clear();
  for (int i = 0 ; i < 7 ; i++)
  {
    char customKey = customKeypad.waitForKey();
    pass1[i] = customKey;
    lcd.print(customKey);
  }
  
  delay(250);
   for (int i = 0 ; i < 7 ; i++)
   {
     if (pass1[i] == pass2[i])
     {
       c++;
     }
   }
  
  if(c == 7)
  {
    lcd.clear();
    lcd.print("correct password");
    delay(2500);
  }
  else
  {
    lcd.clear();
    lcd.print("wrong password");
    delay(2500);
  }
  c = 0;
}