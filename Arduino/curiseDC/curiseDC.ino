int distance;
int triggerPin = 8;
int echoPin = 7;

void setup(){
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(triggerPin,OUTPUT);
  pinMode(echoPin,INPUT);
}
void loop(){
  digitalWrite(triggerPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin,LOW);
  distance = pulseIn(echoPin,HIGH)/58;
  Serial.print("Distance(cm) = ");
  Serial.println(distance);
  if(distance == 10)
  {
    stoped();
  }
  else if(distance > 10)
  {   
    Gofront();
  }
  else
  {
    Goback();
  }  
}
void Gofront(){
    digitalWrite(4, HIGH);
    analogWrite(5, 255);
    digitalWrite(7, HIGH);
    analogWrite(6, 255);
}
void Goback(){
    digitalWrite(4, LOW);
    analogWrite(5, 255);
    digitalWrite(7, LOW);
    analogWrite(6, 255);
}
void stoped(){
    digitalWrite(4, HIGH);
    analogWrite(5, 0);
    digitalWrite(7, HIGH);
    analogWrite(6, 0);
}
