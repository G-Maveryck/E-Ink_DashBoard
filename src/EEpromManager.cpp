/*

*/

#include "EEpromManager.hpp"

#include <EEPROM.h>


EEpromManager::EEpromManager(/* args */)
{
    adressTable = 0;
    adressGaugeState = (CONVERSION_ARRAY_SIZE * sizeof(uint16_t)) + 1;
}

EEpromManager::~EEpromManager()
{
}


void EEpromManager::storeGaugeState(const byte &state)
{

}

byte EEpromManager::getLastGaugeState()
{


}