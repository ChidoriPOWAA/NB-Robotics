/* NB-Robotics
 * Name: Robot One
 * Version: 1.0
 */

/****************** Headers ******************/
#include "lib/motor.h"
#include "lib/robot.h"
#include "lib/sensors.h"

/*********************************************/

/* Function           A	    B
 * Direction	        D12	  D13
 * PWM	              D3	  D11
 * Brake	            D9	  D8
 * Current sensing  	A0 	  A1   (14 & 15)
 */

Motor * leftMotor = new Motor(12, 3, 9, 14);
Motor * rightMotor = new Motor(13, 11, 8, 15);

const int triggerPin = 10;
const int echoPin = 7;
const int maxDistance = 200;
Sonar * sonar = new Sonar(new NewPing(triggerPin, echoPin, maxDistance));

Robot robotOne(leftMotor,
               rightMotor,
               sonar);

unsigned long delayInMs = 2000;
unsigned int speed = 100;

void setup()
{
  robotOne.setupRobot();

  Serial.begin(9600);
}

void loop()
{
  //TODO: Write awesome program

  double distanceInCm;
  distanceInCm = robotOne.getSonarHelperFunction()->readDistanceInCm();
  Serial.print("cm: ");
  Serial.println(distanceInCm);
  delay(250);
}