#define IR_mid A3
#define IR_midL A2
#define IR_midR A1
#define IR_left A0
#define IR_right 8

#define LEFT_RPWM 10
#define LEFT_LPWM 9
#define RIGHT_RPWM 5
#define RIGHT_LPWM 3

#define line_frontL 2
#define line_frontR 4
#define line_backL 12
#define line_backR 11

const int START_PIN = 7; 

bool robotRunning = false;
bool lastButtonState = HIGH;   // لأننا نستخدم INPUT_PULLUP

void setup() {

  pinMode(IR_mid,INPUT);
  pinMode(IR_midR,INPUT);
  pinMode(IR_midL,INPUT);
  pinMode(IR_left,INPUT);
  pinMode(IR_right,INPUT);

  pinMode(LEFT_RPWM, OUTPUT);
  pinMode(LEFT_LPWM, OUTPUT);

  pinMode(RIGHT_RPWM, OUTPUT);
  pinMode(RIGHT_LPWM, OUTPUT);
  
  pinMode(line_frontL,INPUT);
  pinMode(line_frontR,INPUT);
  pinMode(line_backL,INPUT);
  pinMode(line_backR,INPUT);

  pinMode(START_PIN, INPUT);

  Serial.begin(9600);
}

void loop() {

  // قراءة زر التشغيل
  bool currentButtonState = digitalRead(START_PIN);

  // عند الضغط (ينزل من HIGH إلى LOW)
  if(currentButtonState == LOW && lastButtonState == HIGH){
    robotRunning = !robotRunning;   // قلب الحالة

    if(robotRunning){
      Serial.println("Robot ON");
    }else{
      Serial.println("Robot OFF");
    }

    delay(250); // debounce
  }

  lastButtonState = currentButtonState;

  // اذا الروبوت مطفي
  if(!robotRunning){
    stopMotors();
    return;
  }

  // قراءات الحساسات
  int readIR_mid=digitalRead(IR_mid);
  int readIR_midL=digitalRead(IR_midL);
  int readIR_midR=digitalRead(IR_midR);
  int readIR_Right=digitalRead(IR_right);
  int readIR_left=digitalRead(IR_left);

  int readline_frontL=digitalRead(line_frontL);
  int readline_frontR=digitalRead(line_frontR);
  int readline_backL=digitalRead(line_backL);
  int readline_backR=digitalRead(line_backR);

  // حماية الخط الأبيض أولاً
  if(readline_frontR == 0 && readline_frontL == 0){
    backward();
    delay(500);
    right();
    delay(500);
  }
  else if(readline_frontR == 0){
    backward();
    delay(300);
    left();
    delay(400);
  }
  else if(readline_backL == 0){
    forward();
  }

  // هجوم وتتبع
  else if(readIR_mid == HIGH){
    attack();
  }
  else if(readIR_midL == HIGH || readIR_left == HIGH){
    left();
  }
  else if(readIR_Right == HIGH || readIR_midR == HIGH){
    right();
  }
}


