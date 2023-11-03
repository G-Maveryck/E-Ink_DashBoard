/*

*/

#include "EEpromManager.hpp"

#include <Arduino.h>
#include <EEPROM.h>

#include "DebugMacro.hpp"


EEpromManager::EEpromManager(/* args */):
        m_EEprTableIndex(0),
        m_tableComplete(false),
        startAdressTable(0),
        endAdressTable(CONVERSION_TABLE_SIZE * sizeof(uint16_t)),
        adressGaugeState(endAdressTable + sizeof(uint16_t))
{

    bool _eeTableComplete;
    EEPROM.get(100, _eeTableComplete);      // Load the flag from the EEprom
    if (_eeTableComplete)       // Check if the table was already filled or not.
    {
        m_tableComplete = _eeTableComplete;     // store the Flag in memory for future uses.
    }
    LOG("Is CalTable complete ? : ");
    LOGLN(m_tableComplete);
}

EEpromManager::~EEpromManager()
{
}


byte EEpromManager::getCurrentTableValue()
{
    return EEPROM.read(m_EEprTableIndex);
}

uint16_t EEpromManager::getTableValue(const byte& index)
{
   if (index >= 0 && index <= CONVERSION_TABLE_SIZE)       // Check if the ind
    {
        index*sizeof(uint16_t);     // Convert abstract index into EEprom adress

        uint16_t data(0);
        EEPROM.get(index, data);    // Get the data from the EEprom

        return data;        // Return the data to user.
    }
}


inline void EEpromManager::storeGaugeState(const byte &state)
{
    if (state > 0 && state <= 6)    // Check for a valid state
    {
        EEPROM.put(adressGaugeState, state);    // Write the EEPROM
    }
}

inline void EEpromManager::storeNextTableValue(const uint16_t &value)
{
    EEPROM.put(m_EEprTableIndex, value);

    m_EEprTableIndex += sizeof(uint16_t);   // Iterate for the next call of this function
    if (m_EEprTableIndex > endAdressTable)  // Check for the end of the table.
    {
        m_EEprTableIndex = 0;
        m_tableComplete = true;
        storeTableComplete(m_tableComplete);
    }
    
}

inline bool EEpromManager::tableFull()
{
    return m_tableComplete;
}

void EEpromManager::storeTableComplete(const bool& _complete)
{
    EEPROM.put(100, _complete);
}