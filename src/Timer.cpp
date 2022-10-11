/*
    Implementation of the Timer Class.
*/


#include "Timer.h"


ObjTimer::ObjTimer() : m_time(0), m_nextTime(0), m_gap(1000)                  // Defaut constructor : Standard gap of sec
{
}

ObjTimer::ObjTimer(uint16_t gap) : m_time(0), m_nextTime(0), m_gap(gap)       // Constructor with user gap.
{
}


bool ObjTimer::gap()
{
    
    m_time = millis();                  
    
    if (m_time >= m_nextTime)
    {
        m_nextTime = m_time + m_gap;
        return true;                    
    }

    else
    {
        return false;                   
    }
    
}

void ObjTimer::startTimer()
{
    m_nextTime = (millis() + m_gap);

}