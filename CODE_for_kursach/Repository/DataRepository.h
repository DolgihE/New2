#ifndef DATAREPOSITORY_H
#define DATAREPOSITORY_H

class DataRepository
{
public:
  DataRepository();
  float GetData() const;
  void LoadData(float data);
protected:
  float mData;
};

#endif