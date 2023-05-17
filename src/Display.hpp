/*
    Specific class for using easily the 1.54" E-Paper display as a dashboard
    This class uses the libraries for handling the display in a specific purpose.
*/
#ifndef DISPLAY_HPP
#define DISPLAY_HPP


#include <GxEPD2_BW.h>
#include "epd/GxEPD2_150_BN.h"

#include "Screen_Configuration.h"
#include "Configuration.hpp"
#include "Coordinate.h"


class Display : public GxEPD2_BW<GxEPD2_150_BN, MAX_HEIGHT(GxEPD2_150_BN)>    //Inheritance of the BW Template Class with specific parameters.
{
public:
    Display();                          // Constructeur
    ~Display();
        
    void begin(uint32_t _bitrate);      // Initiate the display with the specified bitrate
    void setUpHud();                    // Refresh the E-Paper display and draw HUD elements with static parameters. For starup only.

    void dispAirTemp(const int16_t& _temp);      // Display the temperature, in a simple way, in his own area. This method handle all the specific instruction for the display.
    void dispGasLevel(const uint8_t& _gradToDisplay);     // Ca marche, mais c'est lent !

protected:
    void dispReserve();

private:
    int16_t m_lastTemp;
    uint8_t m_LastGaugeState;
};

#endif

