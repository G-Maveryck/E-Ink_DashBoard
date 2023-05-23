#ifndef CONFIG_H
#define CONFIG_H


#ifndef BOARD
    #define NANO_EVERY
    #define UNO_R3

    #define BOARD NANO_EVERY
    //#define BOARD UNO_R3
#endif

#ifndef BOARD
    #error You have to specify a board
#endif

    /* Firmware configuration*/

// Setting the debug or release configuration.
// 1 = Debug mode
// 0 = Release mode
#ifndef DEBUG_MODE
#define DEBUG_MODE 1
// #define DEBUG_MODE 0
#endif


    /* Display COnfiguration */
// Base class GxEPD2_GFX can be used to pass references or pointers to the display instance as parameter, uses ~1.2k more code.
// Enable or disable GxEPD2_GFX base class:
#define ENABLE_GxEPD2_GFX 0
#define MAX_DISPLAY_BUFFER_SIZE 200
#define MAX_HEIGHT(EPD) (EPD::HEIGHT <= MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8) ? EPD::HEIGHT : MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8))


    /* Fuel Reading configuration */
// Define here the size of the array used to integrate the reading of fuel level.
// Larger value will uses more RAM.
#define FUEL_ARRAY_SIZE 60

    // This should be egal to 2*tank capacity (in liters). 18 Liters tank = 36 values.
    // This is meant to store every capacitor value per 0.5 liter.
#define CONVERSION_TABLE_SIZE 36

#define CONVTABLE_EEPROM_ADRESS 0


#endif