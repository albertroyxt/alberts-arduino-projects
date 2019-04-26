#include <LiquidCrystal.h>


float voltageSense;
float voltageValue;
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
byte sensorInterrupt1 = 0;  // 0 = digital pin 2
byte sensorInterrupt2 = 1;
float inLitre=0;

byte sensorPin1       = 2;
byte sensorPin2       = 3;
// The hall-effect flow sensor outputs approximately 4.5 pulses per second per
// litre/minute of flow.
float calibrationFactor1 = 5;
float calibrationFactor2 = 4.5;

volatile byte pulseCount1;  
volatile byte pulseCount2;  

float flowRate1;
unsigned int flowMilliLitres1;
unsigned long totalMilliLitres1;

unsigned long oldTime;

float flowRate2;
unsigned int flowMilliLitres2;
unsigned long totalMilliLitres2;

#define pulsein A0
unsigned int pulse_count=0;
float units=0.01;

 float watt_factor=0.3125;

int loopCounter=1;

void setup()
{
  Serial.begin(9600);
  // Initialize a serial connection for reporting values to the host
 lcd.begin(16, 2);
  pinMode(pulsein, INPUT);
  digitalWrite(pulsein, LOW);
  
 pinMode(A4, INPUT);
 
  pinMode(sensorPin1, INPUT);
  digitalWrite(sensorPin1, HIGH);
  pinMode(sensorPin2, INPUT);
  digitalWrite(sensorPin2, HIGH);

  pulseCount1        = 0;
  flowRate1          = 0.0;
  flowMilliLitres1   = 0;
  totalMilliLitres1  = 0;
  oldTime           = 0;

 pulseCount2        = 0;
  flowRate2          = 0.0;
  flowMilliLitres2   = 0;
  totalMilliLitres2  = 0;
  
  // The Hall-effect sensor is connected to pin 2 which uses interrupt 0.
  // Configured to trigger on a FALLING state change (transition from HIGH
  // state to LOW state)
  attachInterrupt(sensorInterrupt1, pulseCounter1, FALLING);
  attachInterrupt(sensorInterrupt2, pulseCounter2, FALLING);
}

/**
 * Main program loop
 */
void loop()
{
  voltageSense=analogRead(A7);
  voltageValue=voltageSense * (5.0 / 1023.0);
  Serial.print(voltageValue);
  Serial.print("\n");
  if(digitalRead(pulsein))
    {
           pulse_count++;
      delay(0);
      units=(watt_factor*pulse_count/1000);
    
    }  
   if((millis() - oldTime) > 1000)   // Only process counters once per second
  { 
    // Disable the interrupt while calculating flow rate and sending the value to
    // the host
    detachInterrupt(sensorInterrupt1);
    detachInterrupt(sensorInterrupt2);
        
    // Because this loop may not complete in exactly 1 second intervals we calculate
    // the number of milliseconds that have passed since the last execution and use
    // that to scale the output. We also apply the calibrationFactor to scale the output
    // based on the number of pulses per second per units of measure (litres/minute in
    // this case) coming from the sensor.
    flowRate1 = ((1000.0 / (millis() - oldTime)) * pulseCount1) / calibrationFactor1;
    flowRate2 = ((1000.0 / (millis() - oldTime)) * pulseCount2) / calibrationFactor2;
    
    // Note the time this processing pass was executed. Note that because we've
    // disabled interrupts the millis() function won't actually be incrementing right
    // at this point, but it will still return the value it was set to just before
    // interrupts went away.
    oldTime = millis();
    
    // Divide the flow rate in litres/minute by 60 to determine how many litres have
    // passed through the sensor in this 1 second interval, then multiply by 1000 to
    // convert to millilitres.
    flowMilliLitres1 = (flowRate1 / 60) * 1000;
    
    // Add the millilitres passed in this second to the cumulative total
    totalMilliLitres1 += flowMilliLitres1;
      
    unsigned int frac1;

    flowMilliLitres2 = (flowRate2 / 60) * 1000;
    
    // Add the millilitres passed in this second to the cumulative total
    totalMilliLitres2 += flowMilliLitres2;
      
    unsigned int frac2;
    
    // Print the flow rate for this second in litres / minute
    Serial.print("Flow rate1: ");
    Serial.print(int(flowRate1));  // Print the integer part of the variable
    Serial.print("L/min");
    Serial.print("\t Flow1: ");       // Print tab space
     Serial.print(totalMilliLitres1);
    Serial.println("mL"); 
    Serial.print("\t");
     Serial.print("Flow rate2: ");
    Serial.print(int(flowRate2));  // Print the integer part of the variable
    Serial.print("L/min");
    Serial.print("\t Flow 2:");       // Print tab space
 Serial.print(totalMilliLitres2);
    Serial.println("mL"); 
    Serial.print("Consumption: ");
    if((totalMilliLitres1-totalMilliLitres2)<40000000)
    inLitre=((totalMilliLitres1-totalMilliLitres2));
    Serial.print(totalMilliLitres1-totalMilliLitres2);
        Serial.print("\t \n");


   
    // Reset the pulse counter so we can start incrementing again
    pulseCount1 = 0;
    pulseCount2 = 0;
    
    // Enable the interrupt again now that we've finished sending output
    attachInterrupt(sensorInterrupt1, pulseCounter1, FALLING);
    attachInterrupt(sensorInterrupt2, pulseCounter2, FALLING);
  }

if((voltageValue<=5.0)&&(voltageValue>3.5))
loopdata1();
else if((voltageValue<=3.5)&&(voltageValue>2.0))
loopdata2();
else if((voltageValue<=2.0)&&(voltageValue>0.0))
loopdata3();
}

/*
Insterrupt Service Routine
 */
void pulseCounter1()
{
  // Increment the pulse counter
  pulseCount1++;

}
void pulseCounter2()
{
  // Increment the pulse counter

  pulseCount2++;
}

void loopdata1(){
  
lcd.setCursor(0, 0);
   lcd.print("FUEL:");
   lcd.setCursor(5, 0);
   lcd.print(inLitre);
   lcd.setCursor(11, 0);
   lcd.print("  ");
   lcd.setCursor(13, 0);
   lcd.print("ML ");
lcd.setCursor(0, 1);
   lcd.print("ENERGY:");
   lcd.setCursor(7, 1);
   lcd.print(units);
   lcd.setCursor(13, 1);
   lcd.print("KWH");/*  
     

   */
  }


void loopdata2(){
  lcd.clear();
  lcd.setCursor(0, 0);
   lcd.print("CONSUMPTION");
   lcd.setCursor(0, 1);
   lcd.print((units/(inLitre/1000)),4);
lcd.setCursor(11, 1);
   lcd.print("KWH/L"); }

   void loopdata3(){
    lcd.clear();
    lcd.setCursor(0, 0);
   lcd.print("loop3");
   lcd.setCursor(6, 0);/*
   lcd.print(units/(inLitre/1000));
lcd.setCursor(11, 0);
   lcd.print("KWH/L");} */
}

