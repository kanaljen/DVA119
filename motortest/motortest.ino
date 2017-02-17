#include <Adafruit_MotorShield.h>
#include <lenlib.h> 
#include <Servo.h> 
#include <Wire.h> 

int speedR = 0;
int speedL = 0;


mySensors Sensors; // create Sensors object
myMotors Motors;  // create Motors object
//Motor 1: right, Motor 2: left

void setup() 
{ 
  Motors.beginMotors();   // start motors
  Sensors.beginSensors(); // start sensors
}

void loop() 
{
  line_follower();
}


void line_follower() 
{
speedR = 100;
speedL = 94;

      Motors.runMotor(1, FORWARD, speedR);
  
      Motors.runMotor(2, FORWARD, speedL);
 
}
