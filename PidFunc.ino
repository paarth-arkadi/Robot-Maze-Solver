const int power = 255;
const int iniMotorPower = 127;
const int adj = 1;
float adjTurn = 8;

// PID controller
float Kp=50;
float Ki=0;
float Kd=0;
float error=0, P=0, I=0, D=0, PIDvalue=0;
float previousError=0, previousI=0;

void calculatePID()
{
  P = error;
  I = I + error;
  D = error-previousError;
  PIDvalue = (Kp*P) + (Ki*I) + (Kd*D);
  previousError = error;
}

void checkPIDvalues()
{
  Serial.print("PID: ");
  Serial.print(Kp);
  Serial.print(" - ");
  Serial.print(Ki);
  Serial.print(" - ");
  Serial.println(Kd);  
  
}

void testLineFollowSensors()
{
     int LFS0 = a2d(lineFollowSensor0);
     int LFS1 = a2d(lineFollowSensor1);
     int LFS2 = a2d(lineFollowSensor2);
     int LFS3 = a2d(lineFollowSensor3);
     int LFS4 = a2d(lineFollowSensor4);
     Serial.print ("LFS: L  0 1 2 3 4  R ==> "); 
     Serial.print (LFS0); 
     Serial.print (" ");
     Serial.print (LFS1); 
     Serial.print (" ");
     Serial.print (LFS2); 
     Serial.print (" ");
     Serial.print (LFS3); 
     Serial.print (" ");
     Serial.print (LFS4); 
     Serial.print ("  ==> ");
     Serial.print (" P: ");
     Serial.print (P);
     Serial.print (" I: ");
     Serial.print (I);
     Serial.print (" D: ");
     Serial.print (D);
     Serial.print (" PID: ");
     Serial.println (PIDvalue);
}
