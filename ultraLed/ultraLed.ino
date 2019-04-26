#define echopin A5
#define trig A4
#define LED1 3
#define LED2 4
#define LED3 5
#define LED4 6
#define LED5 7
void setup() {
  Serial.begin(9600);
  pinMode(A5, INPUT);
  pinMode(A4, OUTPUT); //trig
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
}

void loop() {
digitalWrite(A4, LOW);
delayMicroseconds(2);
digitalWrite(A4, HIGH);
delayMicroseconds(10);
digitalWrite(A4, LOW);
// calc
float distance=pulseIn(A5,HIGH);
distance=distance/58;
Serial.print(distance);
Serial.println(" cm");
if((distance>2300)||(distance<30)){
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,LOW);
}
else if((distance>=30)&&(distance<40)){
  digitalWrite(LED2,HIGH);
  digitalWrite(LED1,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,LOW);
}
else if((distance>=40)&&(distance<60)){
  digitalWrite(LED3,HIGH);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,LOW);
}
else if((distance>=60)&&(distance<100)){
  digitalWrite(LED4,HIGH);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED5,LOW);
}
else // if((distance>=100)&&(distance<300))
{
  digitalWrite(LED5,HIGH);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
}


delay(200);

}
