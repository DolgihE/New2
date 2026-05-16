#ifndef TAKEMEASUREMENTTASK_H
#define TAKEMEASUREMENTTASK_H
#include "thread.hpp" // for Thread<>
#include <chrono> // for 'ms' literal
#include "mutex.hpp"  // for Mutex
#include "IADC.h" // for adc
#include "DataRepository.h" // for repos
#include "IFilter.h" // for fltr
#include "ICalculate.h" // for calc

class TakeMeasurementTask:public OsWrapper::Thread<200>
{
public:
  TakeMeasurementTask(IADC& adc, DataRepository& repos, IFilter& fltr, ICalculate& calc, OsWrapper::Mutex& mutex, std::chrono::milliseconds time);
  void Execute() override;
private:
  IADC& mAdc; 
  DataRepository& mRepos; 
  IFilter& mFltr; 
  ICalculate& mCalc; 
  OsWrapper::Mutex& mMutex; 
  std::chrono::milliseconds mTime;
};

#endif