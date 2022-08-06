#define W 1
#define B 0

#define in1 9
#define in2 8
#define in3 10
#define in4 11
#define enr 5
#define enl 3

#define spd 170

int sen[9];

#define ir0 A0
#define ir1 A1
#define ir2 A2
#define ir3 A3 
#define ir4 A4
#define ir5 A5
#define ir6 6
#define ir7 7
#define ir 12

void setup() {

  pinMode(ir0,INPUT);
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  pinMode(ir3,INPUT);
  pinMode(ir4,INPUT);
  pinMode(ir5,INPUT);
  pinMode(ir6,INPUT);
  pinMode(ir7,INPUT);
  pinMode(ir,INPUT);

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(enl,OUTPUT);
  pinMode(enr,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(enl, spd);
  analogWrite(enr, spd);
  
  sen[0] = digitalRead(ir0);
  sen[1] = digitalRead(ir1);
  sen[2] = digitalRead(ir2);
  sen[3] = digitalRead(ir3);
  sen[4] = digitalRead(ir4);
  sen[5] = digitalRead(ir5);
  sen[6] = digitalRead(ir6);
  sen[7] = digitalRead(ir7);
  sen[8] = !digitalRead(ir);

//  <-------------------------------------//FORWARD PART//------------------------------------->
   

  if(sen[0]==B&&sen[1]==B&&sen[2]==B&&sen[3]==B&&sen[4]==B&&sen[5]==B&&sen[6]==B&&sen[7]==B&&sen[8]==W)
  {
    moveForward();
    Serial.println("02");
  }
 
//  <-------------------------------------//GO LEFT PART//------------------------------------->
  
  else if((sen[0]==B&&sen[1]==B&&sen[2]==B&&sen[3]==W&&sen[4]==W&&sen[5]==W&&sen[6]==W&&sen[7]==W
  )||(sen[0]==B&&sen[1]==B&&sen[2]==W&&sen[3]==W&&sen[4]==W&&sen[5]==W&&sen[6]==W&&sen[7]==W
  )||(sen[0]==B&&sen[1]==W&&sen[2]==B&&sen[3]==W&&sen[4]==W&&sen[5]==W&&sen[6]==W&&sen[7]==W
  )||(sen[0]==B&&sen[1]==W&&sen[2]==W&&sen[3]==W&&sen[4]==W&&sen[5]==W&&sen[6]==W&&sen[7]==W
  )||(sen[0]==W&&sen[1]==B&&sen[2]==B&&sen[3]==W&&sen[4]==W&&sen[5]==W&&sen[6]==W&&sen[7]==W
  )||(sen[0]==W&&sen[1]==B&&sen[2]==W&&sen[3]==W&&sen[4]==W&&sen[5]==W&&sen[6]==W&&sen[7]==W
  )||(sen[0]==W&&sen[1]==W&&sen[2]==B&&sen[3]==W&&sen[4]==W&&sen[5]==W&&sen[6]==W&&sen[7]==W
  
  )||(sen[0]==B&&sen[1]==B&&sen[2]==B&&sen[3]==B&&sen[4]==W&&sen[5]==W&&sen[6]==W&&sen[7]==W
  )||(sen[0]==B&&sen[1]==B&&sen[2]==B&&sen[3]==B&&sen[4]==B&&sen[5]==W&&sen[6]==W&&sen[7]==W
  
  )||(sen[0]==W&&sen[1]==B&&sen[2]==B&&sen[3]==B&&sen[4]==W&&sen[5]==W&&sen[6]==W&&sen[7]==W
  )||(sen[0]==W&&sen[1]==B&&sen[2]==B&&sen[3]==B&&sen[4]==B&&sen[5]==W&&sen[6]==W&&sen[7]==W
  )||(sen[0]==B&&sen[1]==B&&sen[2]==W&&sen[3]==W&&sen[4]==W&&sen[5]==W&&sen[6]==W&&sen[7]==W
  
  )||(sen[0]==W&&sen[1]==W&&sen[2]==B&&sen[3]==B&&sen[4]==W&&sen[5]==W&&sen[6]==W&&sen[7]==W
  )||(sen[0]==W&&sen[1]==B&&sen[2]==B&&sen[3]==B&&sen[4]==B&&sen[5]==B&&sen[6]==W&&sen[7]==W
  )||(sen[0]==B&&sen[1]==B&&sen[2]==B&&sen[3]==B&&sen[4]==B&&sen[5]==B&&sen[6]==W&&sen[7]==W

))
  {
    turnLeft();
    Serial.println("03");
  }



  
   else if((sen[0]==W&&sen[1]==W&&sen[2]==B&&sen[3]==B&&sen[4]==B&&sen[5]==W&&sen[6]==W&&sen[7]==W
  )||(sen[0]==W&&sen[1]==W&&sen[2]==W&&sen[3]==B&&sen[4]==B&&sen[5]==B&&sen[6]==W&&sen[7]==W
  )||(sen[0]==W&&sen[1]==W&&sen[2]==W&&sen[3]==B&&sen[4]==B&&sen[5]==W&&sen[6]==W&&sen[7]==W
  )||(sen[0]==W&&sen[1]==W&&sen[2]==B&&sen[3]==B&&sen[4]==B&&sen[5]==B&&sen[6]==W&&sen[7]==W
  ))
       {
  moveForward();
  Serial.println("01");
       }



  
//  <-------------------------------------//GO RIGHT PART//------------------------------------->
  
    else if((sen[0]==W&&sen[1]==W&&sen[2]==W&&sen[3]==W&&sen[4]==W&&sen[5]==B&&sen[6]==B&&sen[7]==B
    )||(sen[0]==W&&sen[1]==W&&sen[2]==W&&sen[3]==W&&sen[4]==W&&sen[5]==B&&sen[6]==B&&sen[7]==W
    )||(sen[0]==W&&sen[1]==W&&sen[2]==W&&sen[3]==W&&sen[4]==W&&sen[5]==B&&sen[6]==W&&sen[7]==B
    )||(sen[0]==W&&sen[1]==W&&sen[2]==W&&sen[3]==W&&sen[4]==W&&sen[5]==B&&sen[6]==W&&sen[7]==W
    )||(sen[0]==W&&sen[1]==W&&sen[2]==W&&sen[3]==W&&sen[4]==W&&sen[5]==W&&sen[6]==B&&sen[7]==B
    )||(sen[0]==W&&sen[1]==W&&sen[2]==W&&sen[3]==W&&sen[4]==W&&sen[5]==W&&sen[6]==B&&sen[7]==W
    )||(sen[0]==W&&sen[1]==W&&sen[2]==W&&sen[3]==W&&sen[4]==W&&sen[5]==W&&sen[6]==W&&sen[7]==B
    )||(sen[0]==W&&sen[1]==W&&sen[2]==W&&sen[3]==W&&sen[4]==W&&sen[5]==W&&sen[6]==W&&sen[7]==W

    )||(sen[0]==W&&sen[1]==W&&sen[2]==W&&sen[3]==W&&sen[4]==B&&sen[5]==B&&sen[6]==B&&sen[7]==B
    )||(sen[0]==W&&sen[1]==W&&sen[2]==W&&sen[3]==B&&sen[4]==B&&sen[5]==B&&sen[6]==B&&sen[7]==B

    )||(sen[0]==W&&sen[1]==W&&sen[2]==W&&sen[3]==B&&sen[4]==B&&sen[5]==B&&sen[6]==B&&sen[7]==W
    )||(sen[0]==W&&sen[1]==W&&sen[2]==W&&sen[3]==W&&sen[4]==B&&sen[5]==B&&sen[6]==B&&sen[7]==W
    )||(sen[0]==W&&sen[1]==W&&sen[2]==W&&sen[3]==W&&sen[4]==W&&sen[5]==W&&sen[6]==B&&sen[7]==B
    
   )||(sen[0]==W&&sen[1]==W&&sen[2]==W&&sen[3]==W&&sen[4]==B&&sen[5]==B&&sen[6]==W&&sen[7]==W
   )||(sen[0]==W&&sen[1]==W&&sen[2]==B&&sen[3]==B&&sen[4]==B&&sen[5]==B&&sen[6]==B&&sen[7]==W
   )||(sen[0]==W&&sen[1]==W&&sen[2]==B&&sen[3]==B&&sen[4]==B&&sen[5]==B&&sen[6]==B&&sen[7]==B
))
  {
    turnRight();
    Serial.println("04");
  }

 // <-------------------------------------//REST NOW PART//------------------------------------->
  
    else if(sen[0]==B&&sen[1]==B&&sen[2]==B&&sen[3]==B&&sen[4]==B&&sen[5]==B&&sen[6]==B&&sen[7]==B&&sen[8]==B)
  {
    doStop();
    Serial.println("05");
  }
  else if((sen[0]==W&&sen[1]==W&&sen[2]==B&&sen[3]==B&&sen[4]==B&&sen[5]==W&&sen[6]==W&&sen[7]==W
  )||(sen[0]==W&&sen[1]==W&&sen[2]==W&&sen[3]==B&&sen[4]==B&&sen[5]==B&&sen[6]==W&&sen[7]==W
  )||(sen[0]==W&&sen[1]==W&&sen[2]==W&&sen[3]==B&&sen[4]==B&&sen[5]==W&&sen[6]==W&&sen[7]==W
  )||(sen[0]==W&&sen[1]==W&&sen[2]==B&&sen[3]==B&&sen[4]==B&&sen[5]==B&&sen[6]==W&&sen[7]==W
  ))
       {
  moveForward();
  Serial.println("01");
       }
Serial.println(sen[8]);

}
void moveForward()
{ 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.println("FORWARD");
 // delay(50);
}
 void turnLeft()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.println("LEFT");
}

void turnRight()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.println("RIGHT");
}
void doStop()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);
  Serial.println("STOP");  
}
