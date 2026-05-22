#ifndef FILTER_H
#define FILTER_H
#include "IFilter.h"

class Filter: public IFilter
{
public:
  Filter();
  float FilterData(float angleNotFiltered) override;
protected:
  float mFilteredAngle;
};

#endif