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

Gauge fuelGauge;

void setup() 
{
  // put your setup code here, to run once:

  display.begin(115200);
  delay(100);

  display.setUpHud();
  delay(1000);

  display.dispGasLevel(6);
  delay(1000);
    /*
  display.dispGasLevel(5);
  display.dispGasLevel(3);
  display.dispGasLevel(1);
  display.dispGasLevel(2);
  display.dispGasLevel(3);
  display.dispGasLevel(4);
  */
 

}



void loop() 
{
  
    
  if (timerSensor.gap())    //  Verify a gap of 1sec, than ask the sensor.
  { 

      // Temperature sensor 
    int16_t* tempC = new int16_t(0);

    *tempC = getTemp();
    display.dispTemp(tempC);
    
    delete tempC;
    //////////////////////////////////////////

      // Fuel sensor
      // Ask the sensor each second, and store 1min of data in an array.
    fuelGauge.integrateNewValue(getFuelLevel());

    display.dispGasLevel(fuelGauge.gradToDisp());
    

    
    


  }


        

}
 