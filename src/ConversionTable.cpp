/*

*/

#include "ConversionTable.hpp"
#include <Arduino.h>
#include "Configuration.hpp"

#include <EEPROM.h>

ConversionTable::ConversionTable(EEpromManager* _EEpAcc) :
    m_TableEEprom(_EEpAcc)
{
        // Iterate throungh the EEPROM, copy the value in the array m_table[].
        // Copy the table from EEPROM into memory for faster access and protecting the EEPROM
    for (byte i = 0; i < CONVERSION_ARRAY_SIZE; i++)
    {
        EEPROM.get(i*sizeof(uint16_t), m_table[i]);
    }
    
}

ConversionTable::~ConversionTable()
{
}

float ConversionTable::getLiters(const uint16_t &readValue)
{
        // Iterate through the table to find the interval where a < readValue < b
    byte i(0);
    while (readValue < m_table[i])
    {
        i++;
    }

    float liters = linearInterpolate(i, readValue);

    return liters;
}

    // Linear interpolate : 
    // f(x) = ( f(a)+(x-a) ) * ( (f(b)+f(a)) / (b-a) )
float ConversionTable::linearInterpolate(const byte &_a, const byte &_x)
{
        // Pas trop sur que ce soit necessaire... Avis ?
    float a = static_cast<float>(_a);
    float b = a + 1.0f;
    float x = static_cast<float>(_x);

    float table_a = static_cast<float>(m_table[_a]);
    float table_b = static_cast<float>(m_table[_a+1]);

    // byte b = a+1;
    float result =  
        (a + (x - table_a)) * ( (b+a) / ((table_b) - table_a) ) ;
        
    return result;
}

