#include <AFMotor.h>
AF_DCMotor leftMotor(2);
AF_DCMotor rightMotor(3);

void motorStop()
{
  leftMotor.run(RELEASE);
  rightMotor.run(RELEASE);
  delay(200);
}
void motorForward()
{
  leftMotor.run(FORWARD);
  leftMotor.setSpeed(power);
  rightMotor.run(FORWARD);
  rightMotor.setSpeed(power*adj);
}
void motorBackward()
{ 
  leftMotor.run(BACKWARD);
  leftMotor.setSpeed(power);
  rightMotor.run(BACKWARD);
  rightMotor.setSpeed(power);
}
void motorFwTime (unsigned int time)
{
  motorForward();
  delay (time);
  motorStop();
}
void motorBwTime (unsigned int time)
{
  motorBackward();
  delay (time);
  motorStop();
}
void motorTurn(unsigned int direction, int degrees)
{
  switch(direction)
  {
    case 1:
    //Turn Right
    rightMotor.run(BACKWARD);
    rightMotor.setSpeed(iniMotorPower);
    leftMotor.run(FORWARD);
    leftMotor.setSpeed(iniMotorPower);
    case -1:
    //Turn Left
    leftMotor.run(BACKWARD);
    leftMotor.setSpeed(iniMotorPower);
    rightMotor.run(FORWARD);
    rightMotor.setSpeed(iniMotorPower);
  }
  delay (round(adjTurn*degrees+1));
  motorStop();
}

//Pid Motor Controls
void motorPIDcontrol()
{
  int leftMotorSpeed = iniMotorPower - PIDvalue;
  int rightMotorSpeed =iniMotorPower*adj - PIDvalue;
  // The motor speed should not exceed the max PWM value
   constrain(leftMotorSpeed, 0, 255);
   constrain(rightMotorSpeed, 0, 255);
  leftMotor.run(FORWARD);
  leftMotor.setSpeed(leftMotorSpeed);
  rightMotor.run(FORWARD);
  rightMotor.run(rightMotorSpeed);
  Serial.print (PIDvalue);
  Serial.print (" ==> Left, Right:  ");
  Serial.print (leftMotorSpeed);
  Serial.print ("   ");
  Serial.println (rightMotorSpeed);
}
