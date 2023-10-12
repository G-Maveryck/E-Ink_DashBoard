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
    stateArray(FILL)
{
  /* GaugeMemory = new EEpromManager();
  Conversion = new ConversionTable(GaugeMemory); */
}

Gauge::~Gauge()
{
  /*
  delete Conversion;
  delete GaugeMemory;
  */
}


void Gauge::integrateNewValue(const uint16_t& _lvl)
{
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

      m_ArrayIndex++; 

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
  /*
    "Current State" return the number of "1/6" that fit into the average level.
    It is the number of graduation for the display. Max = 6, min = 0 (or Reserve).
  */
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

}


uint16_t Gauge::getLevelAverage()
{
  return m_lvlAvrg;
}
