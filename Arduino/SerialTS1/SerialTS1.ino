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
 if(C<100){sta=1;}
 else if(L2<100){sta=2;}
 else if(R1<100){sta=3;}
 else if(L1<100){sta=4; LR=1;}
 else if(R2<100){sta=5; LR=2;}
 if(sta==1){BLDC.control(0,100,0,100);}
 else if (sta==2){BLDC.control(0,0,0,77);}
 else if (sta==3){BLDC.control(0,76,0,0);}
 else if (sta==4){BLDC.control(0,50,0,44);}
 else if (sta==5){BLDC.control(0,42,0,50);}
 else {
  BLDC.control(1,250,1,250);
  delay(200);
  BLDC.control(0,0,0,0);
  delay(2000);
  if(LR==1){while(L2<100){BLDC.control(0,0,0,80);}}
  else if(LR==2){while(R1<100){BLDC.control(0,80,0,0);}}
  }
  Serial.println(LR);
 delay(3);
}
