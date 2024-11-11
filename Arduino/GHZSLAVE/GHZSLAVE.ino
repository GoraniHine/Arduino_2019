#include <SoftwareSerial.h>
#include <Servo.h> 

SoftwareSerial mySerial(1, 0); //블루투스의 Tx, Rx핀을 0번 1번핀으로 설정
Servo servo;

int vibr_Pin =5; // 진동센서 5번 핀
int servoPin = 9; // 서보모터 9번 핀
int angle = 90; // 서보 기본 각도 90 
int x,y;
int M=1;
int PIN_BUTTON_SELECT; // S
int PIN_BUTTON_RIGHT; // R
int PIN_BUTTON_UP; // U
int PIN_BUTTON_DOWN; //D
int PIN_BUTTON_LEFT; // L
int PIN_ANALOG_X;
int PIN_ANALOG_Y;

int redPin = 11; // Red핀
int greenPin = 10; // Green핀
int bluePin = 9; // Blue핀

void setup(){
  Serial.println("System On!");
  pinMode(vibr_Pin, INPUT); // 진동센서 출력
  pinMode(redPin, OUTPUT); // Red핀 출력
  pinMode(greenPin, OUTPUT); // Green핀 출력
  pinMode(bluePin, OUTPUT);  // Blue핀 출력
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop(){
  
  if (Serial.available()) {    // 시리얼모니터에 입력된 데이터가 있다면
    mySerial.write(Serial.read());  // 블루투스를 통해 입력된 데이터 전달
 }
  if (mySerial.available()) { // 블루투스에서 넘어온 데이터가 있다면
  Serial.write(mySerial.read()); // 시리얼모니터에 데이터를 출력
 } 
 if(M=1){Normal();}
 else{Hurt();}
 if(digitalRead(PIN_BUTTON_UP)){M=1;}
}

void motor(char M1,int M2,char M3,int M4){ // 모터
  digitalWrite(12, M1);
  analogWrite(10, M2);
  digitalWrite(13, M3);
  analogWrite(11, M4);
}

long TP_init(){ // 진동센서
  delay(10);
  long measurement=pulseIn (vibr_Pin, HIGH);  // 핀이 HIGH가 될 때까지 기다렸다가 측정 값을 반환합니다
  return measurement;
}

void setColor(int red, int green, int blue) // RGB 컬러
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue); 
}
void Normal()
{
 long measurement =TP_init(); // 진동센서 함수(가서 측정해보기)
 Serial.print("measurment = ");
 Serial.println(measurement);
 
 setColor(0, 255, 0); // 초록색 눈
 if(measurement>1000)
 {setColor(255, 0, 0); M=2;} // 빨간색 눈, 정지
 
 if(digitalRead(PIN_BUTTON_RIGHT)) // 우버튼
 {
  angle++;
  servo.write(angle);
 }
 
 if(digitalRead(PIN_BUTTON_LEFT))
 {
  angle--;
  servo.write(angle);
 }
 
 if(x>400) // 로봇의 다리
 {
  motor(HIGH,70,LOW,0); // 왼쪽
 }
 else if(x<300)
 {
  motor(HIGH,0,LOW,70); // 오른쪽 
 }
 else
 {
 delay(1); // 가만히
 }
   
 if(y>400)
 {
  motor(HIGH,70,LOW,70); // 앞으로
 }
 else if(y<300)
 {
  motor(LOW,70,HIGH,70); // 뒤로
 }
 else
 {
 delay(1); // 가만히
 } 
}
void Hurt()
{
  setColor(255, 255, 0); // 노란색 눈
}
