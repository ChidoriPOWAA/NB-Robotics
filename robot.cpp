#include "lib/robot.h"

/* Function: Robot
 * Brief: Robot constructor
 */
Robot::Robot(Motor * leftMotor, Motor * rightMotor, Sonar * sonar)
{
  leftMotor_ = leftMotor;
  rightMotor_ = rightMotor;
  sonar_ = sonar;
}

/* Function: ~Robot
 * Brief: Robot destructor
 */
Robot::~Robot()
{
  delete leftMotor_;
  delete rightMotor_;
  delete sonar_;
}

/* Function: setupRobot
 * Brief: setup left and right motors
 */
void Robot::setupRobot()
{
  leftMotor_->setupMotor();
  rightMotor_->setupMotor();
}

/* Function: go
 * Brief: run Robot forwards in given speed
 */
void Robot::go(unsigned int speed)
{
  leftMotor_->rotate(counterClockwise, speed);
  rightMotor_->rotate(clockwise, speed);
}

/* Function: stop
 * Brief: hit the brakes on both motors
 */
void Robot::stop()
{
  leftMotor_->brake();
  rightMotor_->brake();
}

/* Function: reverse
 * Brief: run the robot backwards
 */
void Robot::reverse(unsigned int speed)
{
  leftMotor_->rotate(clockwise, speed);
  rightMotor_->rotate(counterClockwise, speed);
}

/* Function: turn
 * Brief: turn robot to either side
 */
void Robot::turn(Side side, unsigned int speed)
{
  if (side == left)
  {
    leftMotor_->rotate(clockwise, speed);
    rightMotor_->rotate(clockwise, speed);
  }
  else if (side == right)
  {
    leftMotor_->rotate(counterClockwise, speed);
    rightMotor_->rotate(counterClockwise, speed);
  }
}

void Robot::checkForObject(double maxDistanceInCm)
{
  double distanceToNearestObject = sonar_->readDistanceInCm();
  if (distanceToNearestObject < maxDistanceInCm)
  {
    Robot::stop();
  }
}

Sonar * Robot::getSonarHelperFunction()
{
  return sonar_;
}