#ifndef SIM_GAUGE_H
#define SIM_GAUGE_H

#include <Arduino.h>
#include "Timer.h"

#include <time.h>



uint16_t getFuelLevel()
{
    static ObjTimer timerFuel(5000);       // Each 5 sec, lvl is decreased


    static uint16_t lvl = 1000;
    uint16_t randLvl = 0;

    if (timerFuel.gap())       // Decrease level 
    {
       lvl-- ;
       
       if (lvl <= 0)           // when it reach 0, start again from 1000.
       {
        lvl = 1000;
       }
       
    }
    
    // Each time the "sensor" is asked, it return the level with a random value of +/- 200
    // This is implemented to simulate the movement of the fuel in the tank.
    randLvl = (lvl + (rand() % 200)) ;      
    return randLvl;

}




#endif