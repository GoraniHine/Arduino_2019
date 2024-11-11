int joystick_x = A0;    
int joystick_y = A1;
int joystick_z = 2;    //조이스틱 X,Y,Z축을 저장

void setup()
{
 pinMode(joystick_z,INPUT_PULLUP);    // Z를 입력모드로
 Serial.begin(9600);               // 시리얼 통신을, 9600속도로 받습니다. (숫자 조정은 자유)
}

void loop()
{
 int x = analogRead(joystick_x);      // 조이스틱 X축의 아날로그 신호를 x에 저장
 int y = analogRead(joystick_y);      // 조이스틱 Y축의 아날로그 신호를 y에 저장
 int z = digitalRead(joystick_z);     // 조이스틱 Z축의 아날로그 신호를 z에 저장 
  Serial.print("X: ");                   
  Serial.print(x);                          //시리얼 모니터에 'X: x값'을 표기
  Serial.print("  Y: ");
  Serial.print(y);                          //시리얼 모니터에 '  Y: y값'을 표기
  Serial.print("  Z: ");
 Serial.println(z);                         //시리얼 모니터에 '  Z: z값'을 표기하고 줄넘김
delay(100);                                  // 100만큼 지연
} 
