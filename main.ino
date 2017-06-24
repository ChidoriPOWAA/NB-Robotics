/* NB-Robotics
 * Name: Robot One
 * Version: 1.0
 */

/****************** Headers ******************/
#include "lib/motor.h"

/*********************************************/

/* Function           A	    B
 * Direction	        D12	  D13
 * PWM	              D3	  D11
 * Brake	            D9	  D8
 * Current sensing  	A0 	  A1   (14 & 15)
 */

Motor leftMotor(12, 3, 9, 14);
Motor rightMotor(13, 11, 8, 15);

void setup()
{
  leftMotor.setup();
  rightMotor.setup();
}

void loop()
{
  leftMotor.rotate(clockwise, 100);
  rightMotor.rotate(clockwise, 100);

  delay(2500);

  leftMotor.rotate(counterClockwise, 100);
  rightMotor.rotate(counterClockwise, 100);

  delay(1000);
}