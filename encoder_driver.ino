/* *************************************************************
   Encoder definitions for Arduino Mega 2560
   ************************************************************ */

#ifdef USE_BASE

#ifdef ARDUINO_ENC_COUNTER

volatile long left_enc_pos = 0L;
volatile long right_enc_pos = 0L;

// --------- Xử lý Encoder Trái ------------
void leftEncoderEventA() {
  if (digitalRead(LEFT_ENC_PIN_A) == digitalRead(LEFT_ENC_PIN_B)) {
    left_enc_pos++;
  } else {
    left_enc_pos--;
  }
}

void leftEncoderEventB() {
  if (digitalRead(LEFT_ENC_PIN_A) != digitalRead(LEFT_ENC_PIN_B)) {
    left_enc_pos++;
  } else {
    left_enc_pos--;
  }
}

// --------- Xử lý Encoder Phải ------------
void rightEncoderEventA() {
  if (digitalRead(RIGHT_ENC_PIN_A) == digitalRead(RIGHT_ENC_PIN_B)) {
    right_enc_pos++;
  } else {
    right_enc_pos--;
  }
}

void rightEncoderEventB() {
  if (digitalRead(RIGHT_ENC_PIN_A) != digitalRead(RIGHT_ENC_PIN_B)) {
    right_enc_pos++;
  } else {
    right_enc_pos--;
  }
}

// --------- Hàm đọc encoder ------------
long readEncoder(int i) {
  if (i == LEFT) return left_enc_pos;
  else return right_enc_pos;
}

// --------- Reset 1 encoder ------------
void resetEncoder(int i) {
  if (i == LEFT) {
    left_enc_pos = 0L;
  } else {
    right_enc_pos = 0L;
  }
}

// --------- Reset cả 2 encoder ------------
void resetEncoders() {
  resetEncoder(LEFT);
  resetEncoder(RIGHT);
}

#endif  // ARDUINO_ENC_COUNTER

#endif  // USE_BASE
