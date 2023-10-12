#include <Arduino.h>

#include "Display.hpp"
#include "GTimer.hpp"
#include "Gauge.hpp"

#include "Sim_temp.hpp"
#include "Sim_Gauge.hpp"

#include "Screen_Configuration.h"
#include "DebugMacro.hpp"


#include <DallasTemperature.h>
#include <OneWire.h>


OneWire onewire(4);
DallasTemperature tempSensor(&onewire);

Display display;
GTimer timerSensor(1000);

Gauge FuelGauge;

void setup() 
{
  Serial.begin(115200);
  delay(100);

  display.begin(115200);
  delay(100);

  display.setUpHud();
  // delay(1000);

  display.dispGasLevel(1);
  // delay(1000);
    
  tempSensor.begin();
 

}



void loop() 
{
  
  if (timerSensor.timeOut())    //  Verify a gap of 1sec, then ask the sensor.
  { 
      // Temperature sensor 
    // int16_t tempC(getTemp());

    Serial.print("Temperature for the device 1 (index 0) is: ");
    Serial.println(tempSensor.getTempCByIndex(0));

    // display.dispAirTemp(tempC);
    
    //////////////////////////////////////////

      // Fuel sensor
      // Ask the sensor each second, and store 1min of data in an array.
    uint16_t readLvl(0), tmp_lvlAvrg(0);
    uint8_t cState(0);

    readLvl = getFuelLevel();
    LOG("readLvl =      ");
    LOGLN(readLvl);

    FuelGauge.integrateNewValue(readLvl);
    
    tmp_lvlAvrg = FuelGauge.getLevelAverage();
    LOG("Average Level = ");
    LOGLN(tmp_lvlAvrg);

    cState = FuelGauge.curentState();

    display.dispGasLevel(cState);

    LOGLN(" ");

  }

}
 