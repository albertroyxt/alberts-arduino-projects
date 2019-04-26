#include <LiquidCrystal.h>

const int LCDVCC=3;
const int rs=4;

const int en=6;
const int d4=7;
const int d5=8;
const int d6=9;
const int d7=10;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
              
void setup() {
              pinMode(LCDVCC, OUTPUT);
              

              digitalWrite(LCDVCC, HIGH);
              lcd.begin(16, 2);
  
              Serial.begin(9600);// Begin Serial port at a Buad speed of 9600bps 
                   
              }  
void loop(){
lcd.setCursor(0,0);
lcd.print("Hello");
    
    
    }

