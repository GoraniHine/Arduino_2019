char M1,M3;
int M2,M4;

void setup(){
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  void motored(M1,M2,M3,M4){
    digitalWrite(4, M1);
    analogWrite(5, M2);
    digitalWrite(7, M3);
    analogWrite(6, M4);
}
}
void loop(){
  Gofront();
  delay(1000);
  Goback();
  delay(1000);
  Left();
  delay(1000);
  Right();
  delay(1000);
  BigLeft();
  delay(500);
  BigRight();
  delay(500);
}
void Gofront(HIGH,70,LOW,70){
    motored(M1,M2,M3,M4);
}
void Goback(LOW,70,HIGH,70){
    motored(M1,M2,M3,M4);
}
void Left(HIGH,0,HIGH,70){
    motored(M1,M2,M3,M4);
}
void Right(LOW,70,HIGH,0){
    motored(M1,M2,M3,M4);
}
void BigLeft(HIGH,70,LOW,100){
    motored(M1,M2,M3,M4);
}
void BigRight(HIGH,100,LOW,70){
    motored(M1,M2,M3,M4);
}
