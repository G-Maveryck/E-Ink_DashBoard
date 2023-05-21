/*
    Configuration for the displayed information, mostly esthetic.
    Define the used fonts, etc..
*/

#ifndef SCREEN_CONFIGURATION_H
#define SCREEN_CONFIGURATION_H


//#include <Fonts/FreeSansBold18pt7b.h>
#include <Fonts/FreeSansBold12pt7b.h>

//#define FONT_UI &FreeSans9pt7b
//#define FONT_DYN &FreeSansBold18pt7b
#define FONT_DYN &FreeSansBold12pt7b

/////////////////////////////////////

    // Macro for handling the partial window coordinates in a simpler way.
#define FUEL_GAUGE_WINDOW 2, 152, 196, 40
#define AIR_TEMP_WINDOW 10, 50, 50, 30

/////////////////////////////////////

#define G_RAD 3     // Radius
#define G_UNIT_W 27     // Gauge rectangles width
#define G_UNIT_INT 5    // 

#define Py1 154     // Gauge's rectangle Y coordinate
#define Px1 6       // Gauge's rectangle X start coordinate


#endif