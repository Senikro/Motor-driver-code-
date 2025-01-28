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
  percentage = constrain(percentage, -100, 100); // Ensure percentage is within -100 to 100
  int result; 
  if (percentage>=100){
    result = MAX_SPEED ;
    }
  else if (percentage<=-100){
    result = MAX_SPEED;
    }
  else {result = (abs(percentage) * MAX_SPEED) / 100;
  }
    return result;
}

void stopAll() {
  analogWrite(LU_PWM, 0);
  analogWrite(RU_PWM, 0);
  analogWrite(LD_PWM, 0);
  analogWrite(RD_PWM, 0);
  analogWrite(MU_PWM, 0);
  analogWrite(MD_PWM, 0);
  delay(1500);
}

void y_axis(int percentage) {
  int pwmSpeed = calculateSpeed(percentage);
  if (percentage > 0) { // Move forward
    digitalWrite(LU_DIR, HIGH);
    digitalWrite(RU_DIR, HIGH);
    digitalWrite(LD_DIR, LOW);
    digitalWrite(RD_DIR, LOW);
  } else { // Move backward
    digitalWrite(LU_DIR, LOW);
    digitalWrite(RU_DIR, LOW);
    digitalWrite(LD_DIR, HIGH);
    digitalWrite(RD_DIR, HIGH);
  }
  analogWrite(LU_PWM, pwmSpeed);
  analogWrite(RU_PWM, pwmSpeed);
  analogWrite(LD_PWM, pwmSpeed);
  analogWrite(RD_PWM, pwmSpeed);
}

void x_axis(int percentage) {
  int pwmSpeed = calculateSpeed(percentage);
  if (percentage > 0) { // Move right
    digitalWrite(LU_DIR, HIGH);
    digitalWrite(RU_DIR, LOW);
    digitalWrite(LD_DIR, HIGH);
    digitalWrite(RD_DIR, LOW);
  } else { // Move left
    digitalWrite(LU_DIR, LOW);
    digitalWrite(RU_DIR, HIGH);
    digitalWrite(LD_DIR, LOW);
    digitalWrite(RD_DIR, HIGH);
  }
  analogWrite(LU_PWM, pwmSpeed);
  analogWrite(RU_PWM, pwmSpeed);
  analogWrite(LD_PWM, pwmSpeed);
  analogWrite(RD_PWM, pwmSpeed);
}
void tilt(int percentage) {
int pwmSpeed = calculateSpeed( percentage);
  if (percentage > 0) { // TILT
     digitalWrite(MU_DIR, HIGH);  
      analogWrite(MU_PWM, pwmSpeed); 
     digitalWrite(MD_DIR, LOW);  
      analogWrite(MD_PWM, pwmSpeed); 
  } else { // TILT
    digitalWrite(MU_DIR, LOW);  
     analogWrite(MU_PWM, pwmSpeed); 
    digitalWrite(MD_DIR, HIGH);  
     analogWrite(MD_PWM, pwmSpeed); 
  }
  analogWrite(MU_PWM, pwmSpeed);
  analogWrite(MU_PWM, pwmSpeed);
}
void rotate(int percentage){
int pwmSpeed = calculateSpeed( percentage);
if(percentage > 0){ //CLOCKWISE
digitalWrite(LU_DIR, HIGH);
digitalWrite(RU_DIR, LOW);
digitalWrite(LD_DIR, LOW);
digitalWrite(RD_DIR, HIGH);
}
else {//Anti_CLOCKWISE
digitalWrite(LU_DIR, LOW);
digitalWrite(RU_DIR, HIGH);
digitalWrite(LD_DIR, HIGH);
digitalWrite(RD_DIR, LOW);
}
analogWrite(LU_DIR, pwmSpeed);
analogWrite(RU_DIR, pwmSpeed);
analogWrite(LD_DIR, pwmSpeed);
analogWrite(RD_DIR, pwmSpeed);
}
void loop() {
  y_axis(90); //from 0% to 100% 
  delay(2000);  
  stopAll();

  y_axis(-80);//from 0% to 100% 
  delay(2000);  
  stopAll();

  x_axis(60);//from 0% to 100% 
  delay(2000);
  stopAll();

  x_axis(-50);//from 0% to 100% 
  delay(2000);
   stopAll();

  tilt(45);//from 0% to 100% 
  delay(2000); 
  stopAll();

  tilt(-37);//from 0% to 100% 
  delay(2000);
  stopAll();

  y_axis(93);//from 0% to 100% 
  delay(2000);
  stopAll();

  x_axis(76);//from 0% to 100% 
  delay(2000);
  stopAll();

  tilt(-120);//from 0% to 100% 
  delay(2000);
  stopAll();

  tilt(69);//from 0% to 100% 
  delay(2000);
  stopAll();
  
  rotate(150);//from 0% to 100%
  delay(2000);
  stopAll();

  rotate(-150);//from 0% to 100%
  delay(2000);
  stopAll();

  rotate(69);//from 0% to 100%
  delay(2000);
  stopAll(); 

  rotate(-69);//from 0% to 100%
  delay(2000);
  stopAll();

exit(0);
}
