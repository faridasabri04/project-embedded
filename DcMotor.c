#include "DcMotor.h"
#include "gpio.h"
#include "pwm.h"
#include "avr/io.h"

void DcMotor_Init(void) {
    // Set the motor control pins (IN1, IN2) as output
    GPIO_setupPinDirection(MOTOR_PORT_ID, MOTOR_PIN_IN1, PIN_OUTPUT);
    GPIO_setupPinDirection(MOTOR_PORT_ID, MOTOR_PIN_IN2, PIN_OUTPUT);

    // Set the motor enable pin (PWM pin OC0) as output
    GPIO_setupPinDirection(MOTOR_PORT_ID, MOTOR_ENABLE_PIN, PIN_OUTPUT);

    // Initially stop the motor
    GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN_IN1, LOGIC_LOW);
    GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN_IN2, LOGIC_LOW);

    // Start PWM with 0% duty cycle (motor off initially)
    PWM_Timer0_Start(0);
}

void DcMotor_Rotate(DcMotor_State state, uint8 speed) {
    uint8 duty_cycle = (speed > 100) ? 100 : speed;  // Ensure speed is capped at 100%

    // Control motor direction based on the state
    switch (state) {
        case CW:
            GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN_IN1, LOGIC_LOW);
            GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN_IN2, LOGIC_HIGH);
            break;

        case ACW:

            GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN_IN1, LOGIC_HIGH);
            GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN_IN2, LOGIC_LOW);
            break;

        case STOP:
            GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN_IN1, LOGIC_LOW);
            GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN_IN2, LOGIC_LOW);
            break;

        default:
            // Stop the motor in case of an invalid state
            GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN_IN1, LOGIC_LOW);
            GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN_IN2, LOGIC_LOW);
            break;
    }

    // Set the PWM duty cycle to control the speed of the motor
    PWM_Timer0_Start(duty_cycle);
}
