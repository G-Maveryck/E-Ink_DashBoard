#ifndef CONFIG_H
#define CONFIG_H



// Base class GxEPD2_GFX can be used to pass references or pointers to the display instance as parameter, uses ~1.2k more code.
// Enable or disable GxEPD2_GFX base class:
#define ENABLE_GxEPD2_GFX 0


// Look for your micro-controller section and uncomment the corresponding line
// for your display:
// By default it's set to use Arduino Uno/Nano, ESP8266 and ESP32 with the
// 7.5" epaper display V2 800x480 (GDEW075Z08). Comment that line if you are using
// another display.

// Arduino:

#define MAX_DISPLAY_BUFFER_SIZE 200

#define MAX_HEIGHT(EPD) (EPD::HEIGHT <= MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8) ? EPD::HEIGHT : MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8))


#endif