
/*
    Class for the handling of the gauge data
    Determine the fuel level, average it on 1 min, and manage the switch threshold.
*/

#ifndef GAUGE_HPP
#define GAUGE_HPP

#include <Arduino.h>

#include "ConversionTable.hpp"
#include "Configuration.hpp"


class Gauge
{
public:
    Gauge();
    ~Gauge();

    void integrateNewValue(const uint16_t& _lvl);       // Insert a new reading in the array, and re-compute the average level.
    uint8_t curentState();                  // Return the current number of rectangle to print, for m_lvlAvrg.

    uint16_t getLevelAverage();     // Return the current average level
    uint16_t getLevelLiters();      // Return the current average level converted in liters


private:
    uint32_t m_ArrTotal;    // Sum of all the values in the array
    uint16_t m_lvlArray[FUEL_ARRAY_SIZE];       // Array containing the last 60 levels
    byte m_ArrayIndex;      // current index of the array, for read/write values
    uint16_t m_lvlAvrg;     // Average level of the array
    byte currentState;      // this is "how many 1/6 of the maximum can fit in the actual level"
    
    enum sIntegral {FILL, SLIP};        // State of the array : FILL and startup, then SLIP once the array is filled.
    sIntegral stateArray;               // Used for better accuracy at startup

    EEpromManager* GaugeMemory;     // EEpromManager object used to store information.
    ConversionTable* Conversion;    // Abstract conversion table object. See "ConversionTable.hpp" for more information
};


#endif