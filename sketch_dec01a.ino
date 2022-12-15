
/*
this program will make the car move around the table while drifting
*/







#define MotorA 7 //defining pins for motor
#define MotorA_Speed 5//defining pins for speed
#define MotorB 8//defining pins for motor
#define MotorB_Speed 6//defining pins for speed
int F1_t = 2000 ; //time delay
int F2_t = 2000 ; //time delay
int R1_t = 1000 ; //time delay
int R2_t = 800 ; //time delay
void setup() {
  for (int i=3; i<9; i++){//setting up the pins as outputs
  pinMode(i, OUTPUT);
  digitalWrite(3, 1);//stand by pin
}


}
void loop() {

  Fwd(255);//car forward at max speed
  delay(F1_t);

  Drift_R();//drift to the right
  
  
  Fwd(255);//car forward at max speed
 delay(F2_t);

  Drift_R();//drift to the right

  
 Fwd(255);//car forward at max speed
 delay(F1_t);

  Rgt(255);// right turn
 delay(R1_t);
 

 

 
 Stp(0);//stop for 5 seconds
 delay(5000);
}


void move(bool a, int b ,bool c, int d){// move function
  digitalWrite(MotorA, a);
   analogWrite(MotorA_Speed,b);


  digitalWrite(MotorB,c); 
  analogWrite(MotorB_Speed,d);
  }
//Stop
 void Stp(int x){
  move(1,x,1,x);
  }  

// Go at x speed forward for wtver delay mentioned
 void Fwd(int x){
  move(1,x,1,x);
  }
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
//drift to the right
    void Drift_R(){
  Rgt(255);// the numbers were optimized for the best speed and delay to turn a 270 degrees turn
  delay (950);
  Fwd(180);
  delay(300);
  }
