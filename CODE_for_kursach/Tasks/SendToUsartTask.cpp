#include "SendToUsartTask.h"

SendToUsartTask::SendToUsartTask(OsWrapper::Mutex& mutex, DataRepository& repos, IConvert& convert, IUsart& usart, std::chrono::milliseconds time):
  mMutex(mutex), mRepos(repos), mConvert(convert), mUsart(usart), mTime(time)
  {}
  
  void SendToUsartTask::Execute()
  {
    float reposAngleData;
    char buffer[16];
    for(;;)
    {
      mMutex.Lock();
      {
      reposAngleData = mRepos.GetData();
      }
      mMutex.UnLock();
      mConvert.ConvertForUsart(reposAngleData, buffer);
      mUsart.SendData(buffer);
      SleepUntil(mTime);
    }
  }