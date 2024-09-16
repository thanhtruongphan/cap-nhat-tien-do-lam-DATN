#include "TimerOne.h"
#include "atomic.h"

//// Pins
#define ENCA 21
#define ENCB 20
#define PWM 2
#define IN1 5
#define IN2 6

// Pins
#define ENCC 19
#define ENCD 18
#define PWM2 3
#define IN3 8
#define IN4 9

// globals
long prevT = 0;
int posPrev = 0;
// Use the "volatile" directive for variables
// used in an interrupt
volatile int pos_i = 0;
volatile float velocity_i = 0;
volatile long prevT_i = 0;
float v1Filt = 0;
float v1Prev = 0;
float v2Filt = 0;
float v2Prev = 0;
float eintegral = 0;

// globals 2
long prevT2 = 0;
int posPrev2 = 0;
// Use the "volatile" directive for variables
// used in an interrupt
volatile int pos_i2 = 0;
volatile float velocity_i2 = 0;
volatile long prevT_i2 = 0;
float v3Filt = 0;
float v3Prev = 0;
float v4Filt = 0;
float v4Prev = 0;
float eintegral2 = 0;

// de trinh bien dich khong toi uu hai bien nay, su dung 'volatile'
// de viec truy cap gia tri cua no luon chinh xac!
volatile float vt = 0;
volatile float vt2 = 0;

// Cờ để báo hiệu việc thực hiện PID
volatile bool pidFlag = false;  

char inputBuffer[20];
int index = 0;

