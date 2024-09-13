
//#include <TimerOne.h>
#include "TimerOne.h"

// KHAI BÁO ĐỘNG CƠ 1
#define in1 2             // Chân encoderA
#define in2 4             // Chân encoderB
#define enA 3             // Chân PWM
#define dir1 6            // chân direction 1
#define dir2 7            // chân direction 2

// KHAI BÁO ĐỘNG CƠ 2
#define in3 19
#define in4 17
#define enB 18
#define dir3 8
#define dir4 9


double T, xung;
double tocdo, Tocdodat;
double E, E1, E2;
double alpha, beta, gamma, Kp, Ki, Kd;
double Output, LastOutput;

double xung2;
double tocdo2, Tocdodat2;
double E20, E21, E22;
double alpha2, beta2, gamma2, Kp2, Ki2, Kd2;
double Output2, LastOutput2;

// KHAI BÁO BIẾN TT ĐIỀU KHIỂN HƯỚNG TIẾN-LÙI-TRÁI-PHẢI == 8-2-4-6
int tt_banh = 0;
int tt_banh2 = 0;

void setup()
{
  pinMode(in1, INPUT_PULLUP);      // Chan ngat
  pinMode(in2, INPUT_PULLUP);      // Chan doc Encoder
  pinMode(enA, OUTPUT);            // Chan PWM
  pinMode(dir1, OUTPUT);            // Chan DIR1
  pinMode(dir2, OUTPUT);            // Chan DIR2

  pinMode(in3, INPUT_PULLUP);      // Chan ngat
  pinMode(in4, INPUT_PULLUP);      // Chan doc Encoder
  pinMode(enB, OUTPUT);            // Chan PWM
  pinMode(dir3, OUTPUT);            // Chan DIR1
  pinMode(dir4, OUTPUT);            // Chan DIR2

  Tocdodat = 50; tocdo = 0;      // max cua GA25-370 130rpm o muc dien ap 11V la 120v/p
  E = 0; E1 = 0; E2 = 0;
  Output = 0; LastOutput = 0;
  // Thong so PID
  T = 0.005;                        // Thoi gian lay mau
  Kp = 9; Kd = 0.01; Ki = 0;

  Tocdodat2 = 50; tocdo2 = 0;      // max cua GA25-370 130rpm o muc dien ap 11V la 120v/p
  E20 = 0; E21 = 0; E22 = 0;
  Output2 = 0; LastOutput2 = 0;

  Kp2 = 9; Kd2 = 0.01; Ki2 = 0;
  Serial.begin(115200);
  attachInterrupt(0, Demxung, FALLING);    // Tra GG de hieu ve ham nay 'attachInterrupt'
  attachInterrupt(4, Demxung2, FALLING);
  
  Timer1.initialize(5000);                // Khoi tao ham timer ngat sau 5ms
  Timer1.attachInterrupt(PID_controller);
}
void loop()
{
  int i;
  for (i=0; i<10; i++)
    delay(1);
  // IN RA MÀN HÌNH GIÁ TRỊ TỐC ĐỘ CỦA 2 ĐỘNG CƠ
  Serial.print("tocdo:  ");
  Serial.print(tocdo);
  Serial.print("   tocdo2:  ");
  Serial.println(tocdo2);
  /////////////////////////////////////PHẦN XỬ LÝ ĐỌC TÍN HIỆU ĐIỀU KHIỂN TỪ MONITOR
  int* const ptr_tt_banh = &tt_banh;
  int* const ptr_tt_banh2 = &tt_banh2;
  if (Serial.available() > 0) {
    // Đọc giá trị từ bàn phím dưới dạng chuỗi DẠNG "4 4", "2 2"
    String input = Serial.readStringUntil('\n');  // Đọc chuỗi đến khi gặp ký tự xuống dòng

    // Tách chuỗi thành 2 phần dựa trên dấu cách (space)
    int index = input.indexOf(' ');  // Tìm vị trí của dấu cách
    String tocdodat_str = input.substring(0, index);  // Lấy chuỗi trước dấu cách
    String tocdodat2_str = input.substring(index + 1);  // Lấy chuỗi sau dấu cách

    // Chuyển chuỗi thành số nguyên VÀ gán giá trị vào con trỏ hằng
    // ==> thay đổi giá trị vị trí con trỏ trỏ đến 
    *ptr_tt_banh = tocdodat_str.toInt();
    *ptr_tt_banh2 = tocdodat2_str.toInt();
  }
}

void Demxung()
{
  if (digitalRead(4) == LOW)
    xung++;
  else
    xung--;
}

void Demxung2()
{
  if (digitalRead(17) == LOW)
    xung2++;
  else
    xung2--;
}

void PID(int tt_banh)
{
  double *p = &Tocdodat;
  tocdo = (abs(xung)/490)*(1/T)*60;          //
  xung = 0;
  E = abs(*p) - tocdo;
  alpha = 2*T*Kp + Ki*T*T + 2*Kd;
  beta = T*T*Ki - 4*Kd - 2*T*Kp;
  gamma = 2*Kd;
  Output = (alpha*E + beta*E1 + gamma*E2 + 2*T*LastOutput)/(2*T);
  LastOutput = Output;
  E2 = E1;
  E1 = E;
  if (Output > 255)                   
    Output = 255; 
  if (Output < 0)
    Output = 0;

  analogWrite(enA, Output);

  
  if (tt_banh == 8 || tt_banh == 4)
  {
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
  }
  else if (tt_banh == 6 || tt_banh == 2)
  {
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
  }
  else
  {
    analogWrite(enA, 0);
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, LOW);
  }
}


void PID2(int tt_banh2)
{
  double *p2 = &Tocdodat2;
  tocdo2 = (abs(xung2)/490)*(1/T)*60;          // Giai thich ben duoi
  xung2 = 0;
  E20 = abs(*p2) - tocdo2;
  alpha2 = 2*T*Kp2 + Ki2*T*T + 2*Kd2;
  beta2 = T*T*Ki2 - 4*Kd2 - 2*T*Kp2;
  gamma2 = 2*Kd2;
  Output2 = (alpha2*E + beta2*E1 + gamma2*E2 + 2*T*LastOutput2)/(2*T);
  LastOutput2 = Output2;
  E22 = E21;
  E21 = E20;
  if (Output2 > 255)                   
    Output2 = 255; 
  if (Output2 < 0)
    Output2 = 0;

  analogWrite(enB, Output);

  if (tt_banh2 == 8 || tt_banh2 == 6)
  {
    digitalWrite(dir3, LOW);
    digitalWrite(dir4, HIGH);
  }
  else if (tt_banh2 == 2 || tt_banh2 == 4)
  {
    digitalWrite(dir3, HIGH);
    digitalWrite(dir4, LOW);
  }
  else
  {
    analogWrite(enB, 0);
    digitalWrite(dir3, LOW);
    digitalWrite(dir4, LOW);
  }
}

void PID_controller()
{
  int* ptr_tt_banh = &tt_banh;
  int* ptr_tt_banh2 = &tt_banh2;
  PID(*ptr_tt_banh);
  PID2(*ptr_tt_banh2);  
}
