const int EchoPin = 11;
const int TrigPin = 8;                        
const int L1 = 2;
const int L2 = 4;
const int R1 = 12;
const int R2 = 13;
const int ena = 9;
const int enb = 3;
int baz = 7;
void setup() {
   pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  Serial.begin(9600);
  pinMode(baz,OUTPUT);
}
long Duration, Distance;

void loop() {

  digitalWrite(TrigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH); 
  delayMicroseconds(5);
  digitalWrite(TrigPin, LOW);
  Duration = pulseIn(EchoPin, HIGH);  
  Distance = ((Duration*0.034)/2);


  if(Distance<=25){
    digitalWrite(baz,HIGH);
  analogWrite(ena,70);
  analogWrite(enb,90);
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
  digitalWrite(R1, LOW);
  digitalWrite(R2, HIGH);
  //delay(500);
  }

   /*if(Distance<30){
  analogWrite(ena,70);
  analogWrite(enb,80);
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
  digitalWrite(R1, LOW);
  digitalWrite(R2, HIGH);
  delay(500);
  }*/

   else {
    digitalWrite(baz,LOW);
    delay(500);
  analogWrite(ena,70);
  analogWrite(enb,90);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
  //delay(500);
  }


  
}
