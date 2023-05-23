/*
    This conversion table class is an abstraction for accessing and reading 
    the values stored in the EEPROM.

    It uses an array to store the capacitor values for each 0,5 litres of fuel.

    This class if used for converting the readed values of the capacitor to liters,
    and accessing the array in a mor abstract way for calibration.
*/

#ifndef CONVERSION_TABLE_HPP
#define CONVERSION_TABLE_HPP

#include <Arduino.h>

#include "EEpromManager.hpp"
#include "Configuration.hpp"


class ConversionTable
{
private :
    
public:
    ConversionTable(EEpromManager* _eemPtr);
    ~ConversionTable();
    
    enum CalibState {READING, CALIB};

    float toLiters(const uint16_t &readValue);
    void setCalibrationMode(CalibState _state);
    bool isInCalibration();

protected:
    inline float linearInterpolate(const byte &a, const byte &x);

private:
    uint16_t m_table[CONVERSION_TABLE_SIZE];

    EEpromManager* Memory;
    CalibState m_CalibState;



};







#endif