#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial mySerial(0, 1); //블루투스의 Tx, Rx핀을 2번 3번핀으로 설정
Servo servo;

int vibr_Pin = 5; // 진동센서 5번 핀
int servoPin = 9; // 서보모터 9번 핀
int angle = 90; // 서보 기본 각도 90 
int M=1;
int redPin = 8; // Red핀
int greenPin = 7; // Green핀
int bluePin = 6; // Blue핀
int data;

void setup() {
  // 시리얼 통신의 속도를 9600으로 설정
  Serial.begin(9600);
  pinMode(vibr_Pin, INPUT); // 진동센서 출력
  pinMode(redPin, OUTPUT); // Red핀 출력
  pinMode(greenPin, OUTPUT); // Green핀 출력
  pinMode(bluePin, OUTPUT);  // Blue핀 출력
  servo.attach(servoPin); 
  while (!Serial) {
    ; //시리얼통신이 연결되지 않았다면 코드 실행을 멈추고 무한 반복
  }
  Serial.println("Hello World!");
  //블루투스와 아두이노의 통신속도를 9600으로 설정
  mySerial.begin(9600);
}
void motor(char M1,int M2,char M3,int M4){ // 모터
  digitalWrite(12, M1);
  analogWrite(10, M2);
  digitalWrite(13, M3);
  analogWrite(11, M4);
}

void loop() { //코드를 무한반복합니다.
  motor(HIGH,255,LOW,100);
  delay(1000);
}
