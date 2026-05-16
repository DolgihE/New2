#include "TakeMeasurementTask.h"

TakeMeasurementTask::TakeMeasurementTask(IADC& adc, DataRepository& repos, IFilter& fltr, ICalculate& calc, OsWrapper::Mutex& mutex, std::chrono::milliseconds time):
  mAdc(adc), mRepos(repos), mFltr(fltr), mCalc(calc), mMutex(mutex), mTime(time)
  {
    
  }
  
  void TakeMeasurementTask::Execute()
  {
    float angleDataBuffer;
    for(;;)
    {
      mAdc.DoMeasurement();
      angleDataBuffer = mAdc.GetData();
      angleDataBuffer = mCalc.CalculateAngle(angleDataBuffer);
      angleDataBuffer = mFltr.FilterData(angleDataBuffer);
      mMutex.Lock();
      {      
        mRepos.LoadData(angleDataBuffer);
      }
      mMutex.UnLock();
      SleepUntil(mTime);
    }
  }