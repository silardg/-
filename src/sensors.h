#ifndef SENSOR_H
#define SENSOR_H

// global help defines
#define DETECTED            1
#define NOT_DETECTED        0

/************************
 *    SENSOR BOARD 6    *                   
 ************************/

#define SENSOR_PIN                          5
#define SENSOR_DETECTED                     0
#define SENSOR_NOT_DETECTED                 1

#define MICROSWITCH_PIN                     6
#define MICROSWITCH_DETECTED                0
#define MICROSWITCH_NOT_DETECTED            1

#define START_MOTOR_1_PIN                   7
#define START_MOTOR_1_DETECTED              0
#define START_MOTOR_1_NOT_DETECTED          1

#define OPEN_VALVE_1_PIN                    8
#define OPEN_VALVE_1_DETECTED               0
#define OPEN_VALVE_1_NOT_DETECTED           1

#define TIMER_VALVE_1_PIN                   9
#define TIMER_VALVE_1_DETECTED              0
#define TIMER_VALVE_1_NOT_DETECTED          1

#define SENSOR_ONOFF_1_PIN                  10
#define SENSOR_ONOFF_1_DETECTED             0
#define SENSOR_ONOFF_1_NOT_DETECTED         1
 /***********************/

 /************************
 *    SENSOR BOARD 4    *                   
 ************************/
#define START_MOTOR_2_PIN                   12
#define START_MOTOR_2_DETECTED              0
#define START_MOTOR_2_NOT_DETECTED          1

#define OPEN_VALVE_2_PIN                    11
#define OPEN_VALVE_2_DETECTED               0
#define OPEN_VALVE_2_NOT_DETECTED           1

#define TIMER_VALVE_2_PIN                   A0
#define TIMER_VALVE_2_DETECTED              0
#define TIMER_VALVE_2_NOT_DETECTED          1

#define SENSOR_ONOFF_2_PIN                  A1
#define SENSOR_ONOFF_2_DETECTED             0
#define SENSOR_ONOFF_2_NOT_DETECTED         1
 /***********************/

/************************
 *      RELAY BOARD     *                   
 ************************/

#define KONTAKTOR_RELAY_PIN                 A5

#define VALVE_RELAY_PIN                     A4

 /***********************/


void init_sensors(void);
uint8_t get_sensor(void);
uint8_t get_microswitch(void);
uint8_t get_start_motor_1(void);
uint8_t get_open_valve_1(void);
uint8_t get_timer_valve_1(void);
uint8_t get_sensor_onoff_1(void);
uint8_t get_start_motor_2(void);
uint8_t get_open_valve_2(void);
uint8_t get_timer_valve_2(void);
uint8_t get_sensor_onoff_2(void);

void motor_on(void);
void motor_off(void);
void valve_on(void);
void valve_off(void);

#endif