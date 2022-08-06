#define W 1
#define B 0

#define in1 9
#define in2 8
#define in3 10
#define in4 11

int sen[8] = {0, 0, 0, 0, 0, 0, 0, 0};
//int track[8] = {0, 0, 0, 0, 0, 0, 0, 0};
//int i, sum=0;
//float avg;

#define ir0 12
#define ir1 13
#define ir2 2
#define ir3 3 
#define ir4 4
#define ir5 5
#define ir6 6
#define ir7 7

void setup() {
  
  pinMode(ir0,INPUT);
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  pinMode(ir3,INPUT);
  pinMode(ir4,INPUT);
  pinMode(ir5,INPUT);
  pinMode(ir6,INPUT);
  pinMode(ir7,INPUT);    

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  //Serial.begin(9600);
}

void loop() {
  
  sen[0] = digitalRead(ir0);
  sen[1] = digitalRead(ir1);
  sen[2] = digitalRead(ir2);
  sen[3] = digitalRead(ir3);
  sen[4] = digitalRead(ir4);
  sen[5] = digitalRead(ir5);
  sen[6] = digitalRead(ir6);
  sen[7] = digitalRead(ir7);

//  <-------------------------------------//FORWARD PART//------------------------------------->
   
       if(sen[0]==W&&sen[1]==W&&sen[2]==W&&sen[3]==B&&sen[4]==B&&sen[5]==W&&sen[6]==W&&sen[7]==W)
  moveForward();
  else if(sen[0]==W&&sen[1]==W&&sen[2]==W&&sen[3]==W&&sen[4]==W&&sen[5]==W&&sen[6]==W&&sen[7]==W)
  moveForward();


//  <-------------------------------------//GO LEFT PART//------------------------------------->
  
  else if(sen[0]==W&&sen[1]==W&&sen[2]==B&&sen[3]==B&&sen[4]==B  &&sen[5]==W&&sen[6]==W&&sen[7]==W)
  turnLeft();
  else if(sen[0]==W&&sen[1]==B&&sen[2]==B&&sen[3]==B&&sen[4]==B  &&sen[5]==W&&sen[6]==W&&sen[7]==W)
  turnLeft();
  else if(sen[0]==W&&sen[1]==B&&sen[2]==B&&sen[3]==B&&sen[4]==W  &&sen[5]==W&&sen[6]==W&&sen[7]==W)
  turnLeft();
  
  else if(sen[0]==B&&sen[1]==B&&sen[2]==B&&sen[3]==B&&sen[4]==B  &&sen[5]==W&&sen[6]==W&&sen[7]==W)
  turnSLeft();
  else if(sen[0]==B&&sen[1]==B&&sen[2]==B&&sen[3]==B&&sen[4]==W  &&sen[5]==W&&sen[6]==W&&sen[7]==W)
  turnSLeft();
  else if(sen[0]==B&&sen[1]==B&&sen[2]==W&&sen[3]==W&&sen[4]==W  &&sen[5]==W&&sen[6]==W&&sen[7]==W)
  turnSLeft();
  else if(sen[0]==B&&sen[1]==B&&sen[2]==B&&sen[3]==W&&sen[4]==W  &&sen[5]==W&&sen[6]==W&&sen[7]==W)
  turnSLeft();
  
//  <-------------------------------------//GO RIGHT PART//------------------------------------->
  
  else if(sen[0]==W&&sen[1]==W&&sen[2]==W  &&sen[3]==B&&sen[4]==B&&sen[5]==B&&sen[6]==W&&sen[7]==W)
  turnRight();
  else if(sen[0]==W&&sen[1]==W&&sen[2]==W  &&sen[3]==B&&sen[4]==B&&sen[5]==B&&sen[6]==B&&sen[7]==W)
  turnRight();
  else if(sen[0]==W&&sen[1]==W&&sen[2]==W  &&sen[3]==W&&sen[4]==B&&sen[5]==B&&sen[6]==B&&sen[7]==W)
  turnRight();

  
  else if(sen[0]==W&&sen[1]==W&&sen[2]==W  &&sen[3]==B&&sen[4]==B&&sen[5]==B&&sen[6]==B&&sen[7]==B)
  turnSRight();
  else if(sen[0]==W&&sen[1]==W&&sen[2]==W  &&sen[3]==W&&sen[4]==B&&sen[5]==B&&sen[6]==B&&sen[7]==B)
  turnSRight();
  else if(sen[0]==W&&sen[1]==W&&sen[2]==W  &&sen[3]==W&&sen[4]==W&&sen[5]==W&&sen[6]==B&&sen[7]==B)
  turnSRight();
  else if(sen[0]==W&&sen[1]==W&&sen[2]==W  &&sen[3]==W&&sen[4]==W&&sen[5]==B&&sen[6]==B&&sen[7]==B)
  turnSRight();
 // <-------------------------------------//REST NOW PART//------------------------------------->
  
  else if(sen[0]==B&&sen[1]==B&&sen[2]==B&&sen[3]==B&&sen[4]==B&&sen[5]==B&&sen[6]==B&&sen[7]==B)
  doStop();


}
void moveForward()
{ 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
 void turnLeft()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);
}
 void turnSLeft()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void turnRight()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnSRight()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void doStop()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);    
}
