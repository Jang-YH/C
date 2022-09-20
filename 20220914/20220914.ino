#define TRIG 8
#define ECHO 9

#define SIZE 5

double data[SIZE+1] = {0, };
double pre_avg = 0.0;
double duration = 0.0;
double cm = 0.0;
void setup()
{
Serial.begin(9600);
pinMode(TRIG, OUTPUT); // 센서 Trig 핀
pinMode(ECHO, INPUT); // 센서 Echo 핀
Serial.println("cm,pre_avg");
}

void loop()
{
digitalWrite(TRIG, HIGH);
delayMicroseconds(200);
digitalWrite(TRIG, LOW);

duration = pulseIn(ECHO, HIGH);
cm = duration * 0.034 / 2;

pre_avg = movAvg(pre_avg, cm);

Serial.print(cm);
Serial.print(",");
Serial.println(pre_avg);

delay(200); //1초에 5번 실행
}



double movAvg(double p_avg, double n_data)
{
  double avg = 0;
  
  data[SIZE] = n_data;
  
  avg = p_avg + data[SIZE] / SIZE - data[0] / SIZE;
  
  for(int i = 1; i < SIZE+1; i++)
  {
    data[i-1] = data[i];
  }
  data[SIZE]=0;
  
  return avg;
}
