/* *************************************************************
   Encoder driver function definitions - Mega2560 version
   ************************************************************ */

#ifdef ARDUINO_ENC_COUNTER
  // ----- Encoder trái -----
  #define LEFT_ENC_PIN_A 2    // INT0
  #define LEFT_ENC_PIN_B 3    // INT1

  // ----- Encoder phải -----
  #define RIGHT_ENC_PIN_A 18  // INT5
  #define RIGHT_ENC_PIN_B 19  // INT4
#endif

long readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();
