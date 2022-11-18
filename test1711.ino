#define BAUD (9600)
const int trig = 9; //Khai báo chân trig nối với chân số 8 là hằng số
const int echo = 8; //Khai báo chân echo nối với chân số 7 là hằng số
#define nut PC13
#define hongngoai PB14
#define quangtro PB13
//unsigned long thoigian;
//int gioihan = 5;
int x;
//int khoangcach;
int kc; // bien khoang cach


void setup() {
  Serial.begin(BAUD);
  // bánh trái
  pinMode(PC14,OUTPUT); // Enable pin - chân khởi động - nối vào GND sẽ giúp ta bật động cơ bước, nối vô VCC động cơ bước được thả ra. Nôm na: GND = servo.attach, VCC = servo.detach
  pinMode(4,OUTPUT); // Step pin
  pinMode(3,OUTPUT); // Dir - pin
  digitalWrite(PC14,LOW); // Set Enable low
  // bánh phải
  pinMode(PC15,OUTPUT); // Enable pin - chân khởi động - nối vào GND sẽ giúp ta bật động cơ bước, nối vô VCC động cơ bước được thả ra. Nôm na: GND = servo.attach, VCC = servo.detach
  pinMode(6,OUTPUT); // Step pin
  pinMode(5,OUTPUT); // Dir - pin
  digitalWrite(PC15,LOW); // Set Enable low
  digitalWrite(PB14,INPUT);

  pinMode(trig, OUTPUT); //Chân trig xuất tín hiệu
  pinMode(echo, INPUT); //Chân echo nhận tín hiệu
}

void loop() 
{
dithang();
rephai();
}
void nutnhan()
{
if( digitalRead(nut) == 0 and digitalRead(quangtro)==1)
{
  dithang();
  rephai();
  dingan();
  rephai();
  dithang();
  quaydau();
  dithang();
  retrai();
  dingan();
  retrai();
  dithang();
  dunglai(); 
  }

if (digitalRead(nut) == 1 and digitalRead(quangtro)==0)
 {
    dunglai();
  } 
  
}
  void dithang()
{
  //bánh trái
  digitalWrite(PC14,LOW); // Đặt Enable ở trạng thái LOW
  digitalWrite(3,HIGH); // Đặt Dir  ở trạng thái HIGH
   //bánh phải
  digitalWrite(PC15,LOW); // Đặt Enable ở trạng thái LOW
  digitalWrite(5,HIGH); // Đặt Dir  ở trạng thái HIGH
  //Serial.println("Cho chay 200 steps (1 vong)");
  for(x = 0; x < 2000; x++) // Cho chay 1 vong
  {
    if(digitalRead(hongngoai)==1)
    {
    digitalWrite(4,HIGH); // Output high
    delay(1); // chờ
    digitalWrite(4,LOW); // Output low
    delay(1); // chờ
    digitalWrite(6,HIGH); // Output high
    delay(1); // chờ
    digitalWrite(6,LOW); // Output low
    delay(1); // chờ
    }
  
  while(digitalRead(hongngoai)==0)
  {
 dunglai();
    }
    //delay(1000);
  }
}
  void dunglai()
   {
  {
        digitalWrite(4,LOW); // Output high
    delay(1); // chờ
    digitalWrite(4,LOW); // Output low
    delay(1); // chờ
    digitalWrite(6,LOW); // Output high
    delay(1); // chờ
    digitalWrite(6,LOW); // Output low
    delay(1); // chờ
    }
    delay(2000);
    }
