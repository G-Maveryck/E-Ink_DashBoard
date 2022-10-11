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
        uint16_t m_lvlArray[FUEL_ARRAY_SIZE], m_lvlAvrg;
        uint8_t m_lvlArray_Counter;
        
        const float thresholds[5];

    public:
        Gauge();
        ~Gauge();

        void integrateNewValue(uint16_t _lvl);
        uint8_t gradToDisp(); 

        uint16_t getLevelAverage();
};





#endif