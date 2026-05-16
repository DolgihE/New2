#ifndef IFILTER_H
#define IFILTER_H

class IFilter
{
public:
  virtual float FilterData(float dataNotFiltered) = 0;
};

#endif