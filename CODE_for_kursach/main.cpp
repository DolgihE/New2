#include "iostream"//for std::cout
#include "rccregisters.hpp" // for RCC
#include "gpioaregisters.hpp" // for GPIOA
#include "gpiocregisters.hpp" // for GPIOÑ

#include "mutex.hpp"  // for Mutex
#include "adc1registers.hpp" // for adc1 registers
#include "rtos.hpp"         // for Rtos
#include "usart2registers.hpp"

#include "TakeMeasurementTask.h" // for TakeMeasurementTask
#include "SendToUsartTask.h" // for SendToUsartTask

#include "DataADC.h" // for adc
#include "AngleCalculating.h" // for calc
#include "FloatToUsart.h" // for convert
#include "Filter.h" // for fltr
#include "DataRepository.h" // for repos
#include "Usart2Send.h" // for usart 


std::uint32_t SystemCoreClock = 16000000U; // hsi

extern "C" {
int __low_level_init(void)
{
  RCC::CR::HSION::On::Set();
  while (RCC::CR::HSIRDY::NotReady::IsSet())
  {

  }
  //Switch system clock on external oscillator
  RCC::CFGR::SW::Hsi::Set();
  while (!RCC::CFGR::SWS::Hsi::IsSet())
  {

  }
 
  RCC::APB2ENR::SYSCFGEN::Enable::Set();
  
  RCC::APB2ENR::ADC1EN::Enable::Set(); 
  ADC1::CR2::ADON::Enable::Set();
  ADC1::CR1::RES::Bits12::Set(); 
  ADC1::JSQR::JL::Conversion1::Set(); 
  ADC1::JSQR::JSQ4::Channel0::Set(); 
  ADC1::SMPR2::SMP0::Cycles112::Set(); 
  
  
  RCC::APB1ENR::USART2EN::Enable::Set(); 
  USART2::CR1::M::Data8bits::Set(); 
  USART2::CR1::OVER8::OversamplingBy16::Set(); 
  USART2::CR2::STOP::Value0::Set(); 
  USART2::BRR::DIV_Fraction::Value1::Set();
  USART2::BRR::DIV_Mantissa::Set(0x34); 
  
  USART2::CR1::UE::Enable::Set();
  USART2::CR1::TE::Enable::Set();
  

  
  return 1;
}
}


OsWrapper::Mutex mutex;



DataADC adc;
AngleCalculating calc;
FloatToUsart convert;
Filter fltr;
DataRepository repos;
Usart2Send usart;

TakeMeasurementTask measure(adc, repos, fltr, calc, mutex, 50ms);
SendToUsartTask send(mutex, repos, convert, usart, 100ms);


int main()
{ 
 

  RCC::AHB1ENR::GPIOAEN::Enable::Set() ; 
  RCC::AHB1ENR::GPIOCEN::Enable::Set() ;

  GPIOA::MODER::MODER5::Output::Set() ;
  GPIOA::MODER::MODER0::Analog::Set() ; 
  GPIOA::MODER::MODER2::Alternate::Set(); 

  GPIOA::OTYPER::OT2::OutputPushPull::Set();

  GPIOA::AFRL::AFRL2::Af7::Set();

  GPIOC::MODER::MODER5::Output::Set() ;
  GPIOC::MODER::MODER8::Output::Set() ;
  GPIOC::MODER::MODER9::Output::Set() ;
    
  OsWrapper::Rtos::CreateThread(measure, "measuretask", OsWrapper::ThreadPriority::aboveNormal);
  OsWrapper::Rtos::CreateThread(send, "sendtask", OsWrapper::ThreadPriority::normal);
  
  OsWrapper::Rtos::Start();
  for(;;)
  {
   
  }

  return 1;
}
