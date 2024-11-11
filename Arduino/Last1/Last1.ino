#include <BasicBLDC.h> 
BasicBLDC BLDC;
int L1,L2,C,R1,R2;
int S=1;
int sta, LR=0;
int T;
int new_sta;
void setup() {
  BLDC.initialized();
  Serial.begin(9600);
  delay(1000);
}
void loop()
{
 L1=analogRead(0);
 L2=analogRead(1);
 C=analogRead(3);
 R1=analogRead(8);
 R2=analogRead(9);
 if((L1<100)&&(R2<100)){}
 else if(L1<100){LR=1;}
 else if(R2<100){LR=2;}
 if(C<100){BLDC.control(0,80,0,80);}
 else if (L2<100){BLDC.control(0,70,0,90);}
 else if (R1<100){BLDC.control(0,90,0,70);}
 else if (L1<100){BLDC.control(0,50,0,0);}
 else if (R2<100){BLDC.control(0,0,0,50);}
 else {
  BLDC.control(1,80,1,80);
  delay(150);
  BLDC.control(0,0,0,0);
  delay(2000);
  if(LR==1){while(L1>100){L1=analogRead(1);BLDC.control(1,10,0,0);}BLDC.control(0,40,0,0);delay(200);}
  else if(LR==2){while(R2>100){R2=analogRead(8);BLDC.control(0,0,1,10);}BLDC.control(0,0,0,40);delay(200);}
  BLDC.control(0,0,0,0);delay(20);}
  Serial.print(sta);Serial.print("  ");Serial.println(LR);
 delay(3);
}
