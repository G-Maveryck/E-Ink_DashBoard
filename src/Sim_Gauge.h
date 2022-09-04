#ifndef SIM_GAUGE_H
#define SIM_GAUGE_H

#include <Arduino.h>
#include "TimeGap.h"


TimeGap timerFuel(10000);


int getFuelLevel()
{
    int lvl = 1024;

    if (timerFuel.gap())
    {
        
    }
    

}




#endif