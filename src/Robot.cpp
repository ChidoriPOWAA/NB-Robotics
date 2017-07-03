#include "../lib/Robot.h"

/* Function: Robot
 * Brief: Robot constructor
 */
Robot::Robot()
{
  state_ = stopped;
}

/* Function: ~Robot
 * Brief: Robot destructor
 */
Robot::~Robot()
{
  if (leftMotor_ != NULL &&
      rightMotor_ != NULL)
  {
    delete leftMotor_;
    delete rightMotor_;
  }
  if (sonar_ != NULL)
  {
    delete sonar_;
  }
  if (serial_ != NULL)
  {
    delete serial_;
  }
}

/* Function: initMotors
 * Brief: setup left and right motors
 */
void Robot::initMotors(Motor * leftMotor, Motor * rightMotor)
{
  leftMotor_ = leftMotor;
  rightMotor_ = rightMotor;

  leftMotor_->setupMotor();
  rightMotor_->setupMotor();
}

/* Function: initSonar
 * Brief: setup sonar
 */
void Robot::initSonar(Sonar * sonar)
{
  sonar_ = sonar;
}

/* Function: enableRemoteControl
 * Brief: enable Serial connection
 */
void Robot::enableRemoteControl(SoftwareSerial * serial)
{
  serial_ = serial;
  serial_->begin(9600);
}

/* Function: setSpeed
 * Brief: set integral robot speed
 */
void Robot::setSpeed(int speed)
{
  speed_ = speed;
}

/* Function: go
 * Brief: run Robot forwards
 */
void Robot::go()
{
  leftMotor_->rotate(counterClockwise, speed_);
  rightMotor_->rotate(clockwise, speed_);
  state_ = moving;
}

/* Function: stop
 * Brief: hit the brakes on both motors
 */
void Robot::stop()
{
  leftMotor_->brake();
  rightMotor_->brake();
  state_ = stopped;
}

/* Function: reverse
 * Brief: run the robot backwards
 */
void Robot::reverse()
{
  leftMotor_->rotate(clockwise, speed_);
  rightMotor_->rotate(counterClockwise, speed_);
  state_ = moving;
}

/* Function: turn
 * Brief: turn robot to either side
 */
void Robot::turn(Side side)
{
  if (side == left)
  {
    leftMotor_->rotate(clockwise, speed_);
    rightMotor_->rotate(clockwise, speed_);
  }
  else if (side == right)
  {
    leftMotor_->rotate(counterClockwise, speed_);
    rightMotor_->rotate(counterClockwise, speed_);
  }
  state_ = turning;
}

/* Function: isClearPath
 * Brief: check for object within minFreePath
 */
bool Robot::isClearPath(double minFreePath)
{
  bool isClearPath = true;
  if (sonar_->readDistanceInCm() < minFreePath)
  {
    isClearPath = false;
  }
  return isClearPath;
}

/* Function: runObstacleAvoidingAlgorithm
 * Brief: algoriithmmmm
 */
void Robot::runObstacleAvoidingAlgorithm()
{
  double minFreePath = 25;

  switch (state_)
  {
    case stopped:
      if (isClearPath(minFreePath))
      {
        go();
      }
      break;
    case moving:
      if (! isClearPath(minFreePath))
      {
        stop();
        delay(1000);
        turn(left);
      }
      break;
    case turning:
      if (isClearPath(minFreePath))
      {
        delay(250);
        stop();
      }
      break;
  }
}

/* Function: getSerialCommand
 * Brief: return received command from Serial read
 */
char Robot::getSerialCommand()
{
  char ch = '\0';
  if (serial_->available() > 0)
  {
    ch = serial_->read();
  }
  return ch;
}

/* Function: runBlueStickCommand
 * Brief: map received command from 'BlueStick' app to appropriate action
 */
void Robot::runBlueStickCommand()
{
  char ch = getSerialCommand();
  switch (ch)
  {
    case '0':
      stop();
      break;
    case '8':
      go();
      break;
    case '2':
      reverse();
      break;
    case '4':
      turn(left);
      break;
    case '6':
      turn(right);
      break;
    default:
      stop();
      break;
  }
}

/* Removable helper functions */
Sonar * Robot::getSonarHelperFunction()
{
  return sonar_;
}