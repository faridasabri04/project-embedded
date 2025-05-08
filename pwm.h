#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"

#define PWM_PORT_ID PORTB
#define PWM_PIN_ID  PB3
// Function prototype
void PWM_Timer0_Start(uint8 duty_cycle); // Initialize Timer0 and set duty cycle

#endif /* PWM_H_ */
