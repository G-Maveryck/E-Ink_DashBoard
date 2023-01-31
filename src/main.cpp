#include <Arduino.h>

// Include libraries:
// Include the specific class to handle the display as a Dashboard
#include "Display.h"
#include "Timer.h"
#include "Gauge.h"

#include "Sim_temp.h"
#include "Sim_Gauge.h"

// #include <DallasTemperature.h>
// #include <OneWire.h>


// OneWire onewire (4);
// DallasTemperature sensors (&onewire);

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
    int16_t* tempC = new int16_t(0);

    *tempC = getTemp();
    display.dispTemp(tempC);
    
    delete tempC;   
    //////////////////////////////////////////

      // Fuel sensor
      // Ask the sensor each second, and store 1min of data in an array.
    uint16_t readLvl(0), tmp_lvlAvrg(0);
    uint8_t cState(0);

    readLvl = getFuelLevel();
      Serial.print("readLvl =      ");
      Serial.println(readLvl);

    FuelGauge.integrateNewValue(readLvl);
    
    tmp_lvlAvrg = FuelGauge.getLevelAverage();
      Serial.print("Average Level = ");
      Serial.println(tmp_lvlAvrg);

    cState = FuelGauge.curentState();
      Serial.print("cState = ");
      Serial.println(cState);

    
    display.dispGasLevel(cState);
    

    
    


  }


        

}
 