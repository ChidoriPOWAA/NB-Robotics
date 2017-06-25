#ifndef ROBOT_H
#define ROBOT_H

#include "motor.h"

enum Side
{
  left,
  right
};

class Robot
{
  private:
    Motor * leftMotor_;
    Motor * rightMotor_;

  public:
    Robot(Motor * leftMotor, Motor * rightMotor);
    ~Robot();

    void setupRobot();

    void go(int speed);
    void reverse(int speed);
    void turn(Side side, int speed);
};

#endif