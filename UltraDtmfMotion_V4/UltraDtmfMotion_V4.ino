
#define R11 11
#define R12 10
#define L11 9
#define L12 8

#define D0 4
#define D1 5
#define D2 6
#define D3 7

#define echopin A5
#define trig A4

void setup() {
 Serial.begin(9600);
 pinMode(D0, INPUT);
 pinMode(D1, INPUT);
 pinMode(D2, INPUT);
 pinMode(D3, INPUT);

  
 pinMode(R11, OUTPUT);
 pinMode(R12, OUTPUT);
 pinMode(L11, OUTPUT);
 pinMode(L12, OUTPUT);

 pinMode(A5, INPUT);
 pinMode(A4, OUTPUT); //trig

}

void loop(){
int temp0=digitalRead(D0);
int temp1=digitalRead(D1);
int temp2=digitalRead(D2);
int temp3=digitalRead(D3);

digitalWrite(A4, LOW);
delayMicroseconds(2);
digitalWrite(A4, HIGH);
delayMicroseconds(10);
digitalWrite(A4, LOW);
float distance=pulseIn(A5,HIGH);
distance=distance/58;
Serial.print(distance);
Serial.print("CM\n");

if ((temp0==LOW)&&(temp1==HIGH)&&(temp2==LOW)&&(temp3==LOW)&&(distance<20))
  stopfn();

else if ((temp0==LOW)&&(temp1==HIGH)&&(temp2==LOW)&&(temp3==LOW)&&(distance>=20))
  fwd();
 
else if((temp0==LOW)&&(temp1==LOW)&&(temp2==HIGH)&&(temp3==LOW))
  left();
else if((temp0==HIGH)&&(temp1==LOW)&&(temp2==HIGH)&&(temp3==LOW))
  stopfn();
else if((temp0==LOW)&&(temp1==HIGH)&&(temp2==HIGH)&&(temp3==LOW))
  right();
else if((temp0==LOW)&&(temp1==LOW)&&(temp2==LOW)&&(temp3==HIGH))
  bwd();
else stopfn();
}


void fwd() {
  digitalWrite(R11, HIGH);
  digitalWrite(R12, LOW);
  digitalWrite(L11, HIGH);
  digitalWrite(L12, LOW);
}

void bwd() {
  digitalWrite(R11, LOW);
  digitalWrite(R12, HIGH);
  digitalWrite(L11, LOW);
  digitalWrite(L12, HIGH);
}

void left() {
  digitalWrite(R11, HIGH);
  digitalWrite(R12, LOW);
  digitalWrite(L11, LOW);
  digitalWrite(L12, HIGH);
}

void right() {
  digitalWrite(R11, LOW);
  digitalWrite(R12, HIGH);
  digitalWrite(L11, HIGH);
  digitalWrite(L12, LOW);
}

void stopfn() {
  digitalWrite(R11, LOW);
  digitalWrite(R12, LOW);
  digitalWrite(L11, LOW);
  digitalWrite(L12, LOW);
}
