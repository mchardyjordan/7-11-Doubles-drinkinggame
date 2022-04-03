#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int buttonPin=7,ledPin=6;

int buttonState=0;
int dice1=0,dice2=0,sum;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  //set up additional components
  pinMode(buttonPin,INPUT);
  pinMode(ledPin,OUTPUT);
   // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);  
}

void loop() { 

  buttonState=digitalRead(buttonPin);
  if(buttonState ==HIGH){
    digitalWrite(ledPin,HIGH);
  sum=0;
  randomSeed(millis()/1000);
  dice1=random(1,6);
  dice2=random(1,6);

  sum=dice1+dice2;
  if(sum == 7 || sum ==11 || dice1==dice2){   
    lcd.print("Dice 1:");
    lcd.print(dice1);
    lcd.print(" Dice 2:");
    lcd.print(dice2);    
    lcd.setCursor(0,1);
    lcd.print("7-11-Doubles!");
    delay(300);

  }
  else{
    lcd.print("Dice1:");
    lcd.print(dice1);
    lcd.print("Dice2:");
    lcd.print(dice2);
    lcd.setCursor(0,1);
    lcd.print("Roll Again");
    delay(300);
    }
  
  (int i=0;i<18;i++){
    lcd.scrollDisplayLeft();
    delay(250);
  }

buttonState=digitalRead(buttonPin);
digitalWrite(ledPin,LOW);
delay(500);
lcd.clear();
}
}
