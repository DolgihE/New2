#ifndef USART2SEND_H
#define USART2SEND_H
#include "IUsart.h"

class Usart2Send: public IUsart
{
public:
  Usart2Send();
  void SendData(char* buffer) const override;
};

#endif