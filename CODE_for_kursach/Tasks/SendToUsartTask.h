#ifndef SENDTOUSARTTASK_H
#define SENDTOUSARTTASK_H
#include "thread.hpp" // for Thread<>
#include <chrono> // for 'ms' literal
#include "DataRepository.h" // for repos
#include "IConvert.h"  // for convert
#include "IUsart.h" // for usart
#include "mutex.hpp"

class SendToUsartTask: public OsWrapper::Thread<200>
{
public:
  SendToUsartTask(OsWrapper::Mutex& mutex, DataRepository& repos, IConvert& convert, IUsart& usart, std::chrono::milliseconds time);
  void Execute() override;
private:
  DataRepository& mRepos; 
  IConvert& mConvert; 
  IUsart& mUsart; 
  std::chrono::milliseconds mTime;
  OsWrapper::Mutex& mMutex;
};

#endif