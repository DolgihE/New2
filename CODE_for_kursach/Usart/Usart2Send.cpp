#include "Usart2Send.h"
#include "usart2registers.hpp" // for Usart registers

Usart2Send::Usart2Send()
{}

void Usart2Send::SendData(char* buffer) const
{
  for(int i = 0; buffer[i] != '\0'; i++)
  {
    while(!USART2::SR::TXE::DataRegisterEmpty::IsSet())  
    {
      
    }
    USART2::DR::Write(buffer[i]);
  }
}