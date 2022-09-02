/*
Specific class for using easily the 1.54" E-Paper display as a dashboard.

This class uses the libraries for handling the display in a specific purpose.
*/



    //Include needed Libraries
#include <GxEPD2_BW.h>
#include "epd/GxEPD2_150_BN.h"

    //Definition file for my specific screen
#include "config.h"



class Display : protected GxEPD2_BW<GxEPD2_150_BN, MAX_HEIGHT(GxEPD2_150_BN)>    //Inheritance of the BW Template Class with specific parameters.
{
    public:

    Display();                          // Constructeur
    void begin(uint32_t _bitrate);

    void setUpHud();                    // Refresh the E-Paper display and draw HUD elements with static parameters. For starup only.
    void dispTemp(int16_t& _temp);        // Display the temperature, in a simple way, in is own area. This method handle all the specific instruction for the display.
    void dispGasLevel(uint8_t _nbr);    // /!\ ATTENTION GROSSE MERDE /!\
    
    
    void drawGauge(uint16_t PosX_R);
    
    
    
        // Test method
    void dispTime(uint32_t* _time);

   
    


    private:
    float m_lastTemp;
    
};