void setup() {
  Serial.begin(9600);

  pinMode(ENCA,INPUT);
  pinMode(ENCB,INPUT);
  pinMode(PWM,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);

  pinMode(ENCC,INPUT);
  pinMode(ENCD,INPUT);
  pinMode(PWM2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

  attachInterrupt(digitalPinToInterrupt(ENCA),readEncoder,RISING);
  attachInterrupt(digitalPinToInterrupt(ENCC),readEncoder2,RISING);
  Timer1.initialize(5000);                // Khoi tao ham timer ngat sau 10ms
  Timer1.attachInterrupt(PID_timerInterrupt); 
}

void loop() {
  int i;
  for (i=0; i<10; i++)
    delay(1);
  /////////////////////////////////////PHẦN XỬ LÝ ĐỌC TÍN HIỆU ĐIỀU KHIỂN TỪ MONITOR
  if (Serial.available() > 0) {
    // Đọc giá trị từ bàn phím dưới dạng chuỗi DẠNG "4 4", "2 2"
    String input = Serial.readStringUntil('\n');  // Đọc chuỗi đến khi gặp ký tự xuống dòng

    // Tách chuỗi thành 2 phần dựa trên dấu cách (space)
    int index = input.indexOf(' ');  // Tìm vị trí của dấu cách
    String tocdodat_str = input.substring(0, index);  // Lấy chuỗi trước dấu cách
    String tocdodat2_str = input.substring(index + 1);  // Lấy chuỗi sau dấu cách

    // Chuyển chuỗi thành số nguyên VÀ gán giá trị vào con trỏ hằng
    // ==> thay đổi giá trị vị trí con trỏ trỏ đến 
    float* const ptr_vt = &vt;
    float* const ptr_vt2 = &vt2;
    *ptr_vt = tocdodat_str.toInt();
    *ptr_vt2 = tocdodat2_str.toInt();

    // de phong tran bo nho khi su dung lau:
    // index = 0;
    // input = ' ';
  }
  if (pidFlag) {
    // Thực hiện tính toán PID
    PID_controller();

    // Đặt lại cờ sau khi thực hiện PID
    pidFlag = false;
  }
  Serial.print(vt);
  Serial.print(" v1,v2 ");
  Serial.print(v1Filt);
  Serial.print(" ");


  Serial.print(vt2);
  Serial.print(" v3, v4 ");
  Serial.print(v3Filt);
  Serial.println(" ");
//  delay(1);
}

void PID_timerInterrupt() {
  pidFlag = true;  // Đánh dấu cờ để thực hiện PID
}

void PID_controller()
{
  // read the position in an atomic block
  // to avoid potential misreads

  // MOTOR 01
  int pos = 0;
  float velocity2 = 0;
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
  {
    pos = pos_i;
    velocity2 = velocity_i;
  }


  // MOTOR 02
  int pos2 = 0;
  float velocity2_2 = 0;
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
  {
    pos2 = pos_i2;
    velocity2_2 = velocity_i2;
  }
  
  // Compute velocity with method 1
  long currT = micros();
  float deltaT = ((float) (currT-prevT))/1.0e6;
  float velocity1 = (pos - posPrev)/deltaT;
  posPrev = pos;
  prevT = currT;

  // MOTOR 02
  long currT2 = micros();
  float deltaT2 = ((float) (currT2-prevT2))/1.0e6;
  float velocity1_2 = (pos2 - posPrev2)/deltaT2;
  posPrev2 = pos2;
  prevT2 = currT2;

  // Convert count/s to RPM
  float v1 = velocity1/490.0*60.0;
  float v2 = velocity2/490.0*60.0;

  float v3 = velocity1_2/490.0*60.0;
  float v4 = velocity2_2/490.0*60.0;

  // Low-pass filter (25 Hz cutoff)
  v1Filt = 0.854*v1Filt + 0.0728*v1 + 0.0728*v1Prev;
  v1Prev = v1;
  v2Filt = 0.854*v2Filt + 0.0728*v2 + 0.0728*v2Prev;
  v2Prev = v2;

  v3Filt = 0.854*v3Filt + 0.0728*v3 + 0.0728*v3Prev;
  v3Prev = v3;
  v4Filt = 0.854*v4Filt + 0.0728*v4 + 0.0728*v4Prev;
  v4Prev = v4;


  // SET A TARGET
//  float vt = 60*(sin(currT/1e6)>0);
//  float vt = -60;
//  float vt2 = 60;
//  float vt, vt2;

  float* ptr_vt = &vt;
  float* ptr_vt2 = &vt2;
  // DUNG KHAN CAP - KICH HOAT DONG NAY:
//  vt = vt2 = 0;


  // Compute the control signal u
  float kp = 0.5;
  float ki = 0.95;

  float kp2 = 0.55;
  float ki2 = 0.95;
  
  float e = vt-v1Filt;
  eintegral = eintegral + e*deltaT;
  float u = kp*e + ki*eintegral;

  float e2 = vt2-v3Filt;
  eintegral2 = eintegral2 + e2*deltaT2;
  float u2 = kp2*e2 + ki2*eintegral2;


  // Set the motor speed and direction
  int dir = 1;
  if (u<0){
    dir = -1;
  }
  int pwr = (int) fabs(u);
  if(pwr > 255){
    pwr = 255;
  }

  int dir2 = 1;
  if (u2<0){
    dir2 = -1;
  }
  int pwr2 = (int) fabs(u2);
  if(pwr2 > 255){
    pwr2 = 255;
  }
  setMotor(dir,pwr,PWM,IN1,IN2);
  setMotor2(dir2,pwr2,PWM2,IN3,IN4);


}
void setMotor(int dir, int pwmVal, int pwm, int in1, int in2)
{
  analogWrite(pwm,pwmVal); // Motor speed
  if(dir == -1){ 
    // Turn one way
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
  }
  else if(dir == 1){
    // Turn the other way
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
  }
  else{
    // Or dont turn
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);    
  }
}

void setMotor2(int dir2, int pwmVal2, int pwm2, int in3, int in4)
{
  analogWrite(pwm2,pwmVal2); // Motor speed
  if(dir2 == -1){ 
    // Turn one way
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
  }
  else if(dir2 == 1){
    // Turn the other way
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
  }
  else{
    // Or dont turn
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);    
  }
}

void readEncoder(){
  // Read encoder B when ENCA rises
  int b = digitalRead(ENCB);
  int increment = 0;
  if(b>0){
    // If B is high, increment forward
    increment = 1;
  }
  else{
    // Otherwise, increment backward
    increment = -1;
  }
  pos_i = pos_i + increment;

  // Compute velocity with method 2
  long currT = micros();
  float deltaT = ((float) (currT - prevT_i))/1.0e6;
  velocity_i = increment/deltaT;
  prevT_i = currT;
}


void readEncoder2(){
  // Read encoder B when ENCA rises
  int d = digitalRead(ENCD);
  int increment2 = 0;
  if(d>0){
    // If B is high, increment forward
    increment2 = 1;
  }
  else{
    // Otherwise, increment backward
    increment2 = -1;
  }
  pos_i2 = pos_i2 + increment2;

  // Compute velocity with method 2
  long currT2 = micros();
  float deltaT2 = ((float) (currT2 - prevT_i2))/1.0e6;
  velocity_i2 = increment2/deltaT2;
  prevT_i2 = currT2;
}
