#ifndef MOTOR_H
#define MOTOR_H

enum Direction
{
  counterClockwise = 0,
  clockwise = 1
};

class Motor
{
  private:
    const int directionPin_;
    const int pwmPin_;
    const int brakePin_;
    const int currentSensingPin_;

  public:
    Motor(const int directionPin,
          const int pwmPin,
          const int brakePin,
          const int currentSensingPin);
    
    void setup();
    void rotate(Direction direction, int speed);
};

#endif