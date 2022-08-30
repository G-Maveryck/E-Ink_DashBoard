/*
    Classe simple pour vérifier des intervales temporaire simplement.
    Permet de simplifier la déclaration des variables ainsi que les tructure conditionnelles.
*/

#ifndef TIMEGAP_H
#define TIMEGAP_H

#include <Arduino.h>


class TimeGap
{
    public:
    TimeGap();                  // Constructor with a standard gap of 1 sec.
    TimeGap(uint16_t gap);      // Constructor overload to specify a custom gap (in millisec)

    bool gap();             // Check if the gap if filled. Return TRUE if the gap is crossed. False if he's not.
    void changeGap(uint16_t newGap);

    private:
    uint32_t m_time;            // Actual time, given by millis()
    uint32_t m_Ltime;           // Time given by millis() the last time the function returned TRUE
    uint16_t m_gap;             // Gap atribute in Millisecond. Given on Unsigned 16bits. Max value = 65 535 (65 sec)
};



#endif