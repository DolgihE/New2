#ifndef ICONVERT_H
#define ICONVERT_H

class IConvert
{
public:
  virtual void ConvertForUsart(float data, char* buffer) = 0;
  virtual ~IConvert(); 
};

#endif