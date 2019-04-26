
void setup() {
  Serial.begin(9600);
  pinMode(5, INPUT);
  pinMode(4, INPUT);
  pinMode(3, INPUT);
  pinMode(2, INPUT);

  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  
  // put your setup code here, to run once:

}

void loop() {
  int a=0;
  int b=0;
  int c=0;
  int d=0;
  a=digitalRead(7);
  b=digitalRead(6);
  c=digitalRead(5);
  d=digitalRead(4);
  
  if ((a==LOW)&&(b==HIGH)&&(c==LOW)&&(d==LOW)){
   forward();
   Serial.print("\n 2");
  }
  else  if ((a==LOW)&&(b==LOW)&&(c==HIGH)&&(d==LOW)){
    left();
    Serial.print("\n 4");
  }
  else  if ((a==HIGH)&&(b==LOW)&&(c==HIGH)&&(d==LOW)){
  stopfn();
  Serial.print("\n 5");

}

else  if ((a==LOW)&&(b==HIGH)&&(c==HIGH)&&(d==LOW)){
    right();
    Serial.print("\n 6");

}

else  if ((a==LOW)&&(b==LOW)&&(c==LOW)&&(d==HIGH)){
    backd();
    Serial.print("\n 8");

} }
void forward(){
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  
}

void backd(){
digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
 
  
}

void right(){
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  
}

void left(){
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  
}
void stopfn(){
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  
}
