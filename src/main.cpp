#include <Arduino.h>
#include "sensors.h"

bool sensor_activated     = true;
bool kontaktor_activated  = false;
bool valve_activated      = false;

void setup() {

  // debug 
  Serial.begin(9600);

  // setup all to input/output
  init_sensors();

}

void loop() {

  if(sensor_activated == true) {
    // get_sensor
  }

  // microswitch



}