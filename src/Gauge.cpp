
#include "Gauge.h"



Gauge::Gauge() : m_lvlArray{0}, m_lvlAvrg(0), m_lvlArray_Counter(0), thresholds{0.83f, 0.66f, 0.5f, 0.33f, 0.16f}
{
}

Gauge::~Gauge()
{
}

void Gauge::integrateNewValue(uint16_t _lvl)
{
      if (m_lvlArray_Counter >= FUEL_ARRAY_SIZE )             // Check if the counter is above the array to avoid overflow.
      {
        m_lvlArray_Counter = 0;                               // Return to 0 when it reach the array limit.
      }
      
      m_lvlArray[m_lvlArray_Counter] = _lvl;                  // Store the current data in the array
      m_lvlArray_Counter++;                                   // Incrementing counter for the next value



    uint32_t* sum = new uint32_t(0);

    for (uint8_t i = 0; i < FUEL_ARRAY_SIZE; i++)
    {
      *sum += m_lvlArray[i];
    }

    m_lvlAvrg = (*sum / FUEL_ARRAY_SIZE);

    delete sum;

}

uint8_t Gauge::gradToDisp()
{
 // uint8_t threshCount = 0;
  float ratio = (m_lvlAvrg/1000);
  uint8_t gradValue(0);

    // BOILERPLATE AF

    // Y'a surement moyen de faire ça avec une machine à état.. J'me creuse la tête..
  if (ratio<=1 && ratio > thresholds[0] )
  {
    gradValue = 6 ;
  }

  else if (ratio <= thresholds[0] && ratio > thresholds[1])
  {
    gradValue = 5;
  }

  else if (ratio <= thresholds[1] && ratio > thresholds[2])
  {
    gradValue = 4;
  }

  else if (ratio <= thresholds[2] && ratio > thresholds[3])
  {
    gradValue = 3;
  }

  else if (ratio <= thresholds[3] && ratio > thresholds[4])
  {
    gradValue = 2;
  }

  else if (ratio < thresholds[4])
  {
    gradValue = 1;
  }
  
  return gradValue;
  
  
  

  
    

}

uint16_t Gauge::getLevelAverage()
{
    return m_lvlAvrg;
}
