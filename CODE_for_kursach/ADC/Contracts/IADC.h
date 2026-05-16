#ifndef IADC_H
#define IADC_H

class IADC
{
public:
  virtual float GetData() = 0;
  virtual void DoMeasurement() = 0;
};

#endif