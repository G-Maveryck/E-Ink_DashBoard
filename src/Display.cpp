/*
Definition of the specific methods for the Display Class.
*/


#include "Display.h"
#include <Fonts/FreeMonoBold12pt7b.h>


    //Constructor - Call the constructor of parent class for my specific Display
 Display::Display() : GxEPD2_BW<GxEPD2_150_BN, MAX_HEIGHT(GxEPD2_150_BN)>(GxEPD2_150_BN(/*CS=10*/ 10, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7)), m_lastTemp(0)
 {       
 }

    
 void Display::setUpHud()
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
       
        Display::setCursor(5,15);
        Display::print("Temp :");
        
    } while (Display::nextPage());
    
 }

 
 void Display::dispTemp(float &_temp)
 {
   if (_temp != m_lastTemp)
   {
      m_lastTemp = _temp;

      Display::setPartialWindow(10, 25, 70, 70);
      Display::firstPage();
      do
      {
         Display::setCursor(10, 75);
         Display::print(_temp);

      } while (Display::nextPage());

   }

   
   


 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
    
    // Test method
 void Display::dispTime(uint32_t* _time)
 {
    
 /* Display::setFont(&FreeMonoBold12pt7b);
    Display::setTextColor(GxEPD_BLACK);
    
    Display::setRotation(1);   */
    Display::setPartialWindow(110, 25, 80, 50);
   
    Display::firstPage();
    do
    {
       
        Display::fillScreen(GxEPD_WHITE);
        Display::setCursor(115, 50);
        Display::print(*_time);
        
        
    } while (Display::nextPage());
    

 }
   
