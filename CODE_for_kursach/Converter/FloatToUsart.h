#ifndef FLOATTOUSART_H
#define FLOATTOUSART_H
#include "IConvert.h"

class FloatToUsart: public IConvert
{
public:
  FloatToUsart();
  void ConvertForUsart(float filteredValue, char* bufferValue) override; 
};

#endif