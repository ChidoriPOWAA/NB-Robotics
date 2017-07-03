#ifndef ROBOT_H
#define ROBOT_H

#include <SoftwareSerial.h>

#include "Motor.h"
#include "Sonar.h"

enum Side
{
  left,
  right
};

enum State
{
  stopped,
  moving,
  turning
};

class Robot
{
  private:
    Motor * leftMotor_;
    Motor * rightMotor_;
    Sonar * sonar_;
    SoftwareSerial * serial_;
    State state_;
    int speed_ = 100;

  public:
    Robot();
    ~Robot();

    void initMotors(Motor * leftMotor, Motor * rightMotor);
    void initSonar(Sonar * sonar);
    void enableRemoteControl(SoftwareSerial * serial);
    void setSpeed(int speed);

    void go();
    void stop();
    void reverse();
    void turn(Side side);
    bool isClearPath(double minFreePath);
    void runObstacleAvoidingAlgorithm(); // WIP
    char getSerialCommand();

    void runBlueStickCommand();

    //TODO: remove helper functions when not needed for testing
    Sonar * getSonarHelperFunction();
};

#endif