/*
    Logic abstract timer.
    Used to measure intervals of time between action, using the timeOut() method.
*/

#ifndef GTIMER_HPP
#define GTIMER_HPP

#include <Arduino.h>


class GTimer
{
public:
    GTimer();                  // Constructor with a standard gap of 1 sec.
    GTimer(uint16_t gap);      // Constructor overload to specify a custom gap (in millisec)

    bool timeOut();            // Check if the gap if filled. Return TRUE if the gap is crossed. False if he's not.
    void startTimer();         // Set the gap from the moment the function is called.


private:
    uint32_t m_currentTime;             // Actual time, given by millis()
    uint32_t m_nextTime;         // Time when the gap will be filled. Determined by m_time + m_gap.
    const uint16_t m_gap;        // Gap atribute in Millisecond. Given on Unsigned 16bits. Max value = 65 535 (65 sec)
};



#endif