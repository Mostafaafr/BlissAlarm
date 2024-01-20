/**
 * @file motor_driver.h
 * @author Abir Hossain (abirh@seas.upenn.edu)
 * @author Mostafa Afr (abirh@seas.upenn.edu)
 * @brief Driver to handle operating motor vibrations. 
 * @version 0.1
 * @date 2023-12-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H
#define MOTOR_DRIVER_PIN PIN_PA06 // Motor driver pin
// Initialization function for the motor driver
void motor_driver_init(int gpio_pin);

// Functions to control the motor in different patterns

void motor_vibrate_continuous(void);
void motor_vibrate_bursts(int burst_duration_ms, int pause_duration_ms, int repeat_count);
void motor_vibrate_timed(int duration_ms);
void motor_vibrate_pattern(int pattern[], int length);
void notify_user(int notif);

// Utility function to stop the motor
void motor_stop(void);

#endif // VIBRATION_MOTOR_DRIVER_H