/***************************************************************
   Motor driver implementation - Arduino Mega
 *************************************************************/

#ifdef USE_BASE

void initMotorController() {
  // Cấu hình chân điều khiển motor
  pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_BACKWARD, OUTPUT);
  pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
  pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);

  pinMode(RIGHT_MOTOR_ENABLE, OUTPUT);
  pinMode(LEFT_MOTOR_ENABLE, OUTPUT);

  // Ban đầu dừng motor
  analogWrite(RIGHT_MOTOR_ENABLE, 0);
  analogWrite(LEFT_MOTOR_ENABLE, 0);
}

void setMotorSpeed(int i, int spd) {
  unsigned char reverse = 0;

  if (spd < 0) {
    spd = -spd;
    reverse = 1;
  }
  if (spd > 255)
    spd = 255;

  if (i == LEFT) {  
    if (reverse == 0) {
      digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
      digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
    } else {
      digitalWrite(LEFT_MOTOR_FORWARD, LOW);
      digitalWrite(LEFT_MOTOR_BACKWARD, HIGH);
    }
    analogWrite(LEFT_MOTOR_ENABLE, spd);
  } else if (i == RIGHT) {
    if (reverse == 0) {
      digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
      digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
    } else {
      digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
      digitalWrite(RIGHT_MOTOR_BACKWARD, HIGH);
    }
    analogWrite(RIGHT_MOTOR_ENABLE, spd);
  }
}

void setMotorSpeeds(int leftSpeed, int rightSpeed) {
  setMotorSpeed(LEFT, leftSpeed);
  setMotorSpeed(RIGHT, rightSpeed);
}

#endif
