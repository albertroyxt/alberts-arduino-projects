#include <Servo.h>
Servo LB1,LH1,LB2,LH2,LB3,LH3;
Servo RB1,RH1,RB2,RH2,RB3,RH3;
int RHUP=20;
int LHUP=160;
int RBmax=70;
int LBmax=110;
int RBmin=110;
int LBmin=70;
int D0=0,D1=0,D2=0,D3=0;
int startupcheck=0;

void setup() {
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, OUTPUT);
 LB1.attach(2);
 LH1.attach(3);
 LB2.attach(4);
 LH2.attach(5);
 LB3.attach(6);
 LH3.attach(7);
 RB1.attach(8);
 RH1.attach(9);
 RB2.attach(10);
 RH2.attach(11);
 RB3.attach(12);
 RH3.attach(13);
}

void loop() {
  if(startupcheck==0){
    defaultfn();
    startupcheck=1; 
  
  } /*
  D0=digitalRead(A1);
  D1=digitalRead(A2);
  D2=digitalRead(A3);
  D3=digitalRead(A4); 

 /* 
  D3      |  D2     |    D1    |    D0    |  Action
  --------------------------------------------------
  0       |  0      |    0     |     1    | Forward
  0       |  0      |    1     |     0    | Right
  0       |  0      |    1     |     1    | Left
  0       |  1      |    0     |     0    | Reverse
  0       |  1      |    1     |     1    | Stop 
  
  
 
  if((D3==LOW)&&(D2==LOW)&&(D1==LOW)&&(D0==HIGH))
  forward();
  else if((D3==LOW)&&(D2==LOW)&&(D1==HIGH)&&(D0==LOW))
  right();
   else if((D3==LOW)&&(D2==LOW)&&(D1==HIGH)&&(D0==HIGH))
  left();
   else if((D3==LOW)&&(D2==HIGH)&&(D1==LOW)&&(D0==LOW))
  backwrd();
  else if((D3==LOW)&&(D2==HIGH)&&(D1==HIGH)&&(D0==HIGH))
  stopfn(); 
  else defaultfn(); */
  else forward();
}


void forward(){

  RH1.write(RHUP);
  LH2.write(LHUP);
  delay(700);
  RB1.write(RBmax);
  LB2.write(LBmax);
  delay(700);
  RH1.write(90);
  LH2.write(90);
  delay(700);


  RH3.write(RHUP);
  LH1.write(LHUP);
  delay(700);
  RB3.write(RBmax);
  LB1.write(LBmax);
  delay(700);
  RH3.write(90);
  LH1.write(90);
  delay(700);



  RH2.write(RHUP);
  LH3.write(LHUP);
  delay(700);
  RB2.write(RBmax);
  LB3.write(LBmax);
  delay(700);
  RH2.write(90);
  LH3.write(90);
  delay(700);

  RB1.write(RBmin);
  LB2.write(LBmin);
  RB3.write(RBmin);
  LB1.write(LBmin);
  RB2.write(RBmin);
  LB3.write(LBmin);
  delay(700);
}

void backwrd(){

  RH1.write(RHUP);
  LH2.write(LHUP);
  delay(700);
  RB1.write(RBmax);
  LB2.write(LBmax);
  delay(700);
  RH1.write(90);
  LH2.write(90);
  delay(700);


  RH3.write(RHUP);
  LH1.write(LHUP);
  delay(700);
  RB3.write(RBmax);
  LB1.write(LBmax);
  delay(700);
  RH3.write(90);
  LH1.write(90);
  delay(700);



  RH2.write(RHUP);
  LH3.write(LHUP);
  delay(700);
  RB2.write(RBmax);
  LB3.write(LBmax);
  delay(700);
  RH2.write(90);
  LH3.write(90);
  delay(700);

  RB1.write(RBmin);
  LB2.write(LBmin);
  RB3.write(RBmin);
  LB1.write(LBmin);
  RB2.write(RBmin);
  LB3.write(LBmin);
  delay(700);
}
void stopfn(){

  RH1.write(RHUP);
  LH2.write(LHUP);
  delay(700);
  RB1.write(90);
  LB2.write(90);
  delay(700);
  RH1.write(90);
  LH2.write(90);
  delay(700);


  RH3.write(RHUP);
  LH1.write(LHUP);
  delay(700);
  RB3.write(90);
  LB1.write(90);
  delay(700);
  RH3.write(90);
  LH1.write(90);
  delay(700);



  RH2.write(RHUP);
  LH3.write(LHUP);
  delay(700);
  RB2.write(90);
  LB3.write(90);
  delay(700);
  RH2.write(90);
  LH3.write(90);
  delay(700);
}


void left(){

  RH1.write(RHUP);
  LH2.write(LHUP);
  delay(700);
  RB1.write(RBmin);
  LB2.write(LBmax);
  delay(700);
  RH1.write(90);
  LH2.write(90);
  delay(700);


  RH3.write(RHUP);
  LH1.write(LHUP);
  delay(700);
  RB3.write(RBmin);
  LB1.write(LBmax);
  delay(700);
  RH3.write(90);
  LH1.write(90);
  delay(700);



  RH2.write(RHUP);
  LH3.write(LHUP);
  delay(700);
  RB2.write(RBmin);
  LB3.write(LBmax);
  delay(700);
  RH2.write(90);
  LH3.write(90);
  delay(700);

  RB1.write(RBmax);
  LB2.write(LBmin);
  RB3.write(RBmax);
  LB1.write(LBmin);
  RB2.write(RBmax);
  LB3.write(LBmin);
  delay(700);
}


void right(){

  RH1.write(RHUP);
  LH2.write(LHUP);
  delay(700);
  RB1.write(RBmax);
  LB2.write(LBmin);
  delay(700);
  RH1.write(90);
  LH2.write(90);
  delay(700);


  RH3.write(RHUP);
  LH1.write(LHUP);
  delay(700);
  RB3.write(RBmax);
  LB1.write(LBmin);
  delay(700);
  RH3.write(90);
  LH1.write(90);
  delay(700);



  RH2.write(RHUP);
  LH3.write(LHUP);
  delay(700);
  RB2.write(RBmax);
  LB3.write(LBmin);
  delay(700);
  RH2.write(90);
  LH3.write(90);
  delay(700);

  RB1.write(RBmin);
  LB2.write(LBmax);
  RB3.write(RBmin);
  LB1.write(LBmax);
  RB2.write(RBmin);
  LB3.write(LBmax);
  delay(700);
}
void defaultfn(){
  RB1.write(90);
  LB2.write(90);
    delay(700);
  RB3.write(90);
  LB1.write(90);
    delay(700);
  RB2.write(90);
  LB3.write(90);
  delay(700);
  RH1.write(90);
  LH2.write(90);
    delay(700);
  RH3.write(90);
  LH1.write(90);
    delay(700);
  RH2.write(90);
  LH3.write(90);
  delay(2000);
}

