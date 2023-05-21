/*
  Implementation of the Gauge class
*/

#include "Gauge.hpp"
#include "DebugMacro.hpp"

// Constructor
Gauge::Gauge() : 
    m_ArrTotal(0), 
    m_lvlArray{1},
    m_ArrayIndex(0),
    m_lvlAvrg(1), 
    currentState(6),
    // thresholds{0.83f, 0.66f, 0.5f, 0.33f, 0.16f},
    stateArray(FILL)
{
  
}


Gauge::~Gauge()
{
}

void Gauge::integrateNewValue(const uint16_t& _lvl)
{
  //machine state for filling the array on the first loop, then integrate new slipping values.

  switch (stateArray)
  {
    /*
    FILL state is used at startup, for filling the array.
    An average value is calculated based only on the filled collumns of the array.
    */
   
    case FILL:
        // Filling the array, with the value _lvl passed as argument
        // Adding the new value to the array sum (total).
      m_lvlArray[m_ArrayIndex] = _lvl;        
      m_ArrTotal += m_lvlArray[m_ArrayIndex]; 

      m_lvlAvrg = (m_ArrTotal/(m_ArrayIndex +1));  // Dividing the total by the actual numer of filled collumns (index) to compute the Average.
      
      m_ArrayIndex++;                         // Increment Index for the next value.

          // Security to avoid overshooting the array maximum index.
          // Index go back to 0 if it reach the maximum.
      if (m_ArrayIndex >= FUEL_ARRAY_SIZE)
      {
        m_ArrayIndex = 0;
        stateArray = SLIP;
        // In FILL state, when the maximum value is reached, the array is now full-filled.
        // Switch to SLIP state.
      }
      break;
    
    case SLIP:
    /*
    SLIP state is used when the array is filled. 
    Substract the old value, add the new, and re-compute the average of the array.
    */
      m_ArrTotal -= m_lvlArray[m_ArrayIndex]; // Substract old value to the total
      m_lvlArray[m_ArrayIndex] = _lvl;        // Add new value to the array
      m_ArrTotal += m_lvlArray[m_ArrayIndex]; // Add new value to total.

      m_ArrayIndex++;             // Increment Index for the next value.

          // Security to avoid overshooting the array maximum size.
          // Index go back to 0 if it reach the maximum size.
      if (m_ArrayIndex >= FUEL_ARRAY_SIZE)
      {
        m_ArrayIndex = 0;
      }   

          // Compute the average level, based on the total array size.
      m_lvlAvrg = (m_ArrTotal/FUEL_ARRAY_SIZE); 

      break;
      
  }

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
  LOGLN("*** Enter currentState() ***");

  #define PERCENTAGE_STEP 17

  byte testPercent(0);
  byte incrementStep(0);

  float ratio = static_cast<float>(m_lvlAvrg)/1200.0f;
  LOG("ratio = ");
  LOGLN(ratio);
  
  uint16_t percentage = static_cast<uint16_t>( (ratio*100.0f) );
  LOG("Percentage = ");
  LOGLN(percentage);

  while (testPercent <= percentage)
  {
    testPercent += PERCENTAGE_STEP;
    incrementStep++;

    if (incrementStep > 6)
    {
      incrementStep = 6;
      break;
    }
    
  }
    /*
    Each increment correspond to an interval of 17% (or 1/6).
    When the while's condition is not match, that means our percentage is now 
    lower than the testPercantage. So, his value is bound between the last and
    the actual test.
    So we return the actual number of iteration, so, "how many 1/6 fit in the percentage"
    */ 
  

  LOG("incrementStep = ");
  LOGLN(incrementStep);
  LOGLN("*** Return currentState() ***");
  LOGLN(" ");
  return incrementStep;
  



  /*
      OLD METHOD
  float ratio = ( (static_cast<float>(m_lvlAvrg) ) / 1200.00f ) ;
    LOG("Ratio =    ");
    LOGLN(ratio);

    // BOILERPLATE AF
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
  
  LOG("current state = ");
  LOGLN(currentState);

  return currentState;
  */
}


uint16_t Gauge::getLevelAverage()
{
    return m_lvlAvrg;
}
