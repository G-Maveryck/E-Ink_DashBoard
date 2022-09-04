/*
Definition of the specific methods for the Display Class.
*/


#include "Display.h"
// #include <Fonts/FreeMonoBold12pt7b.h>
#include "Screen_Config.h"



    //Constructor - Call the constructor of parent class for my specific Display
 Display::Display() : GxEPD2_BW<GxEPD2_150_BN, MAX_HEIGHT(GxEPD2_150_BN)>
 (GxEPD2_150_BN(/*CS=10*/ 10, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7)), 
 m_lastTemp(0), m_LastGaugeState(0)
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
      Display::drawRect(1, 150, 198, 50, GxEPD_BLACK);      //Gauge frame
      Display::drawFastVLine(100, 150, -10, GxEPD_BLACK);   //Middle indication
    
      Display::setCursor(5, 140);
      Display::print("Essence");
      //Display::drawBitmap(5, 140, gImage_LOGO_GAS, 25, 25, GxEPD_BLACK);
        
      
        
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


 void Display::dispGasLevel(uint16_t _nbr)
 {
  
      //Représentation des "etats" (affiché = NOIR, masqué = BLANC) de chaques graduation de la jauge dans un 
   static uint16_t etatJauge[6];

   // uint16_t* et1, et2, et3, et4, et5, et6;

      // Assigne à chaque graduation son état, en fonction du nombre de rectangles à affiché passé en paramètre.
      // Ca marche... Mais c'est TRES lent ! L'arduino met 2 bonnes sec avant d'afficher le résultat.
   for (size_t i = 0; i < 6; i++)
   {
      if (i < _nbr)
      {
         etatJauge[i] = GxEPD_BLACK;
      }
      else
      {
         etatJauge[i] = GxEPD_WHITE;
      }
      
   }


/*
         Tentative d'optimisation = 6 tableau statique constant,
         et un tableau de pointeurs pour "sélectionner" l'affichage.

   static const uint16_t etat3[6] 
   {GxEPD_BLACK, GxEPD_BLACK, GxEPD_BLACK, GxEPD_WHITE, GxEPD_WHITE, GxEPD_WHITE};

   static const uint16_t* etatJaugeptr[6];

   for (size_t i = 0; i < 6; i++)
   {
      {
         etatJaugeptr[i] = &etat3[i];
      }
   }
*/
   

 
   Display::setPartialWindow(2, 152, 196, 40);
   Display::firstPage();
   do
   {
     
      Display::fillScreen(GxEPD_WHITE);

      Display::fillRoundRect(Px1, RECT_POS_Y, RECT_LARG, 39, 5, etatJauge[0]);
      Display::fillRoundRect(Px2, RECT_POS_Y, RECT_LARG, 39, 5, etatJauge[1]);
      Display::fillRoundRect(Px3, RECT_POS_Y, RECT_LARG, 39, 5, etatJauge[2]);

      Display::fillRoundRect(Px4, RECT_POS_Y, RECT_LARG, 39, 5, etatJauge[3]);
      Display::fillRoundRect(Px5, RECT_POS_Y, RECT_LARG, 39, 5, etatJauge[4]);
      Display::fillRoundRect(Px6, RECT_POS_Y, RECT_LARG, 39, 5, etatJauge[5]);
         
 

   } while (Display::nextPage());
  






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
   
