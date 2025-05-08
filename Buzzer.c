#include "buzzer.h"
#include "gpio.h"

void Buzzer_init(void) {
    // Set the buzzer pin as output
    GPIO_setupPinDirection(BUZZER_PORT_ID, BUZZER_PIN_ID, PIN_OUTPUT);
    Buzzer_off();  // Make sure the buzzer is off initially
}

void Buzzer_on(void) {

    GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_HIGH);
}

void Buzzer_off(void) {

    GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_LOW);
}
