#define TEMP_H 1

/**************************************************************************/
/*!
This is a demo for the Adafruit MCP9808 breakout
----> http://www.adafruit.com/products/1782
Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!
*/
/**************************************************************************/

#include <Wire.h>
#include "Adafruit_MCP9808.h"

// Create the MCP9808 temperature sensor object
#define TEMP_NUM 6
Adafruit_MCP9808 tempsensor[TEMP_NUM];
//Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();

/* IDs in order from left to right top to bottom */
int temp_id[] = {2, 0, 3, 7, 4, 1};
#define TEMP_BASE_ID 0x18

int temp_setup() {
  int ret = 0;
  for (int i = 0; i < TEMP_NUM; i++)
  {
    int id = TEMP_BASE_ID + temp_id[i];
    tempsensor[i] = Adafruit_MCP9808();
    Serial.println(id);
    delay(10);
    if (!tempsensor[i].begin(id)) ret += 1;
    tempsensor[i].setResolution(3); // sets the resolution mode of reading, the modes are defined in the table bellow:
    delay(10);
  }
  
  // Make sure the sensor is found, you can also pass in a different i2c
  // address with tempsensor.begin(0x19) for example, also can be left in blank for default address use
  // Also there is a table with all addres possible for this sensor, you can connect multiple sensors
  // to the same i2c bus, just configure each sensor with a different address and define multiple objects for that
  //  A2 A1 A0 address
  //  0  0  0   0x18  this is the default address
  //  0  0  1   0x19
  //  0  1  0   0x1A
  //  0  1  1   0x1B
  //  1  0  0   0x1C
  //  1  0  1   0x1D
  //  1  1  0   0x1E
  //  1  1  1   0x1F
  
  // Mode Resolution SampleTime
  //  0    0.5°C       30 ms
  //  1    0.25°C      65 ms
  //  2    0.125°C     130 ms
  //  3    0.0625°C    250 ms

  if( ret > 0) return 1;
  return 0;
}


/*
void temp_get_demo() {
  Serial.println("wake up MCP9808.... "); // wake up MCP9808 - power consumption ~200 mikro Ampere
  tempsensor.wake();   // wake up, ready to read!

  // Read and print out the temperature, also shows the resolution mode used for reading.
  Serial.print("Resolution in mode: ");
  Serial.println (tempsensor.getResolution());
  float c = tempsensor.readTempC();
  float f = tempsensor.readTempF();
  Serial.print("Temp: "); 
  Serial.print(c, 4); Serial.print("*C\t and "); 
  Serial.print(f, 4); Serial.println("*F.");
  
  delay(2000);
  Serial.println("Shutdown MCP9808.... ");
  tempsensor.shutdown_wake(1); // shutdown MSP9808 - power consumption ~0.1 mikro Ampere, stops temperature sampling
  Serial.println("");
  delay(200);
}

*/


float temp_get_id(int id)
{
  Serial.println("wake up MCP9808.... "); // wake up MCP9808 - power consumption ~200 mikro Ampere
  tempsensor[id].wake();   // wake up, ready to read!

  // Read and print out the temperature, also shows the resolution mode used for reading.
  Serial.print("Resolution in mode: ");
  Serial.println (tempsensor[id].getResolution());
  float c = tempsensor[id].readTempC();
  // float f = tempsensor.readTempF();
  //Serial.print("Temp: "); 
  //Serial.print(c, 4); Serial.print("*C\t and "); 
  //Serial.print(f, 4); Serial.println("*F.");
  
  //delay(2000);
  Serial.println("Shutdown MCP9808.... ");
  tempsensor[id].shutdown_wake(1); // shutdown MSP9808 - power consumption ~0.1 mikro Ampere, stops temperature sampling
  Serial.println("");
  delay(200);
  return c;
}



String temp_get()
{
  String m_str = "START,";     // empty string
  m_str.concat(FRAME_ID);
  m_str.concat(",");
  for (int i; i < TEMP_NUM; i++)
  {
    float val = temp_get_id(i);
    m_str.concat(val);
    m_str.concat(",");
  }
  m_str.concat("END\r\n");
  //m_str.concat(char(13));
  return m_str;
}
