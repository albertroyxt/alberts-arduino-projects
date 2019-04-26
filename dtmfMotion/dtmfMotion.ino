
#define R11 11
#define R12 10
#define L11 9
#define L12 8

#define D0 7
#define D1 6
#define D2 5
#define D3 4

void setup() {
 pinMode(D0, INPUT);
 pinMode(D1, INPUT);
 pinMode(D2, INPUT);
 pinMode(D3, INPUT);

  
 pinMode(R11, OUTPUT);
 pinMode(R12, OUTPUT);
 pinMode(L11, OUTPUT);
 pinMode(L12, OUTPUT);
}

void loop(){
int temp0=digitalRead(D0);
int temp1=digitalRead(D1);
int temp2=digitalRead(D2);
int temp3=digitalRead(D3);

if((temp0==LOW)&&(temp1==HIGH)&&(temp2==LOW)&&(temp3==LOW))
  fwd();
else if((temp0==LOW)&&(temp1==LOW)&&(temp2==HIGH)&&(temp3==LOW))
  left();
else if((temp0==HIGH)&&(temp1==LOW)&&(temp2==HIGH)&&(temp3==LOW))
  stopfn();
else if((temp0==LOW)&&(temp1==HIGH)&&(temp2==HIGH)&&(temp3==LOW))
  right();
else if((temp0==LOW)&&(temp1==LOW)&&(temp2==LOW)&&(temp3==HIGH))
  bwd();
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

void right() {
  digitalWrite(R11, HIGH);
  digitalWrite(R12, LOW);
  digitalWrite(L11, LOW);
  digitalWrite(L12, HIGH);
}

void left() {
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
