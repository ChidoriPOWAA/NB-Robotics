/* NB-Robotics
 * Name: Robot One
 * Version: 1.0
 */

/****************** Headers ******************/
#include "lib/motor.h"
#include "lib/robot.h"

/*********************************************/

/* Function           A	    B
 * Direction	        D12	  D13
 * PWM	              D3	  D11
 * Brake	            D9	  D8
 * Current sensing  	A0 	  A1   (14 & 15)
 */

Robot robotOne(new Motor(12, 3, 9, 14), new Motor(13, 11, 8, 15));

void setup()
{
  robotOne.setupRobot();
}

void loop()
{
  //TODO: Write awesome program
}