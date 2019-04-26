
void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  pinMode(4, INPUT);

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
    digitalWrite(8, HIGH);// put your main code here, to run repeatedly:
    Serial.print("relay on");
  }
  else  if ((a==LOW)&&(b==LOW)&&(c==HIGH)&&(d==LOW)){
    digitalWrite(8, HIGH);// put your main code here, to run repeatedly:
    Serial.print("relay on");
  }
  else {digitalWrite(8, LOW);
  Serial.print("relay off"); }

}
