
/*
    Simple helper file, here are two macro defined, usefull for debugging.
    The Arduino's print() and println() function are accessible via these two macro.

    Here is another macro defined in "config.h" that is used to set the project in "Debug" or "Release" mode.

    In Debug, the macros expands to Serial.println(), in Release, they are undefined.
    Used for code readability, and optimisation. The "print" functions used with 
    the macro are disable in release mode.
*/


#include <Arduino.h>
#include "Configuration.hpp"

#ifndef DEBUG_MODE
#error Missing DEBUG_MODE configuration : please see the "Configuration.hpp" file

#else
    #if (DEBUG_MODE == 1)
    #define LOG(x) Serial.print(x)
    #define LOGLN(x) Serial.println(x)
    #endif

    #if (DEBUG_MODE == 0)
    #define LOG(x) 
    #define LOGLN(x)
    #endif

#endif

