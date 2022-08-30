#ifndef CONFIG_H
#define CONFIG_H

// Base class GxEPD2_GFX can be used to pass references or pointers to the display instance as parameter, uses ~1.2k more code.
// Enable or disable GxEPD2_GFX base class:
#define ENABLE_GxEPD2_GFX 0

// Arduino:

#define MAX_DISPLAY_BUFFER_SIZE 200

#define MAX_HEIGHT(EPD) (EPD::HEIGHT <= MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8) ? EPD::HEIGHT : MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8))


#endif