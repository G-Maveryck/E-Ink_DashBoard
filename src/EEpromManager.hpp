/*

*/
#ifndef EEPROM_MANAGER_HPP
#define EEPROM_MANAGER_HPP

#include <Arduino.h>
#include <EEPROM.h>

#include "Configuration.hpp"



class EEpromManager
{
public:
    EEpromManager();
    ~EEpromManager();

    void storeGaugeState(const byte &state);
    byte getLastGaugeState();
    void storeTableValue(const byte& index, const uint16_t &value);
    uint16_t getTableValue(const byte& index);
    
private:
    static byte adressTable;        // Start adress of the table in the EEPROM
    static byte adressGaugeState;       // Adress of the gauge.
    
};

#endif