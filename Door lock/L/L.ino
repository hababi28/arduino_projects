#include <LiquidCrystal_74HC595.h>
#include <SPI.h>
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>
Servo myservo;

#define Password_Lenght 7 // Give enough room for six chars + NULL char
int pos = 0;    // variable to store the servo position
char Data[Password_Lenght]; // 6 is the number of chars it can hold + the null char = 7
char Master[Password_Lenght] = "123456";

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

bool door = true;
char customKey;
byte data_count = 0, master_count = 0;
String attempt;
 
// Initialize the LCD screen using the latch pin
LiquidCrystal lcd(10);

//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {A0, 8, 7, 6}; //connect to the column pinouts of the keypad

//initialize a NewKeypad
Keypad myKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup()
{
  myservo.attach(9);
  ServoClose();
  lcd.begin(16, 2);
  lcd.print(" Arduino Door");
  lcd.setCursor(0, 1);
  lcd.print("--Look project--");
  delay(3000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (attempt == "280802"){
      lcd.clear();
      ServoOpen();
      lcd.setCursor(0,0);
      lcd.print("Door is Open");
      delay(3000);
      attempt = "";
}
  if (attempt == "####") {
      lcd.clear();
      ServoClose();
      attempt = "";
}
  else {
     bacaKeypad();
     lcd.setCursor(0,0);
     lcd.print("Password pls");
     lcd.setCursor(0,1);
     lcd.print(attempt);
     delay(100);
          if (attempt.length() > 6) {
          lcd.clear();
          attempt = "";
          }
  }
}

void bacaKeypad() {
  char keypressed = myKeypad.getKey(); //deteksi penekanan keypad
  String entry = String(keypressed);
  attempt+=entry;
}

void ServoOpen()
{
  myservo.write(0);// move servos to center position -> 90°
  delay(1000);           
}

void ServoClose()
{
  myservo.write(90);// move servos to center position -> 90°
  delay(1000);
}
  
