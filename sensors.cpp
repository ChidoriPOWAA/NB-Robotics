#include "lib/sensors.h"

Sonar::Sonar(NewPing * newPing)
{
  newPing_ = newPing;
}

Sonar::~Sonar()
{
  delete newPing_;
}

double Sonar::readDistanceInCm()
{
  unsigned long medianTimeInMicroSeconds;
  medianTimeInMicroSeconds = newPing_->ping_median();

  return newPing_->convert_cm(medianTimeInMicroSeconds);
}