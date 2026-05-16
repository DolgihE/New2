#ifndef ANGLECALCULATING_H
#define ANGLECALCULATING_H
#include "ICalculate.h"

class AngleCalculating: public ICalculate
{
public:
  AngleCalculating();
  float CalculateAngle(float buffer) override;
};


#endif