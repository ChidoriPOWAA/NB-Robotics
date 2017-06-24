#include "Arduino.h"
#include "lib/motor.h"

/* Function: Motor constructor
 * Brief: creates Motor object and initializes pins
 */
Motor::Motor(const int directionPin,
             const int pwmPin,
             const int brakePin,
             const int currentSensingPin)
  : directionPin_(directionPin),
    pwmPin_(pwmPin),
    brakePin_(brakePin),
    currentSensingPin_(currentSensingPin)
{
}

/* Function: setup
 * Brief: prepares the motor for use
 */
void Motor::setup()
{
  pinMode(directionPin_, OUTPUT);
  pinMode(pwmPin_, OUTPUT);
  pinMode(brakePin_, OUTPUT);
  pinMode(currentSensingPin_, INPUT);

  // make sure motor is idle
  analogWrite(pwmPin_, 0);
}

/* Function: rotate
 * Brief: rotates wheel in the specified direction and speed
 */
void Motor::rotate(Direction direction, int speed)
{
  speed = constrain(speed, 0, 255);
  speed = map(speed, 0, 255, 0, 100);

  digitalWrite(brakePin_, LOW);
  digitalWrite(directionPin_, direction);
  analogWrite(pwmPin_, speed);
}
