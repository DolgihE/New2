#ifndef DATAADC_H
#define DATAADC_H
#include "IADC.h" 

class DataADC: public IADC
{
public:
  DataADC();
  void DoMeasurement() override;
  float GetData() override;
};

#endif