#ifndef IUSART_H
#define IUSART_H

class IUsart
{
public:
  virtual void SendData(char* buffer) const = 0;
};

#endif