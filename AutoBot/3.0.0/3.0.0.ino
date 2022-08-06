int s[8];

const int ENA = 5;
const int IN1=9;
const int IN2=8;
const int ENB=3;
const int IN3=10;
const int IN4=11;
void setup() 
{
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);

  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  //Serial.begin(9600);

  //forward();
 // delay(2000);
}

void loop() 
{
  analogWrite(ENA, 180);
  analogWrite(ENB, 180);
  
  s[0]=!digitalRead(A0);
  s[1]=!digitalRead(A1);
  s[2]=!digitalRead(A2);
  s[3]=!digitalRead(5);
  s[4]=!digitalRead(6);
  s[5]=!digitalRead(7);
  s[6]=!digitalRead(8);
  s[7]=!digitalRead(9);


 /* Serial.print(s[0]);
  
  Serial.print(" ");
  Serial.print(s[1]);
  Serial.print(" ");
  Serial.print(s[2]);
  Serial.print(" ");
  Serial.print(s[3]);
  Serial.print(" ");
  Serial.print(s[4]);
  Serial.print(" ");
  Serial.print(s[5]);
  Serial.print(" ");
  Serial.print(s[6]);
  Serial.print(" ");
  Serial.print(s[7]);
  Serial.println(" ");
  delay (1000);
  */
  
  //black=1
  //white=0
  //forward
  if(
  ((s[0]==0)&&(s[1]==0)&&(s[2]==0)&&(s[3]==1)&&(s[4]==1)&&(s[5]==0)&&(s[6]==0)&&(s[7]==0))||
  ((s[0]==0)&&(s[1]==0)&&(s[2]==1)&&(s[3]==1)&&(s[4]==1)&&(s[5]==1)&&(s[6]==0)&&(s[7]==0))||
  ((s[0]==0)&&(s[1]==1)&&(s[2]==1)&&(s[3]==1)&&(s[4]==1)&&(s[5]==1)&&(s[6]==1)&&(s[7]==0)) 
  )
  {
    forward();
  }
  //right
  else if(
  ((s[0]==0)&&(s[1]==1)&&(s[2]==1)&&(s[3]==1)&&(s[4]==1)&&(s[5]==1)&&(s[6]==1)&&(s[7]==1))||
  ((s[0]==0)&&(s[1]==0)&&(s[2]==1)&&(s[3]==1)&&(s[4]==1)&&(s[5]==1)&&(s[6]==1)&&(s[7]==1))||
  ((s[0]==0)&&(s[1]==0)&&(s[2]==0)&&(s[3]==1)&&(s[4]==1)&&(s[5]==1)&&(s[6]==1)&&(s[7]==1))||
  ((s[0]==0)&&(s[1]==0)&&(s[2]==0)&&(s[3]==0)&&(s[4]==1)&&(s[5]==1)&&(s[6]==1)&&(s[7]==1))||
  ((s[0]==0)&&(s[1]==0)&&(s[2]==0)&&(s[3]==0)&&(s[4]==0)&&(s[5]==1)&&(s[6]==1)&&(s[7]==1))||
  ((s[0]==0)&&(s[1]==0)&&(s[2]==0)&&(s[3]==0)&&(s[4]==0)&&(s[5]==0)&&(s[6]==1)&&(s[7]==1))||
  ((s[0]==0)&&(s[1]==0)&&(s[2]==0)&&(s[3]==0)&&(s[4]==0)&&(s[5]==0)&&(s[6]==0)&&(s[7]==1))||
  ((s[0]==0)&&(s[1]==0)&&(s[2]==0)&&(s[3]==0)&&(s[4]==0)&&(s[5]==1)&&(s[6]==1)&&(s[7]==0))||
  ((s[0]==0)&&(s[1]==0)&&(s[2]==0)&&(s[3]==0)&&(s[4]==1)&&(s[5]==1)&&(s[6]==0)&&(s[7]==0))||
  ((s[0]==0)&&(s[1]==0)&&(s[2]==0)&&(s[3]==0)&&(s[4]==1)&&(s[5]==1)&&(s[6]==1)&&(s[7]==0))||
  ((s[0]==0)&&(s[1]==0)&&(s[2]==0)&&(s[3]==1)&&(s[4]==1)&&(s[5]==1)&&(s[6]==0)&&(s[7]==0))||
  ((s[0]==0)&&(s[1]==0)&&(s[2]==0)&&(s[3]==1)&&(s[4]==1)&&(s[5]==1)&&(s[6]==1)&&(s[7]==0))||
  ((s[0]==0)&&(s[1]==0)&&(s[2]==1)&&(s[3]==1)&&(s[4]==1)&&(s[5]==1)&&(s[6]==1)&&(s[7]==0))
  )
  {
    right();
  }
  else if(
  ((s[0]==1)&&(s[1]==1)&&(s[2]==1)&&(s[3]==1)&&(s[4]==1)&&(s[5]==1)&&(s[6]==1)&&(s[7]==0))||
  ((s[0]==1)&&(s[1]==1)&&(s[2]==1)&&(s[3]==1)&&(s[4]==1)&&(s[5]==1)&&(s[6]==0)&&(s[7]==0))||
  ((s[0]==1)&&(s[1]==1)&&(s[2]==1)&&(s[3]==1)&&(s[4]==1)&&(s[5]==0)&&(s[6]==0)&&(s[7]==0))||
  ((s[0]==1)&&(s[1]==1)&&(s[2]==1)&&(s[3]==1)&&(s[4]==0)&&(s[5]==0)&&(s[6]==0)&&(s[7]==0))||
  ((s[0]==1)&&(s[1]==1)&&(s[2]==1)&&(s[3]==0)&&(s[4]==0)&&(s[5]==0)&&(s[6]==0)&&(s[7]==0))||
  ((s[0]==1)&&(s[1]==1)&&(s[2]==0)&&(s[3]==0)&&(s[4]==0)&&(s[5]==0)&&(s[6]==0)&&(s[7]==0))||
  ((s[0]==1)&&(s[1]==0)&&(s[2]==0)&&(s[3]==0)&&(s[4]==0)&&(s[5]==0)&&(s[6]==0)&&(s[7]==0))||
  ((s[0]==0)&&(s[1]==1)&&(s[2]==1)&&(s[3]==0)&&(s[4]==0)&&(s[5]==0)&&(s[6]==0)&&(s[7]==0))||
  ((s[0]==0)&&(s[1]==0)&&(s[2]==1)&&(s[3]==1)&&(s[4]==0)&&(s[5]==0)&&(s[6]==0)&&(s[7]==0))||
  ((s[0]==0)&&(s[1]==1)&&(s[2]==1)&&(s[3]==1)&&(s[4]==0)&&(s[5]==0)&&(s[6]==0)&&(s[7]==0))||
  ((s[0]==0)&&(s[1]==0)&&(s[2]==1)&&(s[3]==1)&&(s[4]==1)&&(s[5]==0)&&(s[6]==0)&&(s[7]==0))||
  ((s[0]==0)&&(s[1]==1)&&(s[2]==1)&&(s[3]==1)&&(s[4]==1)&&(s[5]==0)&&(s[6]==0)&&(s[7]==0))||
  ((s[0]==0)&&(s[1]==1)&&(s[2]==1)&&(s[3]==1)&&(s[4]==1)&&(s[5]==1)&&(s[6]==0)&&(s[7]==0))
  )
  {
    left();
  }
  else doStop();
}
void forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
 // analogWrite(ENA, 80);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  //analogWrite(ENB, 80);
}

void right()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  //analogWrite(ENA, 0);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  //analogWrite(ENB, 60);
}

void left()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //analogWrite(ENA, 60);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  //analogWrite(ENB, 0);
}

void doStop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  //analogWrite(ENA, 0);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  //analogWrite(ENB, 0);
}
