
/*
    A E S T H E T I C

    Configuration for the displayed information, mostly esthetic.
    Define the used fonts, etc..

*/

#ifndef SCREEN_CONFIG_H
#define SCREEN_CONFIG_H



#include <Fonts/FreeSans9pt7b.h>

// #include <Fonts/FreeSansBold12pt7b.h>

#include <Fonts/FreeSansBold18pt7b.h>

#define FONT_UI &FreeSans9pt7b
#define FONT_DYN &FreeSansBold18pt7b

/////////////////////////////////////


#define NBR_RECT 6

#define RECT_LARG 27
#define RECT_MARGE 5
#define RECT_POS_Y 154



#define Px1 4
#define Px2 (Px1 + RECT_LARG + RECT_MARGE)
#define Px3 (Px2 + RECT_LARG + RECT_MARGE)
#define Px4 (Px3 + RECT_LARG + RECT_MARGE + 5)
#define Px5 (Px4 + RECT_LARG + RECT_MARGE)
#define Px6 (Px5 + RECT_LARG + RECT_MARGE)


#endif