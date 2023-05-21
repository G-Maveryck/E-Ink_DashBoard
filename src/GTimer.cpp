/*
    Implementation of the Timer Class.
*/


#include "GTimer.hpp"


GTimer::GTimer() : 
    m_currentTime(0), 
    m_nextTime(0), 
    m_gap(1000)        // Defaut constructor : Standard gap of sec
{
}

GTimer::GTimer(uint16_t gap) : 
    m_currentTime(0), 
    m_nextTime(0), 
    m_gap(gap)       // Constructor with user gap.
{
}


bool GTimer::timeOut()
{
    m_currentTime = millis();                  
    
    if (m_currentTime >= m_nextTime)
    {
        m_nextTime = m_currentTime + m_gap;
        return true;
    }

    else
    {
        return false;
    }
    
}

void GTimer::startTimer()
{
    m_nextTime = (millis() + m_gap);
}