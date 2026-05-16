#include "Filter.h"
#include "math.h" // for exp()

Filter::Filter():
  mFilteredAngle(0)
  {
    
  }
  float Filter::FilterData(float angleNotFiltered)
  {
    float tau = 1.0f - exp(-0.1f/0.8f);
    mFilteredAngle = mFilteredAngle  + tau*(angleNotFiltered - mFilteredAngle);
    return mFilteredAngle;
  }