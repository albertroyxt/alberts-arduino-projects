#include <VirtualWire.h>
#include <VirtualWire_Config.h>

int TX_VCC = 2;
int TX_PIN = 3;// Tell Arduino on which pin you would like to Transmit data NOTE should be a PWM Pin
int TX_ID = 3; // Transmitter ID address

const int AOUTpin=0;//the AOUT pin of the alcohol sensor goes into analog pin A0 of the arduino
const int DOUTpin=8;//the DOUT pin of the alcohol sensor goes into digital pin D8 of the arduino
const int ledPin=13;//the anode of the LED connects to digital pin D13 of the arduino
int switchVal;
int limit;
int value;

struct roverRemoteData// Data Structure 
{
int    TX_ID;      // Initialize a storage place for the outgoing TX ID
int    Sensor1Data;// Initialize a storage place for the first integar that you wish to Send 
int    Sensor2Data;// Initialize a storage place for the Second integar that you wish to Send
int    Sensor3Data;// Initialize a storage place for the Third integar that you wish to Send
int    Sensor4Data;// Initialize a storage place for the Forth integar that you wish to Send


};

void setup() {
              Serial.begin(9600);// Begin Serial port at a Buad speed of 9600bps 
              vw_setup(2000);// Setup and Begin communication over the radios at 2000bps( MIN Speed is 1000bps MAX 4000bps)
              vw_set_tx_pin(TX_PIN);// Set Tx Pin

              pinMode(DOUTpin, INPUT);//sets the pin as an input to the arduino
              pinMode(TX_VCC, OUTPUT);
              digitalWrite(TX_VCC, HIGH);
              pinMode(ledPin, OUTPUT);//sets the pin as an output of the arduino

 
              }
void loop()
{

    value= analogRead(AOUTpin);//reads the analaog value from the alcohol sensor's AOUT pin
    limit= digitalRead(DOUTpin);//reads the digital value from the alcohol sensor's DOUT pin
    switchVal=0; //Need to define the value

  
  struct roverRemoteData payload;// In this section is where you would load the data that needs to be sent.
  
  // If you want to read a analog pin and transmit its value you can do it as follows by removing the "//" 
  payload.TX_ID = TX_ID; // Set the Radio Address 
  payload.Sensor1Data =0;//value;// analogRead(Sensor1Pin);
  payload.Sensor2Data =1;//limit;// analogRead(Sensor2Pin);
  payload.Sensor3Data =2;//switchVal;// analogRead(Sensor3Pin);
  payload.Sensor4Data =3;//1;// analogRead(Sensor4Pin);
 
  
  
  vw_send((uint8_t *)&payload, sizeof(payload)); // Send the data 
  vw_wait_tx();// Wait for all data to be sent 
  delay(1000);

}

