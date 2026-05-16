#include "DataADC.h" 
#include "adc1registers.hpp" // for ADC registers

DataADC::DataADC()
{}

void DataADC::DoMeasurement()
{
  ADC1::CR2::JSWSTART::On::Set();
  while(!ADC1::SR::JEOC::ConversionComplete::IsSet())
  {
    
  }
  ADC1::SR::JEOC::Set(0);
}

float DataADC::GetData()
{
  float data = static_cast<float>(ADC1::JDR1::JDATA::Get());
  return data;
}
