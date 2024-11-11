#include <SoftwareSerial.h>
SoftwareSerial mySerial(0, 1); //블루투스의 Tx, Rx핀을 2번 3번핀으로 설정
int data,value;
void setup() {
  // 시리얼 통신의 속도를 9600으로 설정
  Serial.begin(9600);
  Serial.println("Hello World!");
  pinMode(5,OUTPUT);
  //블루투스와 아두이노의 통신속도를 9600으로 설정
  mySerial.begin(9600);
}
void loop() { //코드를 무한반복합니다.
  if(Serial.available())
  {
    char ch =Serial.read();
    if(isDigit(ch))
    {
      value = (value * 10) + (ch - 48);
    }
    else if (ch =='\n')
    {
        Serial.println(value);
        delay(100);
        value = 0;
    }
    if(value==31){digitalWrite(5,HIGH);delay(10);}
  } 
}
