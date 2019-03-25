#include <Arduino.h>
#include "sensors.h"

uint8_t get_sensor(void) {

    if(digitalRead(SENSOR_PIN) == SENSOR_DETECTED) {
        return DETECTED;
    } else {
        return NOT_DETECTED;
    }

}

uint8_t get_microswitch(void) {

    if(digitalRead(MICROSWITCH_PIN) == MICROSWITCH_DETECTED) {
        return DETECTED;
    } else {
        return NOT_DETECTED;
    }

}

uint8_t get_start_motor_1(void) {

    if(digitalRead(START_MOTOR_1_PIN) == START_MOTOR_1_DETECTED) {
        return DETECTED;
    } else {
        return NOT_DETECTED;
    }

}

uint8_t get_open_valve_1(void) {

    if(digitalRead(OPEN_VALVE_1_PIN) == OPEN_VALVE_1_DETECTED) {
        return DETECTED;
    } else {
        return NOT_DETECTED;
    }

}

uint8_t get_timer_valve_1(void) {

    if(digitalRead(TIMER_VALVE_1_PIN) == TIMER_VALVE_1_DETECTED) {
        return DETECTED;
    } else {
        return NOT_DETECTED;
    }

}

uint8_t get_sensor_onoff_1(void) {

    if(digitalRead(SENSOR_ONOFF_1_PIN) == SENSOR_ONOFF_1_DETECTED) {
        return DETECTED;
    } else {
        return NOT_DETECTED;
    }

}

uint8_t get_start_motor_2(void) {

    if(digitalRead(START_MOTOR_2_PIN) == START_MOTOR_2_DETECTED) {
        return DETECTED;
    } else {
        return NOT_DETECTED;
    }

}

uint8_t get_open_valve_2(void) {

    if(digitalRead(OPEN_VALVE_2_PIN) == OPEN_VALVE_2_DETECTED) {
        return DETECTED;
    } else {
        return NOT_DETECTED;
    }

}

uint8_t get_timer_valve_2(void) {

    if(digitalRead(TIMER_VALVE_2_PIN) == TIMER_VALVE_2_DETECTED) {
        return DETECTED;
    } else {
        return NOT_DETECTED;
    }

}

uint8_t get_sensor_onoff_2(void) {

    if(digitalRead(SENSOR_ONOFF_2_PIN) == SENSOR_ONOFF_2_DETECTED) {
        return DETECTED;
    } else {
        return NOT_DETECTED;
    }

}

void init_sensors(void) {
    
    // sensor board - 6
    pinMode(SENSOR_PIN, INPUT);
    pinMode(MICROSWITCH_PIN, INPUT);
    pinMode(START_MOTOR_1_PIN, INPUT);
    pinMode(OPEN_VALVE_1_PIN, INPUT);
    pinMode(TIMER_VALVE_1_PIN, INPUT);
    pinMode(SENSOR_ONOFF_1_PIN, INPUT);

    // sensor board - 4
    pinMode(START_MOTOR_2_PIN, INPUT);
    pinMode(OPEN_VALVE_2_PIN, INPUT);
    pinMode(TIMER_VALVE_2_PIN, INPUT);
    pinMode(SENSOR_ONOFF_2_PIN, INPUT);

    // relay board 
    pinMode(KONTAKTOR_RELAY_PIN, OUTPUT);
    pinMode(VALVE_RELAY_PIN, OUTPUT);
}