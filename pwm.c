#include "pwm.h"
#include <avr/io.h>
#include "gpio.h"

void PWM_Timer0_Start(uint8 duty_cycle) {

	GPIO_setupPinDirection(PWM_PORT_ID, PWM_PIN_ID, PIN_OUTPUT);

    TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS02); //Set Fast PWM Mode

    OCR0 = (duty_cycle * 255) / 100; // Convert percentage to 0-255 range
}



