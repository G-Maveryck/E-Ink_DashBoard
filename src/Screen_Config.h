
/*
    A E S T H E T I C

    Configuration for the displayed information, mostly esthetic.
    Define the used fonts, etc..

*/

#ifndef SCREEN_CONFIG_H
#define SCREEN_CONFIG_H



//#include <Fonts/FreeSans9pt7b.h>

// #include <Fonts/FreeSansBold12pt7b.h>

#include <Fonts/FreeSansBold18pt7b.h>

//#define FONT_UI &FreeSans9pt7b
#define FONT_DYN &FreeSansBold18pt7b

/////////////////////////////////////


#define G_UNIT_TOT 6

#define G_RAD 3
#define G_UNIT_W 27
#define G_UNIT_INT 5



#define Py1 154
#define Px1 6
#define Px2 (Px1 + G_UNIT_W + G_UNIT_INT)
#define Px3 (Px2 + G_UNIT_W + G_UNIT_INT)
#define Px4 (Px3 + G_UNIT_W + G_UNIT_INT)
#define Px5 (Px4 + G_UNIT_W + G_UNIT_INT)
#define Px6 (Px5 + G_UNIT_W + G_UNIT_INT)






#endif