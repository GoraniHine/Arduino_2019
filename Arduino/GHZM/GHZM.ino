#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1); // 블루투스의 Tx, Rx핀을 2번 3번핀으로 
// 디지털 2번부터 8번까지 버튼으로 사용, 아날로그 0번과 1번은 조이스틱으로 사용

const byte PIN_BUTTON_RIGHT = 3;
const byte PIN_BUTTON_UP = 2;
const byte PIN_BUTTON_LEFT = 5;
const byte PIN_ANALOG_X = A0;
const byte PIN_ANALOG_Y = A1;
int x,y,L,R,U;
void setup() 
{ 
  Serial.begin(9600);
  mySerial.begin(9600);
  
  pinMode(PIN_BUTTON_RIGHT, INPUT);  
  digitalWrite(PIN_BUTTON_RIGHT, HIGH);
  
  pinMode(PIN_BUTTON_LEFT, INPUT);  
  digitalWrite(PIN_BUTTON_LEFT, HIGH);
  
  pinMode(PIN_BUTTON_UP, INPUT);  
  digitalWrite(PIN_BUTTON_UP, HIGH);
  
  Serial.println("System On!");
 
  delay(10);
 }

void loop() 
{ 
  int data,sum;
  
  x = analogRead(PIN_ANALOG_X);      // 조이스틱 X축의 아날로그 신호를 x에 저장
  y = analogRead(PIN_ANALOG_Y);      // 조이스틱 Y축의 아날로그 신호를 y에 저장
  R = analogRead(PIN_BUTTON_RIGHT);
  L = analogRead(PIN_BUTTON_LEFT);
  U = analogRead(PIN_BUTTON_UP);
  
  if(600>x && x>400 && 600>y && y>400)
   {data=10; delay(1);}
  else if(400>x && y>600)
   {data=20;delay(1);}
  else if(600>x && x>400 && y>600)
   {data=30;delay(1);} 
  else if(x>600 && y>600)
   {data=40;delay(1);}
  else if(400>x && 600>y && y>400)
   {data=50;delay(1);}
  else if(x>600 && 600>y && y>400)
   {data=60;delay(1);}
  else if(400>x && 400>y)
   {data=70;delay(1);}
  else if(600>x && x>400 && 400>y)
   {data=80;delay(1);}
  else if(x>600 && 400>y)
   {data=90;delay(1);}
  
  if(digitalRead(PIN_BUTTON_UP)==0){data+=4;delay(1);}
  else if(digitalRead(PIN_BUTTON_LEFT)==1 && digitalRead(PIN_BUTTON_RIGHT)==1){data+=1;delay(1);}
  else if(digitalRead(PIN_BUTTON_LEFT)==0 && digitalRead(PIN_BUTTON_RIGHT)==1){data+=2;delay(1);} 
  else if(digitalRead(PIN_BUTTON_LEFT)==1 && digitalRead(PIN_BUTTON_RIGHT)==0){data+=3;delay(1);}  
  
  mySerial.write(data);
  Serial.print(data); 
  Serial.println();
      
  delay(100);
}
