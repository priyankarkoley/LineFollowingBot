#define W 1
#define B 0

float Kp = 65, Ki = 0, Kd = 120;//160;//50
float error = 0, P = 0, I = 0, D = 0, PID_value = 0;
float previous_error = 0;
int sensor[8] = {0, 0, 0, 0, 0, 0, 0, 0};
float lm = 160;
float rm = 160;
int max_speed = 180;

int flag;

#define In1 4
#define In2 5
#define In3 6
#define In4 7
#define ENA 3
#define ENB 11
#define led 8

#define zero A5
#define one  A4
#define two A3
#define three A2
#define four A1
#define five A0
#define six 9
#define seven 10

int read_sensor_value();
void cal_PID();
void set_motor(float lm, float  rm);


void setup() {
  // put your setup code here, to run once:

  pinMode(zero, INPUT);
  pinMode(one, INPUT);
  pinMode(two, INPUT);
  pinMode(three, INPUT);
  pinMode(four, INPUT);
  pinMode(five, INPUT);
  pinMode(six, INPUT);
  pinMode(seven, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //delay(200);
  read_sensor_value();
  cal_PID();

  if ((sensor[0] == B) && (sensor[1] == B) && (sensor[2] == B) && (sensor[3] == B) && (sensor[4] == B)
      && (sensor[5] == B) && (sensor[6] == B) && (sensor[7] == B))
  {
    digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    set_motor(150, 150);
    read_sensor_value();
    while ((sensor[0] == B) && (sensor[1] == B) && (sensor[2] == B) && (sensor[3] == B)
           && (sensor[4] == B) && (sensor[5] == B) && (sensor[6] == B) && (sensor[7] == B))
    {
      set_motor(0, 0);
      read_sensor_value();
    }
  }

  if ((sensor[0] == W) && (sensor[1] == W) && (sensor[2] == W) && (sensor[3] == W) && (sensor[4] == W)
      && (sensor[5] == W) && (sensor[6] == W) && (sensor[7] == W))
  {
    if (flag == 1)
    {
      while ((sensor[0] == W) && (sensor[1] == W) && (sensor[2] == W) && (sensor[3] == W) && (sensor[4] == W)
             && (sensor[5] == W) && (sensor[6] == W) && (sensor[7] == W))
      {
        set_motor(150, -150);
        read_sensor_value();
      }
    }
    if (flag == 0)
    {
      while ((sensor[0] == W) && (sensor[1] == W) && (sensor[2] == W) && (sensor[3] == W) && (sensor[4] == W)
             && (sensor[5] == W) && (sensor[6] == W) && (sensor[7] == W))
      {
        set_motor(-150, 150);
        read_sensor_value();
      }
    }
  }
}

int read_sensor_value()
{

  sensor[0] = !digitalRead(A5);
  sensor[1] = !digitalRead(A4);
  sensor[2] = !digitalRead(A3);
  sensor[3] = !digitalRead(A2);
  sensor[4] = !digitalRead(A1);
  sensor[5] = !digitalRead(A0);
  sensor[6] = !digitalRead(9);
  sensor[7] = !digitalRead(10);
  Serial.print(sensor[0]);
  Serial.print(sensor[1]);
  Serial.print(sensor[2]);
  Serial.print(sensor[3]);
  Serial.print(sensor[4]);
  Serial.print(sensor[5]);
  Serial.print(sensor[6]);
  Serial.println(sensor[7]);
  error = ((sensor[0] * (-7) + sensor[1] * (-5) + sensor[2] * (-3) + sensor[3] * (-1) + sensor[4] * 1 + sensor[5] * 3 + sensor[6] * 5
            + sensor[7] * (7)) / (sensor[0] + sensor[1] + sensor[2] + sensor[3] + sensor[4] + sensor[5] + sensor[6] + sensor[7]));

  if (sensor[0] == B && sensor[7] == W) //left
  {
    flag = 0;
  }

  if (sensor[0] == W && sensor[7] == B) //right
  {
    flag = 1;
  }

  return error;
}

void cal_PID()
{
  while (1)
  {
    error = read_sensor_value();

    P = error;
    I = I + error;
    D = error - previous_error;

    PID_value = (Kp * P) + (Ki * I) + (Kd * D);

    previous_error = error;

    if (PID_value > max_speed)
    {
      PID_value = max_speed;
    }
    else if (PID_value < -max_speed)
    {
      PID_value = 0 - max_speed;
    }


    if (PID_value > 0)
      set_motor(max_speed, max_speed - PID_value);
    else
      set_motor(max_speed + PID_value, max_speed);

    if ((sensor[0] == B) && (sensor[1] == B) && (sensor[2] == B) && (sensor[3] == B) && (sensor[4] == B)
        && (sensor[5] == B) && (sensor[6] == B) && (sensor[7] == B))
    {
      break;
    }
    if ((sensor[0] == W) && (sensor[1] == W) && (sensor[2] == W) && (sensor[3] == W) && (sensor[4] == W)
        && (sensor[5] == W) && (sensor[6] == W) && (sensor[7] == W))
    {
      break;
    }
  }
}

void set_motor(float lm, float  rm)
{
  if (lm == 0)
  {
    digitalWrite(In1, HIGH);
    digitalWrite(In2, HIGH);
    analogWrite(ENA, 255);
  }
  else if (lm > 0)
  {
    digitalWrite(In1, HIGH);
    digitalWrite(In2, LOW);
    analogWrite(ENA, lm);
  }
  else
  {
    digitalWrite(In2, HIGH);
    digitalWrite(In1, LOW);
    analogWrite(ENA, -lm);
  }
  if (rm == 0)
  {
    digitalWrite(In3, HIGH);
    digitalWrite(In4, HIGH);
    analogWrite(ENB, 255);
  }
  else if (rm > 0)
  {
    digitalWrite(In3, HIGH);
    digitalWrite(In4, LOW);
    analogWrite(ENB, rm);
  }
  else
  {
    digitalWrite(In4, HIGH);
    digitalWrite(In3, LOW);
    analogWrite(ENB, -rm);
  }
}