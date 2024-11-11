#include <Servo.h> 

int joystick_x = A0;    
int joystick_y = A1;
int joystick_z = 2;
int servoPin = 9;
int angle = 0;
Servo servo;
void setup() 
{ 
    servo.attach(servoPin); 
    pinMode(joystick_z,INPUT_PULLUP);    
    Serial.begin(9600);
} 
void loop()
{
 int x = analogRead(joystick_x);      // 조이스틱 X축의 아날로그 신호를 x에 저장
 Serial.print("X: ");                   
 Serial.print(x  );                          //시리얼 모니터에 'X: x값'을 표기
 if(x>400)
 {
  angle++;
  servo.write(angle);
  delay(15);
 }
 else if(x<300)
 {
  angle--;
  servo.write(angle);
  delay(15);
 }
 else
 {
 delay(15);
 }  
 Serial.print("  angle: "); 
 Serial.println(angle); 
 delay(15);
} 
