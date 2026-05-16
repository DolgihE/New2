#include "AngleCalculating.h"

AngleCalculating::AngleCalculating()
{}

float AngleCalculating::CalculateAngle(float buffer)
{
  float angle = 0.0f;
  float counts = 4095.0f;
  float maxAngle = 360.0f;
  
  angle = buffer;
  angle = angle*maxAngle/counts;
  
  return angle;
}