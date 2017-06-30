#ifndef ROBOT_H
#define ROBOT_H

#include "motor.h"
#include "sensors.h"

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
    Sonar * sonar_;

  public:
    Robot(Motor * leftMotor,
          Motor * rightMotor,
          Sonar * sonar);
    ~Robot();

    void setupRobot();

    void go(unsigned int speed);
    void stop();
    void reverse(unsigned int speed);
    void turn(Side side, unsigned int speed);
    void checkForObject(double maxDistance); //TODO: extract stop from func

    //TODO: remove helper functions when not needed for testing
    Sonar * getSonarHelperFunction();
};

#endif