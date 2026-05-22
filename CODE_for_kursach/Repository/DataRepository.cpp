#include "DataRepository.h"

DataRepository::DataRepository():
  mData(0)
  {
    
  }
  
  float DataRepository::GetData() const
  {
    return mData;
  }
  
  void DataRepository::LoadData(float data)
  {
    mData = data;
  }