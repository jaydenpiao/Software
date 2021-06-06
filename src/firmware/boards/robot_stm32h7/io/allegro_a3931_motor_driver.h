#pragma once
/**
 * This file is an abstraction around the Allegro A3931 Motor Driver
 */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#include "firmware/boards/robot_stm32h7/Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal.h"
#pragma GCC diagnostic pop

#include "firmware/boards/robot_stm32h7/io/gpio_pin.h"
#include "firmware/boards/robot_stm32h7/io/pwm_pin.h"

typedef enum
{
    CLOCKWISE,
    COUNTERCLOCKWISE
} AllegroA3931MotorDriverDriveDirection;

typedef struct AllegroA3931MotorDriver AllegroA3931MotorDriver_t;

/**
 * Create a Motor Driver
 * @param pwm_pin The PWM pin to the driver. Note that this must be configured to
 *                operate in the correct frequency range for the motor driver. Please
 *                talk to Elec. to determine this.
 * @param direction_pin A GPIO pin connected to the "direction" pin on the motor driver.
 *
 * @return A motor driver with the pwm percentage set to zero.
 */
AllegroA3931MotorDriver_t* io_allegro_a3931_motor_driver_create(PwmPin_t* pwm_pin,
                                                                GpioPin_t* direction_pin);

/**
 * Destroy the given motor driver
 * @param motor_driver The motor driver to destroy
 */
void io_allegro_a3931_motor_driver_destroy(AllegroA3931MotorDriver_t* motor_driver);

/**
 * Set the rotation direction for the given motor driver
 *
 * Note that the rotation is from the perspective of rear of the motor, looking down
 * the shaft starting from the motor body
 *
 * @param motor_driver
 * @param direction
 */
void io_allegro_a3931_motor_driver_setDirection(
    AllegroA3931MotorDriver_t* motor_driver,
    AllegroA3931MotorDriverDriveDirection direction);

/**
 * Set the PWM percentage for the given motor driver
 *
 * NOTE: The motor driver will be automatically enabled when the PWM
 * is set.
 *
 * @param motor_driver
 * @param pwm_percentage A value in [0,1] indicating the PWM percentage
 */
void io_allegro_a3931_motor_setPwmPercentage(AllegroA3931MotorDriver_t* motor_driver,
                                             float pwm_percentage);