void rephai ()
  {
      digitalWrite(PC14,LOW); // Đặt Enable ở trạng thái LOW
  digitalWrite(3,HIGH); // Đặt Dir  ở trạng thái HIGH
  digitalWrite(PC15,LOW); // Đặt Enable ở trạng thái LOW
  digitalWrite(5,HIGH); // Đặt Dir  ở trạng thái HIGH
  Serial.println("Cho chay 200 steps (1 vong)");
  for(x = 0; x < 260; x++) // Cho chay 1 vong
    {
        digitalWrite(4,LOW); // Output high
    delay(1); // chờ
    digitalWrite(4,HIGH); // Output low
    delay(1); // chờ
    digitalWrite(6,LOW); // Output high
    delay(1); // chờ
    digitalWrite(6,LOW); // Output low
    delay(1); // chờ
    }
    delay (500);
    }
      void dingan()
{
  digitalWrite(PC14,LOW); // Đặt Enable ở trạng thái LOW
  digitalWrite(3,HIGH); // Đặt Dir  ở trạng thái HIGH
  digitalWrite(PC15,LOW); // Đặt Enable ở trạng thái LOW
  digitalWrite(5,HIGH); // Đặt Dir  ở trạng thái HIGH
  Serial.println("Cho chay 200 steps (1 vong)");
  for(x = 0; x < 400; x++) // Cho chay 1 vong
  {
        digitalWrite(4,HIGH); // Output high
    delay(1); // chờ
    digitalWrite(4,LOW); // Output low
    delay(1); // chờ
    digitalWrite(6,HIGH); // Output high
    delay(1); // chờ
    digitalWrite(6,LOW); // Output low
    delay(1); // chờ
    }
    delay(300);
}
      void quaydau ()
  {
      digitalWrite(PC14,LOW); // Đặt Enable ở trạng thái LOW
  digitalWrite(3,HIGH); // Đặt Dir  ở trạng thái HIGH
  digitalWrite(PC15,LOW); // Đặt Enable ở trạng thái LOW
  digitalWrite(5,LOW); // Đặt Dir  ở trạng thái HIGH
  Serial.println("Cho chay 200 steps (1 vong)");
  for(x = 0; x < 265; x++) // Cho chay 1 vong
    {
        digitalWrite(4,HIGH); // Output high
    delay(1); // chờ
    digitalWrite(4,LOW); // Output low
    delay(1); // chờ
    digitalWrite(6,HIGH); // Output high
    delay(1); // chờ
    digitalWrite(6,LOW); // Output low
    delay(1); // chờ
    }
    delay (500);
    }
     void retrai ()
  {
      digitalWrite(PC14,LOW); // Đặt Enable ở trạng thái LOW
  digitalWrite(3,LOW); // Đặt Dir  ở trạng thái HIGH
  digitalWrite(PC15,LOW); // Đặt Enable ở trạng thái LOW
  digitalWrite(5,HIGH); // Đặt Dir  ở trạng thái HIGH
  Serial.println("Cho chay 200 steps (1 vong)");
  for(x = 0; x < 260; x++) // Cho chay 1 vong
    {
        digitalWrite(4,LOW); // Output high
    delay(1); // chờ
    digitalWrite(4,LOW); // Output low
    delay(1); // chờ
    digitalWrite(6,HIGH); // Output high
    delay(1); // chờ
    digitalWrite(6,LOW); // Output low
    delay(1); // chờ
    }
    delay (500);
    }
    /*int DoKC(){
  //digitalWrite(trig,0); // xuat xung chan Trig
  //delayMicroseconds(10)
  digitalWrite(trig,1); // xuat xung chan Trig
  delayMicroseconds(5); // trong 5us
  digitalWrite(trig,0);
  

 /* while(micros()- pulse < 3000)
  {
    if(digitalRead(echo)==0)
    {
      tg= micros() - pulse;
      }
    }
    if(tg==0)
    {
      tg=3000;
      }
  /// do thoi gian xung o muc 1

  tg= pulseIn(echo,1);
  kc= tg/2/29.412; // cong thuc chuyen doi qua khoang cach
  return kc; // tra gia tri khoang cach ve ctrinh con
  }*/
/*void Do()
{
float tongKC=0;
  for(int k=0;k<10;k++)
  {
    tongKC += DoKC();// gấp đôi biến K tại thời điểm đo
    
  }
  float K = tongKC/10;
  int KCTB = (int)K;
  //int kc=0;  
  
 kc = 0;
  DoKC();
 if(kc < 20){
  dunglai();
  delay(2000);
  }
if(kc>=20)
{
  xechay();
  }
}*/
