void setup(){
  Serial.begin(9600);
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
}
void Gofront(){
    digitalWrite(4, HIGH);
    analogWrite(5, 255);
    digitalWrite(2, HIGH);
    analogWrite(3, 255);
}
void Goback(){
    digitalWrite(4, LOW);
    analogWrite(5, 255);
    digitalWrite(2, LOW);
    analogWrite(3, 255);
}
void Left(){
    digitalWrite(4, HIGH);
    analogWrite(5, 0);
    digitalWrite(2, LOW);
    analogWrite(3, 255);
}
void Right(){
    digitalWrite(4, LOW);
    analogWrite(5, 255);
    digitalWrite(2, HIGH);
    analogWrite(3, 0);
}
