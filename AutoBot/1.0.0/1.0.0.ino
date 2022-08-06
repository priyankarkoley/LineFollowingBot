#define W 1
#define B 0

#define in1 9
#define in2 8
#define in3 10
#define in4 11

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
  Serial.begin(9600);
}

void loop() {

delay(1000);
int sen[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int track[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int i;
float avg, ct=0, sum=0;
  
  sen[0] = digitalRead(ir0);
  sen[1] = digitalRead(ir1);
  sen[2] = digitalRead(ir2);
  sen[3] = digitalRead(ir3);
  sen[4] = digitalRead(ir4);
  sen[5] = digitalRead(ir5);
  sen[6] = digitalRead(ir6);
  sen[7] = digitalRead(ir7);

for(i=0;i<=7;i++)
  {
    if(sen[i]==B)
      {
        track[i]=(i+1);
        ct++;
      }
    else
      {
        track[i]=0;
      } 
    sum=sum+track[i];
 }
avg=sum/ct;
if((sen[1]==B)&&(sen[2]==B)&&(sen[3]==B)&&(sen[4]==B)&&(sen[5]==B)&&(sen[6]==B)&&(sen[7]==B)&&(sen[8]==B))
avg=-1;
if((sen[1]==B)&&(sen[2]==B)&&(sen[3]==B)&&(sen[4]==B)&&(sen[5]==B)&&(sen[6]==B)&&(sen[7]==B)&&(sen[8]==B))
avg=-1;


Serial.print("\t");
Serial.print(track[0]);
Serial.print("\t");
Serial.print(track[1]);
Serial.print("\t");
Serial.print(track[2]);
Serial.print("\t");
Serial.print(track[3]);
Serial.print("\t");
Serial.print(track[4]);
Serial.print("\t");
Serial.print(track[5]);
Serial.print("\t");
Serial.print(track[6]);
Serial.print("\t");
Serial.print(track[7]);
Serial.print("\n");
Serial.println(ct);
Serial.println(sum, 4);
Serial.println(avg, 4);




//if(sen[3]==B&&sen[4]==B)
//moveForward();

     if (avg==-1)
doStop();
else if(avg>=1&&avg<=2.5)
turnSLeft();
else if(avg>2.5&&avg<=3.5)
turnLeft();
else if(avg>3.5&&avg<5.5)
{
moveForward();
}
else if(avg>=5.5&&avg<6.5)
turnRight();
else if(avg>=6.5&&avg<=8)
turnSRight();


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
