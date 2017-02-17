#include <Adafruit_MotorShield.h>
#include <lenlib.h> 
#include <Servo.h> 
#include <Wire.h> 

int acc_y = 0;
int acc_x = 0;

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
  scan();
  line_follower();
}

void scan() 
{
  acc_y  = Sensors.readAccY();
  acc_x  = Sensors.readAccX();
}

void line_follower() 
{
  
int r_speed = 0;
int l_speed = 0;




if (acc_y <= 330 && acc_y >= 320)
  {
      r_speed = 170;
      l_speed = 94;
  }
//----------------------------------------------------------------------------------
  if (acc_y < 320)
  {     
      r_speed = 0;
      l_speed = 94;
  }

//----------------------------------------------------------------------------------
  if (acc_y > 330)
  {     
      r_speed = 170;
      l_speed = 0;
  }

//Motors-----------------------------------------------------------------------------


      Motors.runMotor(1, FORWARD, r_speed);
      Motors.runMotor(2, FORWARD, l_speed);
 
}
