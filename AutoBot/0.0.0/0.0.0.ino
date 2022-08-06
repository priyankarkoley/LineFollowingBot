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
  //sen[3] = digitalRead(ir3);
  //sen[4] = digitalRead(ir4);
  sen[5] = digitalRead(ir5);
  sen[6] = digitalRead(ir6);
  sen[7] = digitalRead(ir7);
  sen[8] = digitalRead(ir);

if((sen[0]==W)&&(sen[1]==W)&&(sen[2]==W)&&(sen[5]==W)&&(sen[6]==W)&&(sen[7]==W)&&(sen[8]==W)||
   (sen[0]==B)&&(sen[1]==B)&&(sen[2]==B)&&(sen[5]==B)&&(sen[6]==B)&&(sen[7]==B)&&(sen[8]==W))
{
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    Serial.println("FFFFFFFFFF");
}
if(((sen[0]==B)||(sen[1]==B)||(sen[2]==B))&&(sen[5]==W)&&(sen[6]==W)&&(sen[7]==W))
{//LEFT
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    Serial.println("LLLLLLLLLL");
}
if((sen[0]==W)&&(sen[1]==W)&&(sen[2]==W)&&((sen[5]==B)||(sen[6]==B)||(sen[7]==B)))
{//RIGHT
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    Serial.println("RRRRRRRRRR");
}
if((sen[0]==B)&&(sen[1]==B)&&(sen[2]==B)&&  (sen[5]==B)&&(sen[6]==B)&&(sen[7]==B)&&(sen[8]==B))
{//STOP
    digitalWrite(in1,HIGH);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,HIGH);
    Serial.println("SSSSSSSSSS");
}
}
