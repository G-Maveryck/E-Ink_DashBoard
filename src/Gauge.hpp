
/*
    Class for the handling of the gauge data
    Determine the fuel level, average it on 1 min, and manage the switch threshold.
*/

#ifndef GAUGE_HPP
#define GAUGE_HPP

#include "Configuration.hpp"
#include <Arduino.h>


class Gauge
{
public:
    Gauge();
    ~Gauge();

    void integrateNewValue(const uint16_t& _lvl);
    uint8_t curentState();                  // Return the current number of rectangle to print, for m_lvlAvrg.

    uint16_t getLevelAverage();

private:
    uint32_t m_ArrTotal;
    uint16_t m_lvlArray[FUEL_ARRAY_SIZE];
    uint16_t m_lvlAvrg;
    byte m_ArrayIndex;
    byte currentState;
    
    // const float thresholds[5] /*{0.83f, 0.66f, 0.5f, 0.33f, 0.16f}*/;

    enum sIntegral {FILL, SLIP};
    sIntegral stateArray;


};


#endif