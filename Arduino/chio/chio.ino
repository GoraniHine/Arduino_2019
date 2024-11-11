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
    digitalWrite(4, HIGH);
    analogWrite(5, 0);
  }
  else if(distance > 10)
  {   
    digitalWrite(4, HIGH);
    analogWrite(5, 255);
  }
  else
  {
    digitalWrite(4, LOW);
    analogWrite(5, 255);
  }  
}
