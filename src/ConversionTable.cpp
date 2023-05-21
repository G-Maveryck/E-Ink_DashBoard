/*

*/

#include "ConversionTable.hpp"
#include <Arduino.h>
#include "Configuration.hpp"

#include <EEPROM.h>

ConversionTable::ConversionTable()
{
        // Iterate throungh the EEPROM, copy the value in the array m_table[].
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
float ConversionTable::linearInterpolate(const byte &a, const byte &x)
{
 
    byte b = a+1;
    float result = static_cast<float>( 
        (a + (x - m_table[a])) * (b+a) / ((m_table[b]) - m_table[a])
        );
        
    return result;
}