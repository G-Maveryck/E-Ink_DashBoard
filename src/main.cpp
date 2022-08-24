#include <Arduino.h>

// Include libraries:
//#include <GxEPD2_BW.h>  // Include GxEPD2 library for black and white display.
//#include <Adafruit_GFX.h>  // Include Adafruit_GFX library

// Select one and adapt to your mapping
//GxEPD2_BW<GxEPD2_154, MAX_HEIGHT(GxEPD2_154)> display.GxEPD2_154(/*CS=10*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7)); // GDEP015OC1 no longer available
//GxEPD2_BW<GxEPD2_154_D67, MAX_HEIGHT(GxEPD2_154_D67)> display.GxEPD2_154_D67(/*CS=10*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7)); // GDEH0154D67

#include "display.h"    //Include the specific class to handle the display.as a Dashboard
#include <Fonts/FreeMonoBold12pt7b.h>




static Display display;


void setup() 
{
  // put your setup code here, to run once:
  display.init(15200, true, 2, false);
  display.setUp();
  delay(1000);
  
 

}



void loop() 
{
  
  static uint32_t time = 0;
  static uint32_t l_time = 0;
  
  
  time = millis();

  if (time - l_time >= 1000)
  {
    l_time = time;
    
    display.setPartialWindow(50, 50, 68, 68);
    display.firstPage();
    do
    {
      
        
      display.fillScreen(GxEPD_BLACK);
      display.fillRect(75, 75, 50, 50, GxEPD_BLACK);
     
  
    } while (display.nextPage());

   
    
  }

 

}
 /*


  static int Variable1 = 0;
  static int tour = 0;

  Variable1++;  // Increase variable by 1
  if(Variable1 > 150)  // If Variable1 is greater than 150
  {
    Variable1 = 0;  // Set Variable1 to 0
    tour++;

    display.setFullWindow();  // Set full window mode, meaning is going to update the entire screen

    // Here we use paged drawing, even if the processor has enough RAM for full buffer
    // so this can be used with any supported processor board.
    // the cost in code overhead and execution time penalty is marginal
    display.firstPage();  // Tell the graphics class to use paged drawing mode
    do
    {
      display.fillScreen(GxEPD_WHITE);

      display.fillRect(0, 120, 50, 70, GxEPD_BLACK);
      display.fillRect(60, 120, 50, 70, GxEPD_BLACK);
      display.fillRect(120, 120, 50, 70, GxEPD_BLACK);

      display.setTextColor(GxEPD_BLACK);
      display.setFont(&FreeMonoBold12pt7b);
      display.setCursor(15, 15);

      display.print(tour);
      display.println(" tours effectues.");
      
    }
    // Tell the graphics class to transfer the buffer content (page) to the controller buffer.
    // The graphics class will command the controller to refresh to the screen when the last
    // page has been transferred.

    // Returns true if more pages need be drawn and transferred.
    // Returns false if the last page has been transferred and the screen refreshed for
    // panels without fast partial update.
    // Returns false for panels with fast partial update when the controller buffer has
    // been written once more, to make the differential buffers equal.
    // For full buffered with fast partial update the (full) buffer is just transferred
    // again, and false returned.
    while (display.nextPage());  // Print everything we set previously
  }

 


*/
  


  
