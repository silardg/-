#include <Arduino.h>
#include <JC_Button.h>    
#include "sensors.h"

bool sensor_activated     = true;         // sensor activated bool

Button sensor_onoff_1(SENSOR_ONOFF_1_PIN, 25, true, true);       // define ON
Button sensor_onoff_2(SENSOR_ONOFF_2_PIN, 25, true, true);       // define OFF

// comment out if you don't want serial debug
#define DEBUG

void setup() {

  // debug 
  #ifdef DEBUG
    Serial.begin(9600);
  #endif

  Serial.println("Starting...");

  // setup all to input/output
  init_sensors();

  // setup the button library inputs
  sensor_onoff_1.begin();
  sensor_onoff_2.begin();


}

void loop() {

  // continue if the sensor is activated
  if(sensor_activated == true) {
    // get_sensor
    if(get_sensor() == SENSOR_DETECTED) {

      // the sensor has not_detected, so we have low crate
      valve_off();
      motor_on();

      #ifdef DEBUG
      Serial.println("SENSOR: not detecting... motor ON");
      #endif

    } else {
      // if sensor has not detected low crate, then just turn off the motor (to be sure)
      motor_off();
    }
  }

  // detecting start motor switches
  if(get_start_motor_1() == START_MOTOR_1_NOT_DETECTED ||
     get_start_motor_2() == START_MOTOR_2_NOT_DETECTED) {

    // do start motor
    sensor_activated = true;
    motor_on();
    valve_off();

    #ifdef DEBUG
      Serial.println("START MOTOR: motor on; sensor activated");
    #endif

    delay(100);
  }

  // detecting open valve switches
  if(get_open_valve_1() == OPEN_VALVE_1_NOT_DETECTED ||
     get_open_valve_2() == OPEN_VALVE_2_NOT_DETECTED) {

    // do open valve
    valve_on();
    motor_off();
    delay(50);

    #ifdef DEBUG
      Serial.print("OPEN VALVE: .");
    #endif

    // do it until it is pressed down
    while(get_open_valve_1() == OPEN_VALVE_1_NOT_DETECTED ||
          get_open_valve_2() == OPEN_VALVE_2_NOT_DETECTED) {

        valve_on();
        motor_off();
        delay(50);
    }

    #ifdef DEBUG
      Serial.println("..");
    #endif

    delay(100);

  } else if(get_open_valve_1() == OPEN_VALVE_1_DETECTED &&
            get_open_valve_2() == OPEN_VALVE_2_DETECTED) {

    // close valve
    valve_off();

    delay(100);

  }

  // timer valve switch
  if(get_timer_valve_1() == TIMER_VALVE_1_NOT_DETECTED || 
     get_timer_valve_2() == TIMER_VALVE_2_NOT_DETECTED) {

    // define a counter for delay not to overflow
    int counter = 0;

    valve_on();
    motor_off();

    #ifdef DEBUG
      Serial.print("TIMER VALVE ON: 60s...");
    #endif

    // start timer
    while(counter < 60) {
      delay(1000);
      counter++;
    }

    valve_off();

    #ifdef DEBUG
      Serial.println("done");
    #endif

    delay(100);

  }

  // reading ON/OFF
  sensor_onoff_1.read(); 
  if(sensor_onoff_1.isPressed()) {
    sensor_activated = true;
    #ifdef DEBUG
    Serial.println("SENSOR STATUS: ON");
    #endif
    delay(500);
  } 
  if(sensor_onoff_1.pressedFor(500)) {
    sensor_activated = false;
    #ifdef DEBUG
    Serial.println("SENSOR STATUS: OFF");
    #endif
    while(!sensor_onoff_1.isReleased()) {
      sensor_onoff_1.read();
    }
    delay(1000);
  }

  sensor_onoff_2.read();
  if(sensor_onoff_2.isPressed()) {
    sensor_activated = true;
    #ifdef DEBUG
    Serial.println("SENSOR STATUS: ON");
    #endif
    delay(500);
  } 
  if(sensor_onoff_2.pressedFor(500)) {
    sensor_activated = false;
    #ifdef DEBUG
    Serial.println("SENSOR STATUS: OFF");
    #endif
    while(!sensor_onoff_2.isReleased()) {
      sensor_onoff_2.read();
    }
    delay(1000);
  }
 
  // reading microswitch
  if(get_microswitch() == MICROSWITCH_NOT_DETECTED) {

    motor_off();
    sensor_activated = false;

    #ifdef DEBUG
      Serial.println("MICROSWITCH: motor OFF, sensor not active");
    #endif

    delay(100);

  }

  delay(10);

}