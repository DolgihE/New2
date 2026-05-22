#include "FloatToUsart.h"
#include "stdio.h" // for sprintf()

FloatToUsart::FloatToUsart()
{}

void FloatToUsart::ConvertForUsart(float filteredValue, char* bufferValue)
{
  sprintf(bufferValue, "%.2f\r\n", filteredValue);
}