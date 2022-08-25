#include <Arduino.h>

// Include libraries:
// Include the specific class to handle the display as a Dashboard
#include "Display.h"


// Select one and adapt to your mapping
//GxEPD2_BW<GxEPD2_154_D67, MAX_HEIGHT(GxEPD2_154_D67)> display.GxEPD2_154_D67(/*CS=10*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7)); // GDEH0154D67

   


/*
#include <Adafruit_GFX.h>
#include <GxEPD2_BW.h>
//#include "epd/GxEPD2_154_D67.h"
#include "epd/GxEPD2_150_BN.h"

#include <Fonts/FreeMonoBold12pt7b.h>

*/

static Display display;

void setup() 
{
  // put your setup code here, to run once:

  display.init(115200);
  delay(100);

  display.setUpHud();
  delay(1000);

  /*
  display.init(115200);
  delay(100);
  
  display.setFullWindow();
  display.setRotation(1);

  display.setTextWrap(false); 
  display.setFont(&FreeMonoBold12pt7b);
  display.setTextColor(GxEPD_BLACK);
    //Basic configuration for the display
    
  display.firstPage();
  do
  {
      //Draw "hud" Elements, two lines and the label "Sec :"
      display.drawFastHLine(0, 100, 200, GxEPD_BLACK);
      display.drawFastVLine(100, 100, -100, GxEPD_BLACK);
      
      display.setCursor(15,50);
      display.print("Sec :");

  } while (display.nextPage());
    */
 

}



void loop() 
{
  
  static uint32_t time = 0;
  static uint32_t l_time = 0;   //l_time stand for 'Last Time'
  
  
  time = millis();              //store the actual time.

  if (time - l_time >= 1000)    //Verify a gap of 1sec, then, command the display.
  {
    l_time = time;              //store the actual time in 'Last Time' to détermine the next gap

    time = time/1000;           // <-- SHLAG
    uint32_t* time_ptr = &time; // Mumuse avec les pointeurs

    display.dispTime(time_ptr);

  }
        

}
 