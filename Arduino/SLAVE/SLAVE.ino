#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial mySerial(0, 1); //블루투스의 Tx, Rx핀을 2번 3번핀으로 설정
Servo servo;

int vibr_Pin; // 진동센서 5번 핀
int servoPin = 9; // 서보모터 9번 핀
int angle = 90; // 서보 기본 각도 90 
int M=1;
int redPin = 11; // Red핀
int greenPin = 10; // Green핀
int bluePin = 9; // Blue핀
int led = 8;

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
  digitalWrite(4, M1);
  analogWrite(5, M2);
  digitalWrite(7, M3);
  analogWrite(6, M4);
}

void loop() { //코드를 무한반복합니다.
  if (mySerial.available()) { //블루투스에서 넘어온 데이터가 있다면
  int data = Serial.write(mySerial.read()); //시리얼모니터에 데이터를 출력
  Serial.println(data);
 
  if(data>10 && 20>data){    // 10번대
  motor(HIGH,0,LOW,0);
  if(data==12){angle++;}
  if(data==13){angle--;}
  }
  else if(data>20 && 30>data){    // 20번대
  motor(HIGH,255,LOW,150);
  if(data==22){angle++;}
  if(data==23){angle--;}
  }
  else if(data>30 && 40>data){    // 30번대
  motor(HIGH,150,LOW,150);
  if(data==32){angle++;}
  if(data==33){angle--;}
  }
  else if(data>40 && 50>data){    // 40번대
  motor(HIGH,150,LOW,255);
  if(data==42){angle++;}
  if(data==43){angle--;}
  }
  else if(data>50 && 60>data){    // 50번대
  motor(HIGH,150,LOW,0);
  if(data==52){angle++;}
  if(data==53){angle--;}
  }
  else if(data>60 && 70>data){    // 60번대
  motor(HIGH,0,LOW,150);
  if(data==62){angle++;}
  if(data==63){angle--;}
  }
  else if(data>70 && 80>data){    // 70번대
  motor(LOW,150,HIGH,255);
  if(data==72){angle++;}
  if(data==73){angle--;}
  }
  else if(data>80 && 90>data){    // 80번대
  motor(LOW,150,HIGH,150);
  if(data==82){angle++;}
  if(data==83){angle--;}
  }
  else if(data>90 && 100>data){    // 90번대
  motor(LOW,255,HIGH,150);
  if(data==92){angle++;}
  if(data==93){angle--;}
  }   
  
  servo.write(angle);
  }
}
