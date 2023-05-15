#include <Arduino.h>

#include "Display.hpp"
#include "Timer.h"
#include "Gauge.hpp"

#include "Sim_temp.hpp"
#include "Sim_Gauge.hpp"

#include "DebugMacro.hpp"

/*
#include <DallasTemperature.h>
#include <OneWire.h>


OneWire onewire (4);
DallasTemperature sensors (&onewire);
*/

Display display;
ObjTimer timerSensor(1000);

Gauge FuelGauge;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(100);

  display.begin(115200);
  delay(100);

  display.setUpHud();
  // delay(1000);

  display.dispGasLevel(6);
  // delay(1000);
    
 

}



void loop() 
{
  
    
  if (timerSensor.gap())    //  Verify a gap of 1sec, then ask the sensor.
  { 
    
      // Temperature sensor 
    int16_t tempC(0);
    tempC = getTemp();

    display.dispTemp(tempC);
    
    //////////////////////////////////////////

      // Fuel sensor
      // Ask the sensor each second, and store 1min of data in an array.
    uint16_t readLvl(0), tmp_lvlAvrg(0);
    uint8_t cState(0);

    readLvl = getFuelLevel();
      PRINT("readLvl =      ");
      PRINTLN(readLvl);

    FuelGauge.integrateNewValue(readLvl);
    
    tmp_lvlAvrg = FuelGauge.getLevelAverage();
      PRINT("Average Level = ");
      PRINTLN(tmp_lvlAvrg);

    cState = FuelGauge.curentState();
      PRINT("cState = ");
      PRINTLN(cState);

    
    display.dispGasLevel(cState);

  }

}
 