


#include "TimeGap.h"


TimeGap::TimeGap() : m_time(0), m_Ltime(0), m_gap(1000)
{
}

TimeGap::TimeGap(uint16_t gap) : m_time(0), m_Ltime(0), m_gap(gap)
{
}

bool TimeGap::gap()
{
    m_time = millis();                  // Store the actual time.

    if (m_time - m_Ltime >= m_gap)      // Verify the gap between the last call of the method and the actual time.
    {
        m_Ltime = m_time;               // m_Ltime become the actual time for the next call
        return true;                    // Return true for the user
    }

    else
    {
        return false;                   
    }
    
}

void TimeGap::changeGap(uint16_t newGap)
{
    m_gap = newGap;
}