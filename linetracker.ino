/*
this program will make the car track the line
*/
int R_s = A0;// defining the pins
int M_s = A1;// defining the pins
int L_s = A2;// defining the pins
int R;//  setting up the sensor values for right sensor
int M;//  setting up the sensor values for middle sensor
int L;//  setting up the sensor values for left sensor

#define MotorA 7 //defining pins for motor
#define MotorA_Speed 5//defining pins for speed
#define MotorB 8//defining pins for motor
#define MotorB_Speed 6//defining pins for speed
int F1_t = 2000 ; //time delay
int F2_t = 2000 ; //time delay
int R1_t = 1000 ; //time delay
int R2_t = 800 ; //time delay

void setup() {
  Serial.begin(9600);
for (int i=3; i<9; i++){//setting up the pins as outputs
  pinMode(i, OUTPUT);
  digitalWrite(3, 1);//stand by pin
}
}
void loop() {
  R = analogRead(R_s);//reads R sensor value
  M = analogRead(M_s);//reads M sensor value
  L = analogRead(L_s);//reads L sensor value

 if(M <= 200){
   Fwd(50);
 }
  else if(R<= 200 )
  {
    Rgt(50);
  }
   else if(R<= 200 && M <= 200) {
     RtFw(50);
     }
     else if(L<= 200 && M <= 200) {
     LtFw(50);
     }
 
    else if (M>=200){
   Rgt(50);
 }
}



void move(bool a, int b ,bool c, int d){// move function
  digitalWrite(MotorA, a);
   analogWrite(MotorA_Speed,b);


  digitalWrite(MotorB,c); 
  analogWrite(MotorB_Speed,d);
  }
// forward function
   void Fwd(int x){
  move(1,x,1,x);
  }
  // backward function
 void Bkw(int x){
  move(0,x,0,x);
  }
   // turn right 
 void Rgt(int x){
  move(0,x,1,x);
  }
//turn left
   void Lft(int x){
  move(1,x,0,x);
  }
//turn left forward
   void LtFw(int x){
  move(1,x/2,1,x);
  }

  //turn right forward
   void RtFw(int x){
  move(1,x,1,x/2);
  }

   //right backwards
   void RtBw(int x){
  move(0,x,0,x/2);
  }
//left backwards
     void LtBw(int x){
  move(0,x/2,0,x);
  }
   void Stp(int x){
  move(1,x,1,x);
  }  