#include <Arduino.h>

// Include libraries:
// Include the specific class to handle the display as a Dashboard
#include "Display.h"
#include "Sim_temp.h"
#include "TimeGap.h"

// #include <DallasTemperature.h>
// #include <OneWire.h>


// OneWire onewire (4);
// DallasTemperature sensors (&onewire);

static Display display;
static TimeGap tempSensorGap(1000);

void setup() 
{
  // put your setup code here, to run once:

  display.init(115200);
  delay(100);

  display.setUpHud();
  delay(1000);


}



void loop() 
{
  
    
  if (tempSensorGap.gap())    //  Verify a gap of 1sec, than ask the sensor.
  { 
    float tempC = 0;

    tempC = getTemp();
    display.dispTemp(tempC);
    
  }
        

}
 