/*
Specific class for using easily the 1.54" E-Paper display as a dashboard.

This class uses the libraries for handling the display in a specific purpose.
*/



    //Include needed Libraries
#include <GxEPD2_BW.h>
#include "epd/GxEPD2_150_BN.h"

    //Definition file for my specific screen
#include "config.h"



class Display : public GxEPD2_BW<GxEPD2_150_BN, MAX_HEIGHT(GxEPD2_150_BN)>    //Inheritance of the BW Template Class with specific parameters.
{
    public:

    Display();      //Constructeur
    
    void setUpHud();   //Configure the e-paper display, refresh it, and draw HUD elements
    void dispTime(uint32_t* _time);


    
    private:
   // int16_t m_lastTemp;

};


