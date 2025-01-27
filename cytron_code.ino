// Motor Driver 1 Pins (Motors 1 and 3)
#define LU_PWM 3  // Motor 1 PWM
#define LU_DIR 4  // Motor 1 Direction
#define LD_PWM 5  // Motor 2 PWM
#define LD_DIR 6  // Motor 2 Direction

// Motor Driver 2 Pins (Motors 2 and 4)
#define RU_PWM 9  // Motor 3 PWM
#define RU_DIR 10 // Motor 3 Direction
#define RD_PWM 11 // Motor 4 PWM
#define RD_DIR 12 // Motor 4 Direction

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
void movebackward(int speed) {
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
void moveright(int speed) {
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
void moveleft(int speed) {
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
void moveclock(int speed) {
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
void moveanti(int speed) {
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
