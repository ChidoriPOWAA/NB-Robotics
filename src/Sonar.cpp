#include "../lib/Sonar.h"

/* Function: Sonar
 * Brief: sonar constructor
 */
Sonar::Sonar(NewPing * newPing)
{
  newPing_ = newPing;
}

/* Function: ~Sonar
 * Brief: sonar destructor
 */
Sonar::~Sonar()
{
  delete newPing_;
}

/* Function: readDistanceInCm
 * Brief: return distance to nearest object in cm
 */
double Sonar::readDistanceInCm()
{
  unsigned long medianTimeInMicroSeconds;
  medianTimeInMicroSeconds = newPing_->ping_median();

  return newPing_->convert_cm(medianTimeInMicroSeconds);
}