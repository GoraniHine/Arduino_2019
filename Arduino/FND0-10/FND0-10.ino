float state=0;
void setup(){
  Serial.begin(9600);
}
void loop()
{
  state=analogRead(A0);
  Serial.println(state);
  delay(1000);
  if(state<100)
  Serial.print(0);
  else if(state<300 && state>200)
  Serial.print((state)/120);
  else if(state<650 && state>300)
  Serial.print((state)/200);
  Serial.print("cm");
}
