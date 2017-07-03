/* NB-Robotics
 * Name: Robot One
 * Version: 1.0
 */

/****************** Headers ******************/
#include <SoftwareSerial.h>

#include "lib/Motor.h"
#include "lib/Robot.h"
#include "lib/Sonar.h"

/*************** Robot objects ***************/

#define BT_RX_PIN 16
#define BT_TX_PIN 17

SoftwareSerial * serial = new SoftwareSerial(BT_RX_PIN, BT_TX_PIN);

/** Motor schematics
 * Function           A	    B
 * Direction	        D12	  D13
 * PWM	              D3	  D11
 * Brake	            D9	  D8
 * Current sensing  	A0 	  A1   (14 & 15)
 */

Motor * leftMotor = new Motor(12, 3, 9, 14);
Motor * rightMotor = new Motor(13, 11, 8, 15);

const int triggerPin = 10;
const int echoPin = 7;
const int maxDistanceInCm = 200;
Sonar * sonar = new Sonar(new NewPing(triggerPin, echoPin, maxDistanceInCm));

/* It's alive! */
Robot robotOne;

void setup()
{
  robotOne.initMotors(leftMotor, rightMotor);
  robotOne.initSonar(sonar);
  robotOne.enableRemoteControl(serial);
  delay(5000); // some start-up margin
}

void loop()
{
  //TODO: Write awesome program
  robotOne.runBlueStickCommand();
  delay(25);
  robotOne.stop();
  delay(25);
}
