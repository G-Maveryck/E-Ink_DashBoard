#include <Arduino.h>

// Include libraries:
//#include <GxEPD2_BW.h>  // Include GxEPD2 library for black and white display.
//#include <Adafruit_GFX.h>  // Include Adafruit_GFX library

// Select one and adapt to your mapping
//GxEPD2_BW<GxEPD2_154, MAX_HEIGHT(GxEPD2_154)> display.GxEPD2_154(/*CS=10*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7)); // GDEP015OC1 no longer available
//GxEPD2_BW<GxEPD2_154_D67, MAX_HEIGHT(GxEPD2_154_D67)> display.GxEPD2_154_D67(/*CS=10*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7)); // GDEH0154D67

//#include "Display.h"    //Include the specific class to handle the display.as a Dashboard

#include <Fonts/FreeMonoBold12pt7b.h>

#include <Adafruit_GFX.h>
#include <GxEPD2_BW.h>
#include "epd/GxEPD2_154_D67.h"


#define ENABLE_GxEPD2_GFX 0
#define MAX_DISPLAY_BUFFER_SIZE 200
#define MAX_HEIGHT(EPD) (EPD::HEIGHT <= MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8) ? EPD::HEIGHT : MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8))




GxEPD2_BW<GxEPD2_154_D67, MAX_HEIGHT(GxEPD2_154_D67)> display(GxEPD2_154_D67(/*CS=10*/ 10, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7));


void setup() 
{
  // put your setup code here, to run once:
  display.init(15200);
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
    
 

}



void loop() 
{
  
  static uint32_t time = 0;
  static uint32_t l_time = 0;   //l_time stand for 'Last Time'
  
  
  time = millis();              //store the actual time.

  if (time - l_time >= 1000)    //Verify a gap of 1sec, then, command the display.
  {
    l_time = time;              //store the actual time in 'Last Time' to détermine the next gap
    
    
    display.setPartialWindow(100, 0, 98, 98);   // <-- don't want to work...
    display.setRotation(1);
    display.setFont(&FreeMonoBold12pt7b);
    display.setTextColor(GxEPD_BLACK);          //Configuration again. Don't know if it's needed. I just looked at how some other people code were built...

    display.firstPage();
    do
    {
      
      display.fillScreen(GxEPD_WHITE);    //Clean the previous display in the 
      display.setCursor(115, 50);
      display.print(time/1000);           // print the time value in front of the "Sec" label.
     
  
    } while (display.nextPage());

   
    
  }
        //this whole loop don't display anything. I don't know why...


}
 