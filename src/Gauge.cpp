
#include "Gauge.hpp"
#include "DebugMacro.hpp"

// Constructor
Gauge::Gauge() :  m_ArrTotal(0), 
                  m_lvlArray{1}, 
                  m_ArrayIndex(0),
                  m_lvlAvrg(0), 
                  currentState(6),

                 // thresholds{0.83f, 0.66f, 0.5f, 0.33f, 0.16f},
                  stateArray(FILL)
  {}


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
      m_lvlArray[m_ArrayIndex] = _lvl;        // Filling the array, with the value _lvl passed as argument

      m_ArrTotal += m_lvlArray[m_ArrayIndex]; // Adding the new value to the array sum (total).
      m_lvlAvrg = (m_ArrTotal/m_ArrayIndex);  // Dividing the total by the actual numer of filled collumns (index) to compute the Average.

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

  float ratio = ( (static_cast<float>(m_lvlAvrg) ) / 1200.00f ) ;
    PRINT("Ratio =    ");
    PRINTLN(ratio);
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
  
  PRINT("current state = ");
  PRINTLN(currentState);

  return currentState;

}


uint16_t Gauge::getLevelAverage()
{
    return m_lvlAvrg;
}
