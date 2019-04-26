byte statusLed    = 13;

byte sensorInterrupt1 = 0;  // 0 = digital pin 2
byte sensorInterrupt2 = 0;
byte sensorPin1       = 2;
byte sensorPin2       =3;

// The hall-effect flow sensor outputs approximately 4.5 pulses per second per
// litre/minute of flow.
float calibrationFactor1 = 4.5;
float calibrationFactor2 = 4.5;

volatile byte pulseCount1;  
volatile byte pulseCount2; 

float flowRate1;
unsigned int flowMilliLitres1;
unsigned long totalMilliLitres1;

unsigned long oldTime1;
float flowRate2;
unsigned int flowMilliLitres2;
unsigned long totalMilliLitres2;

unsigned long oldTime2;

void setup()
{
  
  // Initialize a serial connection for reporting values to the host
  Serial.begin(9600);
   
  // Set up the status LED line as an output
  pinMode(statusLed, OUTPUT);
  digitalWrite(statusLed, HIGH);  // We have an active-low LED attached
  
  pinMode(sensorPin1, INPUT);
  digitalWrite(sensorPin1, HIGH);
    pinMode(sensorPin2, INPUT);
  digitalWrite(sensorPin2, HIGH);

  pulseCount1        = 0;
  flowRate1          = 0.0;
  flowMilliLitres1   = 0;
  totalMilliLitres1  = 0;
  oldTime1           = 0;

    pulseCount2        = 0;
  flowRate2          = 0.0;
  flowMilliLitres2   = 0;
  totalMilliLitres2  = 0;
  oldTime2           = 0;

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
   
   if((millis() - oldTime1) > 1000)    // Only process counters once per second
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
    flowRate1 = ((1000.0 / (millis() - oldTime1)) * pulseCount1) / calibrationFactor1;

     flowRate2 = ((1000.0 / (millis() - oldTime2)) * pulseCount2) / calibrationFactor2;
    
    // Note the time this processing pass was executed. Note that because we've
    // disabled interrupts the millis() function won't actually be incrementing right
    // at this point, but it will still return the value it was set to just before
    // interrupts went away.
    oldTime1 = millis();
    oldTime2 = millis();
    
    // Divide the flow rate in litres/minute by 60 to determine how many litres have
    // passed through the sensor in this 1 second interval, then multiply by 1000 to
    // convert to millilitres.
    flowMilliLitres1 = (flowRate1 / 60) * 1000;
    
    // Add the millilitres passed in this second to the cumulative total
    totalMilliLitres1 += flowMilliLitres1;
     flowMilliLitres2 = (flowRate2 / 60) * 1000;
    
    // Add the millilitres passed in this second to the cumulative total
    totalMilliLitres2 += flowMilliLitres2;
      
    unsigned int frac1;
    unsigned int frac2;
    
    // Print the flow rate for this second in litres / minute
    Serial.print("Flow rate: ");
    Serial.print(int(flowRate1));  // Print the integer part of the variable
    Serial.print("L/min");
    Serial.print("\t");       // Print tab space
    Serial.print(int(flowRate2));  // Print the integer part of the variable
    Serial.print("L/min");
    Serial.print("\t");

    // Print the cumulative total of litres flowed since starting
    Serial.print("Quantity1: ");        
    Serial.print(totalMilliLitres1);
    Serial.println("mL"); 
    Serial.print("\t");       // Print tab space
    Serial.print(totalMilliLitres2);
    Serial.println("mL"); 
    Serial.print("\t");       
  Serial.print(totalMilliLitres1/1000);
  Serial.print("L\n");
  Serial.print(totalMilliLitres2/1000);
   Serial.print("L\n");
    

    // Reset the pulse counter so we can start incrementing again
    pulseCount1 = 0;
    pulseCount2 = 0;
    // Enable the interrupt again now that we've finished sending output
    attachInterrupt(sensorInterrupt1, pulseCounter1, FALLING);
  attachInterrupt(sensorInterrupt2, pulseCounter2, FALLING);

  }
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
