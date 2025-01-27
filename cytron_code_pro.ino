#define MAX_SPEED 228 

 #define LU_PWM 2  
 #define LU_DIR 30 
 #define LD_PWM 3  
 #define LD_DIR 32 

 #define RU_PWM 4  
 #define RU_DIR 34 
 #define RD_PWM 5 
 #define RD_DIR 36 

 #define MU_PWM 6  
 #define MU_DIR 38
 #define MD_PWM 7
 #define MD_DIR 40

void setup() {

  pinMode(LU_PWM, OUTPUT);
  pinMode(LU_DIR, OUTPUT);
  pinMode(RU_PWM, OUTPUT);
  pinMode(RU_DIR, OUTPUT);
  pinMode(LD_PWM, OUTPUT);
  pinMode(LD_DIR, OUTPUT);
  pinMode(RD_PWM, OUTPUT);
  pinMode(RD_DIR, OUTPUT);
  pinMode(MU_PWM, OUTPUT);
  pinMode(MU_DIR, OUTPUT);
  pinMode(MD_PWM, OUTPUT);
  pinMode(MD_DIR, OUTPUT);
}

int calculateSpeed(int percentage) {
  int result=0;
  if(percentage >= 100){
    result =  MAX_SPEED;}
  else{
    result = (percentage * MAX_SPEED) / 100;}
  return result;
}

void stopAll() {
  analogWrite(LU_PWM, 0);
  analogWrite(RU_PWM, 0);
  analogWrite(LD_PWM, 0);
  analogWrite(RD_PWM, 0);
  analogWrite(MU_PWM, 0);
  analogWrite(MD_PWM, 0);
  delay (1500);
}

void moveForward(int speed) {
  int pwmSpeed = calculateSpeed(speed);
  digitalWrite(LU_DIR, HIGH);  
  analogWrite(LU_PWM, pwmSpeed); 

  digitalWrite(RU_DIR, HIGH);  
  analogWrite(RU_PWM, pwmSpeed); 

  digitalWrite(LD_DIR, LOW);  
  analogWrite(LD_PWM, pwmSpeed); 

  digitalWrite(RD_DIR, LOW);  
  analogWrite(RD_PWM, pwmSpeed); 
}

void moveBackward(int speed) {
  int pwmSpeed = calculateSpeed(speed);
  digitalWrite(LU_DIR, LOW);  
  analogWrite(LU_PWM, pwmSpeed); 

  digitalWrite(RU_DIR, LOW);  
  analogWrite(RU_PWM, pwmSpeed); 

  digitalWrite(LD_DIR, HIGH);  
  analogWrite(LD_PWM, pwmSpeed); 

  digitalWrite(RD_DIR, HIGH);  
  analogWrite(RD_PWM, pwmSpeed); 
}

void moveRight(int speed) {
  int pwmSpeed = calculateSpeed(speed);
  digitalWrite(LU_DIR, HIGH);  
  analogWrite(LU_PWM, pwmSpeed); 

  digitalWrite(RU_DIR, LOW);  
  analogWrite(RU_PWM, pwmSpeed); 

  digitalWrite(LD_DIR, HIGH);  
  analogWrite(LD_PWM, pwmSpeed); 

  digitalWrite(RD_DIR, LOW);  
  analogWrite(RD_PWM, pwmSpeed); 
}

void moveLeft(int speed) {
  int pwmSpeed = calculateSpeed(speed);
  digitalWrite(LU_DIR, LOW);  
  analogWrite(LU_PWM, pwmSpeed); 

  digitalWrite(RU_DIR, HIGH);  
  analogWrite(RU_PWM, pwmSpeed); 

  digitalWrite(LD_DIR, LOW);  
  analogWrite(LD_PWM, pwmSpeed); 

  digitalWrite(RD_DIR, HIGH);  
  analogWrite(RD_PWM, pwmSpeed); 
}

void moveClock(int speed) {
  int pwmSpeed = calculateSpeed(speed);
  digitalWrite(LU_DIR, HIGH);  
  analogWrite(LU_PWM, pwmSpeed); 

  digitalWrite(RU_DIR, LOW);  
  analogWrite(RU_PWM, pwmSpeed); 

  digitalWrite(LD_DIR, LOW);  
  analogWrite(LD_PWM, pwmSpeed); 

  digitalWrite(RD_DIR, HIGH);  
  analogWrite(RD_PWM, pwmSpeed); 
}

void moveAnti(int speed) {
  
  int pwmSpeed = calculateSpeed(speed);
  
  digitalWrite(LU_DIR, LOW);  
  analogWrite(LU_PWM, pwmSpeed); 

  digitalWrite(RU_DIR, HIGH);  
  analogWrite(RU_PWM, pwmSpeed); 

  digitalWrite(LD_DIR, HIGH);  
  analogWrite(LD_PWM, pwmSpeed); 

  digitalWrite(RD_DIR, LOW); 
  analogWrite(RD_PWM, pwmSpeed); 
}
void movefrontup(int speed) {
  
  int pwmSpeed = calculateSpeed(speed);
  
  digitalWrite(MU_DIR, HIGH);  
  analogWrite(MU_PWM, pwmSpeed); 

  digitalWrite(MD_DIR, LOW);  
  analogWrite(MD_PWM, pwmSpeed); 

}
void movefrontdown(int speed) {
  
  int pwmSpeed = calculateSpeed(speed);
  
  digitalWrite(MU_DIR, LOW);  
  analogWrite(MU_PWM, pwmSpeed); 

  digitalWrite(MD_DIR, HIGH);  
  analogWrite(MD_PWM, pwmSpeed); 

}
void loop() {
  moveForward(100); //from 0% to 100% 
  delay(2000);  
  stopAll();

  moveBackward(150);//from 0% to 100% 
  delay(2000);  
  stopAll();

  moveForward(19);//from 0% to 100% 
  delay(2000);
  stopAll();

  moveBackward(23);//from 0% to 100% 
  delay(2000);
   stopAll();

  moveRight(50);//from 0% to 100% 
  delay(2000); 
  stopAll();

  moveLeft(35);//from 0% to 100% 
  delay(2000);
  stopAll();

  moveClock(80);//from 0% to 100% 
  delay(2000);
  stopAll();

  moveAnti(69);//from 0% to 100% 
  delay(2000);
  stopAll();

  movefrontup(73);//from 0% to 100% 
  delay(2000);
  stopAll();

  movefrontdown(91);//from 0% to 100% 
  delay(2000);
  stopAll();

exit(0);
}
