/*v 

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 

*/

const int AOUTpin=0;//the AOUT pin of the alcohol sensor goes into analog pin A0 of the arduino
const int DOUTpin=8;//the DOUT pin of the alcohol sensor goes into digital pin D8 of the arduino
int limit;
int value;

#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {



Serial.begin(9600);
pinMode(DOUTpin, INPUT);

lcd.begin(8, 2);

}

void loop() {

value= analogRead(AOUTpin);
limit= digitalRead(DOUTpin);
Serial.print("Alcohol value: ");
Serial.println(value);
Serial.print("Limit: ");
Serial.print(limit);
delay(100);


 
  lcd.setCursor(0, 0);
  lcd.print("VALUE: ");
  lcd.setCursor(0, 1);
  lcd.print(value);
}

