/*
Definition of the specific methods for the Display Class.
*/


#include "Display.hpp"
#include "Bitmaps.h"
#include "Screen_Configuration.h"

#include "DebugMacro.hpp"


Display::Display() : GxEPD2_BW<GxEPD2_150_BN, MAX_HEIGHT(GxEPD2_150_BN)>
      (GxEPD2_150_BN(
         10 /*CS=10*/, 
         8 /*DC=*/, 
         9 /*RST=9*/, 
         7 /*BUSY=*/)), 
      m_lastTemp(0), 
      m_LastGaugeState(0)
      // FuelGaugeWindow{2, 152, 198, 40},
      // AirTempWindow{10, 50, 50, 30}
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
       
         // Air Temp logo 
      drawBitmap(2, 2, epd_bitmap_Logo_Temp_35px, 35, 35, GxEPD_BLACK);

       // Fuel gauge Background and logo
      drawRect(1, 150, 198, 48, GxEPD_BLACK);      // Gauge frame
      drawFastVLine(100, 150, -10, GxEPD_BLACK);   // Middle indication
      drawBitmap(2, 105, epd_bitmap_LOGO_GAS, 36, 36, GxEPD_BLACK);  // Fuel logo
    } while (Display::nextPage());
   
   setFont(FONT_DYN);
}

   // Specific methods for dashboard display.
void Display::dispAirTemp(const int16_t& _temp)
{
   if (_temp != m_lastTemp)
   {
      m_lastTemp = _temp;

      setPartialWindow(AIR_TEMP_WINDOW);
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

      else if (0 <= _gradToDisplay && _gradToDisplay <= 6)
      {
            // Drawing function
         setPartialWindow(FUEL_GAUGE_WINDOW);
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
                     38,                                    /* Height */
                     G_RAD,                                 /* Radius */
                     GxEPD_BLACK                            /* Color */
                     );
            }
         } while (nextPage());  
      }

         // Error Handling
      else
      {
         errorPrompt(_gradToDisplay);
      }
   }

}

void Display::dispCalibrationIdle()
{
   setPartialWindow(FUEL_GAUGE_WINDOW);
   firstPage();
   do
   {
      fillScreen(GxEPD_WHITE);
      // drawRect(5, 155, 190, 34, GxEPD_BLACK);
      
      setCursor(9, 180);
      print("CALIB...");

   } while (nextPage());  

}

void Display::dispReserve()
{
   setPartialWindow(FUEL_GAUGE_WINDOW);
   firstPage();
   do
   {
      fillScreen(GxEPD_WHITE);
      drawRoundRect(Px1, Py1, G_UNIT_W, 38, G_RAD, GxEPD_BLACK);

      setCursor(9, 180);
      print("R");

   } while (nextPage());
     
}


   // Error code handling
void Display::errorPrompt(byte errorCode)
{
   switch (errorCode)
   {
   case 100:   // Error on fuel Gauge.
      setPartialWindow(FUEL_GAUGE_WINDOW);
      firstPage();
      do
      {
         fillScreen(GxEPD_WHITE);
         setCursor(5, 186);
         print("ERR 100");
      } while (nextPage());
      break;
   
   default: //default error
      setPartialWindow(FUEL_GAUGE_WINDOW);
      firstPage();
      do
      {
         fillScreen(GxEPD_WHITE);
         setCursor(5, 186);
         print("ERRUNK");  // Error Unknow
         LOGLN("Invalid graduation number");
      } while (nextPage());
      break;
   }

}
