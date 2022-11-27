
#include "Gauge.h"



Gauge::Gauge() : m_sum(0), m_lvlArray{1}, m_lvlAvrg(0), m_ArrayIndex(1), currentState(6),
                 thresholds{0.83f, 0.66f, 0.5f, 0.33f, 0.16f},
                 stateArray(FILL)   
{
}


Gauge::~Gauge()
{
}

void Gauge::integrateNewValue(uint16_t _lvl)
{

  //machine state for filling the array on the first loop, then integrate new slipping values.

  // enum sIntegral {FILL, SLIP};
  // static sIntegral stateArray = FILL;

  
  switch (stateArray)
  {
    case FILL:
      m_lvlArray[m_ArrayIndex] = _lvl;

      m_sum += m_lvlArray[m_ArrayIndex];
      m_lvlAvrg = (m_sum/m_ArrayIndex);

      m_ArrayIndex++;
      if (m_ArrayIndex >=60)
      {
        m_ArrayIndex = 0;
        stateArray = SLIP;
      }

      break;
    

    case SLIP:
      m_sum -= m_lvlArray[m_ArrayIndex];
      m_lvlArray[m_ArrayIndex] = _lvl;
      m_sum += m_lvlArray[m_ArrayIndex];

      m_ArrayIndex++;
      if (m_ArrayIndex >=60)
      {
        m_ArrayIndex = 0;
      }   

      m_lvlAvrg = (m_sum/FUEL_ARRAY_SIZE);

      break;
      
  }

  

 


  /*
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
  */



}

uint8_t Gauge::curentState()
{
      // Steps :
            // 6/6 = 1
            // 5/6 = 0.83
            // 4/6 = 0.66
            // 3/6 = 0.5
            // 2/6 = 0.33
            // 1/6 = 0.16
         // const float thresholds[5] {0.83f, 0.66f, 0.5f, 0.33f, 0.16f};
         // static uint8_t selThresh = 5;



  float ratio = ( float(m_lvlAvrg) / 1200.00f );
    Serial.print("Ratio =    ");
    Serial.println(ratio);
    // BOILERPLATE AF

    // Y'a surement moyen de faire ça avec une machine à état.. J'me creuse la tête..
  if (ratio<=1 && ratio > thresholds[0] )
  {
    currentState = 6 ;
  }

  else if (ratio <= thresholds[0] && ratio > thresholds[1])
  {
    currentState = 5;
  }

  else if (ratio <= thresholds[1] && ratio > thresholds[2])
  {
    currentState = 4;
  }

  else if (ratio <= thresholds[2] && ratio > thresholds[3])
  {
    currentState = 3;
  }

  else if (ratio <= thresholds[3] && ratio > thresholds[4])
  {
    currentState = 2;
  }

  else if (ratio < thresholds[4])
  {
    currentState = 1;
  }
  
  return currentState;



}




uint16_t Gauge::getLevelAverage()
{
    return m_lvlAvrg;
}
