/*
Definition of the specific methods for the Display Class.
*/


#include "Display.hpp"
#include <Fonts/FreeMonoBold12pt7b.h>
#include "Screen_Config.h"
#include "Bitmaps.h"
#include "Timer.h"

    //Constructor - Call the constructor of parent class for my specific Display
 
 Display::Display() : GxEPD2_BW<GxEPD2_150_BN, MAX_HEIGHT(GxEPD2_150_BN)>
   (GxEPD2_150_BN(/*CS=10*/   10, 
                  /*DC=*/     8, 
                  /*RST=*/    9, 
                  /*BUSY=*/   7) ), 
   m_lastTemp(0), 
   m_LastGaugeState(0)
   {
   }

 Display::~Display()
 {
 }

 void Display::begin(uint32_t _bitrate)
{
   init(_bitrate);
}

 void Display::setUpHud()
 {

   setFullWindow();
   setRotation(1);                  // Set orientation. Goes from 0, 1, 2 or 3

   setTextWrap(false); 
   setTextColor(GxEPD_BLACK);

   firstPage();
    do
    {
         //UI Element : Speparator segments.
      drawFastHLine(0, 100, 200, GxEPD_BLACK);
      drawFastVLine(100, 100, -100, GxEPD_BLACK);
       
         //Temp indication     
      drawBitmap(2, 2, epd_bitmap_Logo_Temp_35px, 35, 35, GxEPD_BLACK);

       // Fuel gauge Background
      drawRect(1, 150, 198, 50, GxEPD_BLACK);      // Gauge frame
      drawFastVLine(100, 150, -10, GxEPD_BLACK);   // Middle indication
      drawBitmap(2, 105, epd_bitmap_LOGO_GAS, 36, 36, GxEPD_BLACK);
      
    } while (Display::nextPage());
   
   setFont(FONT_DYN);
 }

   // Specific methods for dashboard display.
 void Display::dispTemp(const int16_t& _temp)
 {
   if (_temp != m_lastTemp)
   {
      m_lastTemp = _temp;

      setPartialWindow(10, 50, 50, 30);
      firstPage();
      do
      {
         setCursor(10, 75);
         print(_temp);

      } while (nextPage());
   }
}

 void Display::dispGasLevel(const uint8_t& _gradToDisplay)
 {
   if (_gradToDisplay != m_LastGaugeState)
   {
      m_LastGaugeState = _gradToDisplay;
      
      if (_gradToDisplay == 1)
      {
       dispReserve();
      }

      else
      {
         setPartialWindow(2, 152, 196, 40);
         firstPage();
         do
         {
            fillScreen(GxEPD_WHITE);

            for (uint8_t i = 0; i < _gradToDisplay; i++)
            {
               fillRoundRect( 
                     (Px1 + (G_UNIT_W + G_UNIT_INT) * i),   /* X coordinate */
                     Py1,                                   /* Y coordinate */
                     G_UNIT_W,                              /* Width */
                     39,                                    /* Height */
                     G_RAD, GxEPD_BLACK                     /* Radius, Color */
                     );
            }
            
            
         } while (nextPage());
         
         




       /* 
         static uint16_t colorBlack = GxEPD_BLACK;
         static uint16_t colorWhite = GxEPD_WHITE;
         
         uint16_t* graduationGauge[6];

         for (uint8_t i = 0; i < _gradToDisplay; i++)
         {
            graduationGauge[i] = &colorBlack;
         }

         for (uint8_t i = _gradToDisplay; i < 6; i++)
         {
            graduationGauge[i] = &colorWhite;
         }

         
         
         setPartialWindow(2, 152, 196, 40);
         firstPage();
         do
         {
            fillScreen(GxEPD_WHITE);

            fillRoundRect(Px1, Py1, G_UNIT_W, 39, G_RAD, *graduationGauge[0]);
            fillRoundRect(Px2, Py1, G_UNIT_W, 39, G_RAD, *graduationGauge[1]);
            fillRoundRect(Px3, Py1, G_UNIT_W, 39, G_RAD, *graduationGauge[2]);

            fillRoundRect(Px4, Py1, G_UNIT_W, 39, G_RAD, *graduationGauge[3]);
            fillRoundRect(Px5, Py1, G_UNIT_W, 39, G_RAD, *graduationGauge[4]);
            fillRoundRect(Px6, Py1, G_UNIT_W, 39, G_RAD, *graduationGauge[5]);
         */
      }
   
   }

 }
  

void Display::dispReserve()
{
   setPartialWindow(2, 152, 196, 40);
   firstPage();
   do
   {
      fillScreen(GxEPD_WHITE);

      drawRoundRect(Px1, Py1, G_UNIT_W, 39, G_RAD, GxEPD_BLACK);

      setCursor(5, 186);
      print("R");

   } while (nextPage());
     

}
 
 
 
 
 

 
 
 
 
 
 
    
    // Test method
 void Display::dispTime(uint32_t* _time)
 {
    
 /* setFont(&FreeMonoBold12pt7b);
    setTextColor(GxEPD_BLACK);
    
    setRotation(1);   */
    setPartialWindow(110, 25, 80, 50);
   
    firstPage();
    do
    {
       
        fillScreen(GxEPD_WHITE);
        setCursor(115, 50);
        print(*_time);
        
        
    } while (nextPage());
    

 }
   
