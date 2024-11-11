#include <BasicBLDC.h>

BasicBLDC BLDC;

int sta=0, LR=0;
int v1=0, v2=0;
bool dnum=0, sto=0;
int x;
void setup() {
  BLDC.initialized();
  Serial.begin(500000);
  delay(1000);
}

void loop() {
 int L1=analogRead(0);
 int L0=analogRead(1);
 int C1=analogRead(2);
 int C0=analogRead(3);
 int R0=analogRead(8);
 int R1=analogRead(9);

  
      if (L1<100) { sta=1;  }
 else if (R1<100) { sta=5;   }
 else if (L0<100) { sta=2;  }
 else if (R0<100) { sta=4;   }
 else if (C0<100) { sta=3;    }
 else { sta=0; }

 
        if ( (L1<100)&&(R1<100) ) {  }
   else if ( L1<100  ) {LR=1;}
   else if ( R1<100  ) {LR=2;}
    
 
 if (sta==3) { v1=120; v2=120;   }
 else if (sta==2) { v1=105; v2=95;  }
 else if (sta==4) { v1=95; v2=105;  }
 else if (sta==1) { v1=50; v2=0; }
 else if (sta==5) { v1=0; v2=50; }
 else if (sta==0) { if (LR!=0){
                      motor(-90,-90); delay(100);  
                           if (LR==2) {v1=-40; v2=0; }
                      else if (LR==1) {v1=0; v2=-40; } 
                      int pp=0; motor(v2,v1); 
                      while(pp==0) { if (analogRead(9)<100) {pp=1;}
                                     else if (analogRead(0)<100) {pp=1;}}
                      motor(-v2,-v1); delay(200);
                      motor(0,0);  delay(100);  
                          if (LR==2) {v1=0; v2=10; }
                      else if (LR==1) {v1=10; v2=0; }
                       LR=0;
                     }
 
                    }
 
 
              
 motor(v2 ,v1 );
 delay(1);

}


void motor(int vv1, int vv2)
{  bool d1=0, d2=0;
   if (vv1<0) {vv1=abs(vv1); d1=1;}//
   if (vv2<0) {vv2=abs(vv2); d2=1;}//
   BLDC.control(d1,vv1 ,d2,vv2 );  //
}
