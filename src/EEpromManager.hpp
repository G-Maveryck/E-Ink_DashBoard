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

    inline byte getLastGaugeState();
    inline uint16_t getTableValue(const byte& index);
    inline void storeGaugeState(const byte &state);
    inline void storeNextTableValue(const uint16_t &value);
    inline bool tableFull();

protected:
    void storeTableComplete(const bool& _complete);

private:
    /* 
        Reminder for adressing :
        Table start at adress 0 to 36* 2byte = 72 byte
        Gauge state is stored at adress "table.Lengh +1", so at adress 73.
        m_tableComplete is stored at adress 100. Beacause.
    */

    static byte startAdressTable;       // Start adress of the table in the EEPROM
    static byte endAdressTable;         // End adress of the table in the EEPROM
    static byte adressGaugeState;       // Adress of the gauge state.
    
    bool m_tableComplete;       // Flag for calibration done
    byte m_EEprTableIndex;      // Index to iterate through the table when writing.
    
    
};

#endif