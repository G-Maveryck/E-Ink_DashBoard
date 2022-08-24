/*
Definition of the specific methods for the Display Class.
*/


#include "Display.h"
#include <Fonts/FreeMonoBold12pt7b.h>


    //Constructor - Call the constructor of parent class for my specific Display
 Display::Display() : GxEPD2_BW<GxEPD2_154_D67, MAX_HEIGHT(GxEPD2_154_D67)>(GxEPD2_154_D67(/*CS=10*/ 10, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7))
 {       
 }

    
 void Display::setUp()
 {
    //Display::init(115200, true, 2, false);      // Initiate the display
    //Display::init(115200); 
    Display::setFullWindow();
    Display::setRotation(1);                    // Set orientation. Goes from 0, 1, 2 or 3

    Display::setTextWrap(false); 
    Display::setFont(&FreeMonoBold12pt7b);
    Display::setTextColor(GxEPD_BLACK);

    
    Display::firstPage();
    do
    {
        Display::drawFastHLine(0, 100, 200, GxEPD_BLACK);
        Display::drawFastVLine(100, 100, -100, GxEPD_BLACK);
       
        Display::setCursor(15,50);
        Display::print("Sec :");

    } while (Display::nextPage());
    
   

 }

 void Display::dispTime(int _time)
 {
    
    
    Display::setRotation(1);
    Display::setFont(&FreeMonoBold12pt7b);
    Display::setTextColor(GxEPD_BLACK);
    
    Display::setPartialWindow(80, 0, 98, 98);
   // Display::setFullWindow();
    Display::firstPage();
    do
    {
       
        //Display::fillScreen(GxEPD_WHITE);
        Display::setCursor(115, 50);
        Display::print("TEST ");
        Display::println(_time);
        
        
    } while (Display::nextPage());
    

 }
   
