/***************************************************************
   Motor driver function definitions - Arduino Mega
 *************************************************************/

#define RIGHT_MOTOR_FORWARD   42   // IN1
#define RIGHT_MOTOR_BACKWARD  40   // IN2
#define LEFT_MOTOR_FORWARD    41   // IN3
#define LEFT_MOTOR_BACKWARD   43   // IN4
#define RIGHT_MOTOR_ENABLE    44   // ENA (PWM)
#define LEFT_MOTOR_ENABLE     45   // ENB (PWM)

void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed);

