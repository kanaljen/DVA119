#include <Adafruit_MotorShield.h>
#include <lenlib.h> 
#include <Servo.h> 
#include <Wire.h> 

byte R0Val = 0;
byte R1Val = 0;
byte R2Val = 0;
byte r_speed = 0;
byte l_speed = 0;
byte r_gear = 0;
byte l_gear = 0;
byte low_speed = 130;
byte high_speed = 150;

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
  
  R0Val  = Sensors.readReflect0(); // Read digital value of reflect sensor 0 (right)
  R1Val  = Sensors.readReflect1(); // Read digital value of reflect sensor 1 (middle)
  R2Val  = Sensors.readReflect2(); // Read digital value of reflect sensor 2 (left)

//----------------------------------------------------------------------------------
  if (R2Val == 0 && R1Val == 1 && R0Val == 0)
  {
      r_gear = 1;
      l_gear = 1;
      r_speed = high_speed;
      l_speed = high_speed;
  }

//----------------------------------------------------------------------------------
  if (R2Val == 1 && R1Val == 0 && R0Val == 0)
  {
      r_gear = 1;
      l_gear = 0;
      r_speed = low_speed;
      l_speed = low_speed;
  }

  //----------------------------------------------------------------------------------
  if (R2Val == 1 && R1Val == 1 && R0Val == 0)
  {
      r_gear = 1;
      l_gear = 1;
      r_speed = high_speed;
      l_speed = low_speed;
  }

//----------------------------------------------------------------------------------
  if (R2Val == 0 && R1Val == 0 && R0Val == 1)
  {     
      r_gear = 0;
      l_gear = 1;
      r_speed = low_speed;
      l_speed = low_speed;
  }

//----------------------------------------------------------------------------------
  if (R2Val == 0 && R1Val == 1 && R0Val == 1)
  {   
      r_gear = 1;
      l_gear = 1;
      r_speed = low_speed;
      l_speed = high_speed;
  }

//Motors-----------------------------------------------------------------------------

if (r_gear == 1)
  {
      Motors.runMotor(1, FORWARD, r_speed);
  }

if (r_gear == 0)
  {
      Motors.runMotor(1, BACKWARD, r_speed);
  }

if (l_gear == 1)
  {
      Motors.runMotor(2, FORWARD, l_speed);
  }

if (l_gear == 0)
  {
      Motors.runMotor(2, BACKWARD, l_speed);
  }




  
}
