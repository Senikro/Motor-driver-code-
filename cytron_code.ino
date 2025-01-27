#define MAX_SPEED 228 

 #define LU_PWM 2  
 #define LU_DIR 30 
 #define LD_PWM 3  
 #define LD_DIR 32 

#define RU_PWM 4  
#define RU_DIR 34 
#define RD_PWM 5 
#define RD_DIR 36 

void setup() {

  pinMode(LU_PWM, OUTPUT);
  pinMode(LU_DIR, OUTPUT);
  pinMode(RU_PWM, OUTPUT);
  pinMode(RU_DIR, OUTPUT);
  pinMode(LD_PWM, OUTPUT);
  pinMode(LD_DIR, OUTPUT);
  pinMode(RD_PWM, OUTPUT);
  pinMode(RD_DIR, OUTPUT);
}

int calculateSpeed(int percentage) {
  int result=0;
  if(percentage >= 100){
   result =  MAX_SPEED;}
   else{
  result = (percentage * MAX_SPEED) / 100;}
  return result;
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

void loop() {

  moveForward(100);
  delay(2000);  

  moveBackward(150);
  delay(2000);  

  moveRight(50);
  delay(2000); 

  moveLeft(35);
  delay(2000);

  moveClock(80);
  delay(2000);

  moveAnti(69);
  delay(2000);
}
