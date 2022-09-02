/*
Definition of the specific methods for the Display Class.
*/


#include "Display.h"
// #include <Fonts/FreeMonoBold12pt7b.h>
#include "Screen_Config.h"

//#include "LOGO_GAS.h"


    //Constructor - Call the constructor of parent class for my specific Display
 Display::Display() : GxEPD2_BW<GxEPD2_150_BN, MAX_HEIGHT(GxEPD2_150_BN)>(GxEPD2_150_BN(/*CS=10*/ 10, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7)), m_lastTemp(0)
 {       
 }

 void Display::begin(uint32_t _bitrate)
{
   Display::init(_bitrate);
}
    
 void Display::setUpHud()
 {
    //Display::init(115200, true, 2, false);      // Initiate the display
    //Display::init(115200); 
    Display::setFullWindow();
    Display::setRotation(1);                    // Set orientation. Goes from 0, 1, 2 or 3

    Display::setTextWrap(false); 
    Display::setFont(FONT_UI);
    Display::setTextColor(GxEPD_BLACK);

    Display::firstPage();
    do
    {
         //UI Element : Speparator segments.
        Display::drawFastHLine(0, 100, 200, GxEPD_BLACK);
        Display::drawFastVLine(100, 100, -100, GxEPD_BLACK);
       
         //Temp indication
        Display::setCursor(5, 15);
        Display::print("Temp :");

         // Fuel gauge Background
        Display::drawRect(1, 150, 198, 50, GxEPD_BLACK);
        Display::drawFastVLine(100, 150, -10, GxEPD_BLACK);
    
        Display::setCursor(5, 140);
        Display::print("Essence");

        //Display::drawChar(gImage_LOGO_GAS);
      
        
    } while (Display::nextPage());
    
    Display::setFont(FONT_DYN);


 }

 
 void Display::dispTemp(int16_t& _temp)
 {
   if (_temp != m_lastTemp)
   {
      m_lastTemp = _temp;

      
      Display::setPartialWindow(10, 25, 70, 70);
      Display::firstPage();
      do
      {
         Display::setCursor(10, 70);
         Display::print(_temp);

      } while (Display::nextPage());

   }


 }


 void Display::dispGasLevel(uint8_t _nbr)
 {
   /*
   static const uint16_t positions[6] 
   {
      Px1, Px2, Px3, Px4, Px5, Px6 
   };
   */

   switch (_nbr)
   {
            // BOILERPLATE AT HIS MAXIMUM
   case 0:
   Display::setPartialWindow(2, 152, 196, 40);
   Display::firstPage();
   do
   {
      Display::drawRoundRect(Px1, RECT_POS_Y, RECT_LARG, 38, 5, GxEPD_BLACK);

      Display::setCursor(5, 185);
      Display::print("R");



   } while (Display::nextPage());
      break;


   case 1:
      Display::setPartialWindow(2, 152, 196, 40);
      Display::firstPage();
      do
      {
         Display::fillScreen(GxEPD_WHITE);

         Display::fillRoundRect(Px1, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);

      } while (Display::nextPage());
      break;
   

   case 2:
      Display::setPartialWindow(2, 152, 196, 40);
      Display::firstPage();
      do
      {
         Display::fillScreen(GxEPD_WHITE);

         Display::fillRoundRect(Px1, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);
         Display::fillRoundRect(Px2, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);
  
      } while (Display::nextPage());
      break;


   case 3:
      Display::setPartialWindow(2, 152, 196, 40);
      Display::firstPage();
      do
      {
         Display::fillScreen(GxEPD_WHITE);

         Display::fillRoundRect(Px1, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);
         Display::fillRoundRect(Px2, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);
         Display::fillRoundRect(Px3, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);
      
      } while (Display::nextPage());
      break;


   case 4:
      Display::setPartialWindow(2, 152, 196, 40);
      Display::firstPage();
      do
      {
         Display::fillScreen(GxEPD_WHITE);

         Display::fillRoundRect(Px1, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);
         Display::fillRoundRect(Px2, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);
         Display::fillRoundRect(Px3, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);

         Display::fillRoundRect(Px4, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);
      
      } while (Display::nextPage());
      break;


   case 5:
      Display::setPartialWindow(2, 152, 196, 40);
      Display::firstPage();
      do
      {
         Display::fillScreen(GxEPD_WHITE);

         Display::fillRoundRect(Px1, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);
         Display::fillRoundRect(Px2, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);
         Display::fillRoundRect(Px3, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);

         Display::fillRoundRect(Px4, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);
         Display::fillRoundRect(Px5, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);
        
      } while (Display::nextPage());
      break;


   case 6:
      Display::setPartialWindow(2, 152, 196, 40);
      Display::firstPage();
      do
      {
         Display::fillScreen(GxEPD_WHITE);

         Display::fillRoundRect(Px1, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);
         Display::fillRoundRect(Px2, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);
         Display::fillRoundRect(Px3, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);

         Display::fillRoundRect(Px4, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);
         Display::fillRoundRect(Px5, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);
         Display::fillRoundRect(Px6, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);
         
      } while (Display::nextPage());
      break;


   default:
      Display::setPartialWindow(2, 152, 196, 40);
      Display::firstPage();
      do
      {
         Display::setCursor(40, 180);
         Display::print("ERR");  
      } while (Display::nextPage());
      break;
   }
  

   /*
   Display::setPartialWindow(2, 152, 196, 40);
   Display::firstPage();
   do
   {
      Display::fillScreen(GxEPD_WHITE);

      Display::fillRoundRect(Px1, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);
      Display::fillRoundRect(Px2, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);
      Display::fillRoundRect(Px3, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);

      Display::fillRoundRect(Px4, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);
      Display::fillRoundRect(Px5, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);
      Display::fillRoundRect(Px6, RECT_POS_Y, RECT_LARG, 39, 5, GxEPD_BLACK);
      


   } while (Display::nextPage());
   */

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
   
