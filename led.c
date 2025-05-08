#include "led.h"
#include "gpio.h"
#include "LDR.h"

void LED_init(void) {
    GPIO_setupPinDirection(LED_PORT_ID_RED, LED_PIN_ID_RED, PIN_OUTPUT);
    GPIO_setupPinDirection(LED_PORT_ID_GREEN, LED_PIN_ID_GREEN, PIN_OUTPUT);
    GPIO_setupPinDirection(LED_PORT_ID_BLUE, LED_PIN_ID_BLUE, PIN_OUTPUT);
}

void LED_on(void) {
    uint16 lightIntensity = LDR_getLightIntensity();

    if (lightIntensity < LDR_THRESHOLD_1) {
        GPIO_writePin(LED_PORT_ID_RED, LED_PIN_ID_RED, LOGIC_HIGH);
        GPIO_writePin(LED_PORT_ID_GREEN, LED_PIN_ID_GREEN, LOGIC_HIGH);
        GPIO_writePin(LED_PORT_ID_BLUE, LED_PIN_ID_BLUE, LOGIC_HIGH);
    } else if (lightIntensity >= LDR_THRESHOLD_1 && lightIntensity < LDR_THRESHOLD_2) {
        GPIO_writePin(LED_PORT_ID_RED, LED_PIN_ID_RED, LOGIC_HIGH);
        GPIO_writePin(LED_PORT_ID_GREEN, LED_PIN_ID_GREEN, LOGIC_HIGH);
        GPIO_writePin(LED_PORT_ID_BLUE, LED_PIN_ID_BLUE, LOGIC_LOW);  // Turn off Blue LED
    } else if (lightIntensity >= LDR_THRESHOLD_2 && lightIntensity < LDR_THRESHOLD_3) {
        GPIO_writePin(LED_PORT_ID_RED, LED_PIN_ID_RED, LOGIC_HIGH);
        GPIO_writePin(LED_PORT_ID_GREEN, LED_PIN_ID_GREEN, LOGIC_LOW);  // Turn off Green LED
        GPIO_writePin(LED_PORT_ID_BLUE, LED_PIN_ID_BLUE, LOGIC_LOW);    // Turn off Blue LED
    } else if (lightIntensity >= LDR_THRESHOLD_3) {
        LED_off(); // Turn off all LEDs
    }
}

void LED_off(void) {
    GPIO_writePin(LED_PORT_ID_RED, LED_PIN_ID_RED, LOGIC_LOW);
    GPIO_writePin(LED_PORT_ID_GREEN, LED_PIN_ID_GREEN, LOGIC_LOW);
    GPIO_writePin(LED_PORT_ID_BLUE, LED_PIN_ID_BLUE, LOGIC_LOW);
}
