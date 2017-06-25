#include "lib/robot.h"

Robot::Robot(Motor * leftMotor, Motor * rightMotor)
{
  leftMotor_ = leftMotor;
  rightMotor_ = rightMotor;
}

Robot::~Robot()
{
  delete leftMotor_;
  delete rightMotor_;
}

void Robot::setupRobot()
{
  leftMotor_->setupMotor();
  rightMotor_->setupMotor();
}

void Robot::go(int speed)
{
  leftMotor_->rotate(counterClockwise, speed);
  rightMotor_->rotate(clockwise, speed);
}

void Robot::reverse(int speed)
{
  leftMotor_->rotate(clockwise, speed);
  rightMotor_->rotate(counterClockwise, speed);
}

void Robot::turn(Side side, int speed)
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