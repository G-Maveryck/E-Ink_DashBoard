/*
    Classe simple pour vérifier des intervales temporels.
    Permet de simplifier la déclaration des variables ainsi que les tructure conditionnelles.
*/

#ifndef OBJ_TIMER_H
#define OBJ_TIMER_H

#include <Arduino.h>


class ObjTimer
{
    public:
    ObjTimer();                  // Constructor with a standard gap of 1 sec.
    ObjTimer(uint16_t gap);      // Constructor overload to specify a custom gap (in millisec)

    bool gap();                  // Check if the gap if filled. Return TRUE if the gap is crossed. False if he's not.
    void startTimer();           // Set the gap from the moment the function is called.


    private:
    uint32_t m_time;             // Actual time, given by millis()
    uint32_t m_nextTime;         // Time when the gap will be filled. Determined by m_time + m_gap.
    const uint16_t m_gap;        // Gap atribute in Millisecond. Given on Unsigned 16bits. Max value = 65 535 (65 sec)
};



#endif