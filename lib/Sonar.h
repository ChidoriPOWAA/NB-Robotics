#ifndef SENSORS_H
#define SENSORS_H

#include "NewPing.h"

class Sonar
{
  private:
    NewPing * newPing_;

  public:
    Sonar(NewPing * newPing);
    ~Sonar();
    double readDistanceInCm();
};

/*** Available Methods ***/
// sonar.ping(); - Send a ping, returns the echo time in microseconds or 0 (zero) if no ping echo within set distance limit
// sonar.ping_cm(); - Send a ping, returns the distance in centimeters or 0 (zero) if no ping echo within set distance limit
// sonar.ping_median(iterations); - Do multiple pings (default=5), discard out of range pings and return median in microseconds
// sonar.convert_cm(echoTime); - Converts microseconds to distance in centimeters
// sonar.ping_timer(function); - Send a ping and call function to test if ping is complete.
// sonar.check_timer(); - Check if ping has returned within the set distance limit.
// timer_us(frequency, function); - Call function every frequency microseconds.
// timer_ms(frequency, function); - Call function every frequency milliseconds.
// timer_stop(); - Stop the timer.

#endif