/**
 * @file motor_driver.c
 * @author Abir Hossain (abirh@seas.upenn.edu)
 * @author Mostafa Afr (abirh@seas.upenn.edu)
 * @brief Driver to handle operating motor vibrations. 
 * @version 0.1
 * @date 2023-12-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "motor_driver.h"
#include <asf.h> // Assuming Atmel Software Framework is used

static int motor_gpio_pin;

/**
 * @brief Initializes the motor driver, and
 * sets the GPIO pin the motor is connected to.
 * 
 * @param gpio_pin Pin the motor is connected to
 * on the board
 */
void motor_driver_init(int gpio_pin) {
    motor_gpio_pin = gpio_pin;
    // Configure the GPIO pin as output
    struct port_config pin_conf;
    port_get_config_defaults(&pin_conf);
    pin_conf.direction  = PORT_PIN_DIR_OUTPUT;
    port_pin_set_config(motor_gpio_pin, &pin_conf);
}

/**
 * @brief Sets the motor to vibrate 
 * continuously. 
 * 
 */
void motor_vibrate_continuous(void) {
    port_pin_set_output_level(motor_gpio_pin, true);
}

/**
 * @brief Sets the motor to vibrate in
 * bursts at a time.
 * 
 * @param burst_duration_ms Time to vibrate for (in ms)
 * @param pause_duration_ms Pause time in between vibrations (in ms)
 * @param repeat_count Number of times to repeat bursts
 */
void motor_vibrate_bursts(int burst_duration_ms, int pause_duration_ms, int repeat_count) {
    for (int i = 0; i < repeat_count; i++) {
        port_pin_set_output_level(motor_gpio_pin, true);
        delay_ms(burst_duration_ms);
        port_pin_set_output_level(motor_gpio_pin, false);
        delay_ms(pause_duration_ms);
    }
}

/**
 * @brief Vibrates motor for a designated
 * amount of time.
 * 
 * @param duration_ms Time to vibrate motor for.
 */
void motor_vibrate_timed(int duration_ms) {
    motor_vibrate_continuous();
    delay_ms(duration_ms);
    motor_stop();
}

/**
 * @brief Vibrates the motor in different
 * pattersns.
 * 
 * @param pattern Pattern for motor to vibrate
 * in.
 * @param length Length of pattern.
 */
void motor_vibrate_pattern(int pattern[], int length) {
    for (int i = 0; i < length; ++i) {
        if (pattern[i] > 0) {
            port_pin_set_output_level(motor_gpio_pin, true);
            delay_ms(pattern[i]);
        } else {
            port_pin_set_output_level(motor_gpio_pin, false);
            delay_ms(-pattern[i]);
        }
    }
}

/**
 * @brief Sets the pin output level to LOW,
 * so the motor stops vibrating.
 * 
 */
void motor_stop(void) {
    port_pin_set_output_level(motor_gpio_pin, false);
}

/**
 * @brief Various notifiations for the user, which
 * send the motor different patters of vibrations
 * based on the notification type. 
 * 
 * @param notif 
 */
void notify_user(int notif) {
    switch (notif) {
        case 1:
            {int pattern1[] = {100, -100, 100, -100, 100};
            motor_vibrate_pattern(pattern1, 5);
            break;}

        case 2: 
            {int pattern2[] = {1300, -1000, 1300, -1000, 1300, -1000};
            motor_vibrate_pattern(pattern2, 6);
            break;}

        case 3:
            {int pattern3[] = {100, -100, 100, -500, 100, -100, 100};
            motor_vibrate_pattern(pattern3, 7);
            break;}

        case 4: 
            {int pattern4[] = {500, -200, 500, -200, 500};
            motor_vibrate_pattern(pattern4, 5);
            break;}

        case 5: 
            {int pattern5[] = {300, -100};
            motor_vibrate_pattern(pattern5, 2);
            break;}

        case 6: 
            {int pattern6[] = {300, -100, 200, -100, 100, -100};
            motor_vibrate_pattern(pattern6, 6);
            break;}

        case 7:
            {int pattern7[] = {300, -100, 300, -100, 300, -500, 300, -100, 300, -100, 300};
            motor_vibrate_pattern(pattern7, 11);
            break;}

        case 8: 
            {int pattern8[] = {100, -50, 100, -50, 100, -50, 100, -50, 100, -50, 100, -50};
            motor_vibrate_pattern(pattern8, 12);
            break;}

        case 9:
            {int pattern9[] = {200, -100, 200, -100, 200, -300, 200, -100, 200};
            motor_vibrate_pattern(pattern9, 9);
            break;}

        case 10: 
            {int pattern10[] = {300, -300, 100};
            motor_vibrate_pattern(pattern10, 3);
            break;}

        default:
            break;
    }
}