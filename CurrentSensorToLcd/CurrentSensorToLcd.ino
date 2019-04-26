#include <Filters.h>

#include <LiquidCrystal.h>


double kilos = 0;
int peakPower = 0;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float testFrequency = 60;                     // test signal frequency (Hz)
float windowLength = 20.0/testFrequency;     // how long to average the signal, for statistist
int sensorValue = 0;
float intercept = 0.1; // to be adjusted based on calibration testing
float slope = 0.0405; // to be adjusted based on calibration testing
float current_amps; // estimated actual current in amps

unsigned long printPeriod = 1000; // in milliseconds
// Track time in milliseconds since last reading 
unsigned long previousMillis = 0;

void setup() {
  Serial.begin( 57600 );    // start the serial port

  lcd.begin(16,2);              // columns, rows.  use 16,2 for a 16x2 LCD, etc.
  lcd.clear();
  lcd.setCursor(0,0);    
   lcd.print("SMART FUEL");
   lcd.setCursor(0,1);  
    lcd.print("MONITORING S/M");
  delay(1000);
  lcd.clear();
}

void loop() {
  int current = 0;
  int maxCurrent = 0;
  int minCurrent = 1000;
  RunningStatistics inputStats;                 // create statistics to look at the raw test signal
  inputStats.setWindowSecs( windowLength );
   
  while( true ) {   
    sensorValue = analogRead(A0);  // read the analog in value:
    inputStats.input(sensorValue);  // log to Stats function
    
        
    if((unsigned long)(millis() - previousMillis) >= printPeriod) {
      previousMillis = millis();   // update time
      
      // display current values to the screen
      Serial.print( "\n" );
      // output sigma or variation values associated with the inputValue itsel
      Serial.print( "\tsigma: " ); Serial.print( inputStats.sigma() );
      // convert signal sigma value to current in amps
      current_amps = intercept + slope * inputStats.sigma();
      Serial.print( "\tamps: " ); Serial.print( current_amps );
      for (int i=0 ; i<=200 ; i++)  //Monitors and logs the current input for 200 cycles to determine max and min current
  {
    current = current_amps;    //Reads current input and records maximum and minimum current
    if(current >= maxCurrent)
      maxCurrent = current;
    else if(current <= minCurrent)
      minCurrent = current;
  }
  if (maxCurrent <= 517)
  {
    maxCurrent = 516;
  }
  double RMSCurrent = ((maxCurrent - 516)*0.707)/11.8337;    //Calculates RMS current based on maximum value
  int RMSPower = 220*RMSCurrent;    //Calculates RMS Power Assuming Voltage 220VAC, change to 110VAC accordingly
  if (RMSPower > peakPower)
  {
    peakPower = RMSPower;
  }
  kilos = kilos + (RMSPower * (2.05/60/60/1000));    //Calculate kilowatt hours used
  delay (2000);
      lcd.clear();
  lcd.setCursor(0,0);           // Displays all current data
  lcd.print(current_amps);
  lcd.print("A");
  lcd.setCursor(10,0);
  lcd.print(RMSPower);
  lcd.print("W");
  lcd.setCursor(0,1);
  lcd.print(kilos);
  lcd.print("kWh");
  lcd.setCursor(10,1);
  lcd.print(peakPower);
  lcd.print("W");}
    }
  }
