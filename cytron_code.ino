// Motor Driver 1 Pins (Motors 1 and 3)
#define LU_PWM 2  // Motor 1 PWM
#define LU_DIR 30 // Motor 1 Direction
#define LD_PWM 3  // Motor 2 PWM
#define LD_DIR 32 // Motor 2 Direction

// Motor Driver 2 Pins (Motors 2 and 4)
#define RU_PWM 4  // Motor 3 PWM
#define RU_DIR 34 // Motor 3 Direction
#define RD_PWM 5 // Motor 4 PWM
#define RD_DIR 36 // Motor 4 Direction

void setup() {
  // Set motor pins as output
  pinMode(LU_PWM, OUTPUT);
  pinMode(LU_DIR, OUTPUT);
  pinMode(RU_PWM, OUTPUT);
  pinMode(RU_DIR, OUTPUT);
  pinMode(LD_PWM, OUTPUT);
  pinMode(LD_DIR, OUTPUT);
  pinMode(RD_PWM, OUTPUT);
  pinMode(RD_DIR, OUTPUT);
}

void moveForward(int speed) {
  // Motor 1 - Forward
  digitalWrite(LU_DIR, HIGH);  // Set direction to forward
  analogWrite(LU_PWM, speed); // Set speed

  // Motor 2 - Forward
  digitalWrite(RU_DIR, HIGH);  // Set direction to forward
  analogWrite(RU_PWM, speed); // Set speed

  // Motor 3 - Forward
  digitalWrite(LD_DIR, LOW);  // Set direction to forward
  analogWrite(LD_PWM, speed); // Set speed

  // Motor 4 - Forward
  digitalWrite(RD_DIR, LOW);  // Set direction to forward
  analogWrite(RD_PWM, speed); // Set speed
}
void moveBackward(int speed) {
  // Motor 1 - Backward
  digitalWrite(LU_DIR, LOW);  // Set direction to Backward
  analogWrite(LU_PWM, speed); // Set speed

  // Motor 2 - Backward
  digitalWrite(RU_DIR, LOW);  // Set direction to Backward
  analogWrite(RU_PWM, speed); // Set speed

  // Motor 3 - Backward
  digitalWrite(LD_DIR, HIGH);  // Set direction to Backward
  analogWrite(LD_PWM, speed); // Set speed

  // Motor 4 - Backward
  digitalWrite(RD_DIR, HIGH);  // Set direction to Backward
  analogWrite(RD_PWM, speed); // Set speed
}
void moveRight(int speed) {
  // Motor 1 - Right
  digitalWrite(LU_DIR, HIGH);  // Set direction to Right
  analogWrite(LU_PWM, speed); // Set speed

  // Motor 2 - Right
  digitalWrite(RU_DIR, LOW);  // Set direction to Right
  analogWrite(RU_PWM, speed); // Set speed

  // Motor 3 - Right
  digitalWrite(LD_DIR, HIGH);  // Set direction to Right
  analogWrite(LD_PWM, speed); // Set speed

  // Motor 4 - Right
  digitalWrite(RD_DIR, LOW);  // Set direction to Right
  analogWrite(RD_PWM, speed); // Set speed
}
void moveLeft(int speed) {
  // Motor 1 - Left
  digitalWrite(LU_DIR, LOW);  // Set direction to Left
  analogWrite(LU_PWM, speed); // Set speed

  // Motor 2 - Left
  digitalWrite(RU_DIR, HIGH);  // Set direction to Left
  analogWrite(RU_PWM, speed); // Set speed

  // Motor 3 - Left
  digitalWrite(LD_DIR, LOW);  // Set direction to Left
  analogWrite(LD_PWM, speed); // Set speed

  // Motor 4 - Left
  digitalWrite(RD_DIR, HIGH);  // Set direction to Left
  analogWrite(RD_PWM, speed); // Set speed
}
void moveClock(int speed) {
  // Motor 1 - Clockwise
  digitalWrite(LU_DIR, HIGH);  // Set direction to Clockwise
  analogWrite(LU_PWM, speed); // Set speed

  // Motor 2 - Clockwise
  digitalWrite(RU_DIR, LOW);  // Set direction to Clockwise
  analogWrite(RU_PWM, speed); // Set speed

  // Motor 3 - Clockwise
  digitalWrite(LD_DIR, LOW);  // Set direction to Clockwise
  analogWrite(LD_PWM, speed); // Set speed

  // Motor 4 - Clockwise
  digitalWrite(RD_DIR, HIGH);  // Set direction to Clockwise
  analogWrite(RD_PWM, speed); // Set speed
}
void moveAnti(int speed) {
  // Motor 1 - AntiClockwise
  digitalWrite(LU_DIR, LOW);  // Set direction to AntiClockwise
  analogWrite(LU_PWM, speed); // Set speed

  // Motor 2 - AntiClockwise
  digitalWrite(RU_DIR, HIGH);  // Set direction to AntiClockwise
  analogWrite(RU_PWM, speed); // Set speed

  // Motor 3 - AntiClockwise
  digitalWrite(LD_DIR, HIGH);  // Set direction to AntiClockwise
  analogWrite(LD_PWM, speed); // Set speed

  // Motor 4 - AntiClockwise
  digitalWrite(RD_DIR, LOW);  // Set direction to AntiClockwise
  analogWrite(RD_PWM, speed); // Set speed
}
void loop() {
  // Test all movements with speed 150 for 2 seconds each

  // Move forward with speed 150
  moveForward(150);
  delay(2000);  

  // Move backward with speed 150
  moveBackward(150);
  delay(2000);  

  // Move right with speed 150
  moveRight(150);
  delay(2000); 

  // Move left with speed 150
  moveLeft(150);
  delay(2000);

  // Rotate clockwise with speed 150
  moveClock(150);
  delay(2000);

  // Rotate counterclockwise with speed 150
  moveAnti(150);
  delay(2000);
}

