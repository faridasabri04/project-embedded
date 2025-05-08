#include "FlameSensor.h"
#include "gpio.h"
#include "avr/io.h"



void FlameSensor_init(void) {
    GPIO_setupPinDirection(PORTD_ID, FLAME_SENSOR_PIN, PIN_INPUT);  // Set the sensor pin as input
}

uint8 FlameSensor_getValue(void) {
    return GPIO_readPin(PORTD_ID, FLAME_SENSOR_PIN);  // Return the pin's value (fire detected or not)
}
