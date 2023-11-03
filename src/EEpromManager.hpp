/*

*/
#ifndef EEPROM_MANAGER_HPP
#define EEPROM_MANAGER_HPP

#include <Arduino.h>

#include "Configuration.hpp"


class EEpromManager
{
public:
    EEpromManager();
    ~EEpromManager();

    byte getCurrentTableValue();       // Return the value stored in the EEprom at the current index (don't know if it's usefull...)
    uint16_t getTableValue(const byte& index);      // 
    void storeGaugeState(const byte &state);
    void storeNextTableValue(const uint16_t &value);
    bool tableFull();

protected:
    void storeTableComplete(const bool& _complete);

private:
    /* 
        Reminder for adressing :
        Table start at adress 0 to 36*2byte = 72 byte (so, end adress is 72)
        Gauge state is stored at adress "table.Lengh + 2byte", so at adress 74.
        m_tableComplete is stored at adress 100. Beacause.
    */

    const byte startAdressTable;       // Start adress of the conversion table in the EEPROM
    const byte endAdressTable;         // End adress of the conversion table in the EEPROM
    const byte adressGaugeState;       // Adress of the gauge state.
    
    bool m_tableComplete;       // Flag for calibration done
    byte m_EEprTableIndex;      // Index to iterate through the table when writing.
    
    
};

#endif