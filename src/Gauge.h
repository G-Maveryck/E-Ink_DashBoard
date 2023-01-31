/*
    Class for the handling of the gauge data.
    Determine the fuel level, average it on 1 min, and manage the switch threshold.
*/

#ifndef GAUGE_H
#define GAUGE_H

#include "config.h"
#include <Arduino.h>

class Gauge
{
    private:
        uint32_t    m_ArrTotal;

        uint16_t    m_lvlArray[FUEL_ARRAY_SIZE], 
                    m_lvlAvrg;

        uint8_t     m_ArrayIndex, 
                    currentState;
        
        
        float thresholds[5];

        enum sIntegral {FILL, SLIP};
        sIntegral stateArray;

        

    public:
        Gauge();
        ~Gauge();

        void integrateNewValue(const uint16_t& _lvl);
        uint8_t curentState();                  // Return the current number of rectangle to print, for m_lvlAvrg.

        uint16_t getLevelAverage();
};





#endif