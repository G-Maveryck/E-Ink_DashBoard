


#include "TimeGap.h"


TimeGap::TimeGap() : m_time(0), m_nextTime(0), m_gap(1000)                  // Defaut constructor : Standard gap of sec
{
}

TimeGap::TimeGap(uint16_t gap) : m_time(0), m_nextTime(0), m_gap(gap)       // Custructor with user gap.
{
}

bool TimeGap::gap()
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
