#ifndef LED_H_
#define LED_H_

#include "std_types.h"

// LED Port and Pin Definitions
#define LED_PORT_ID_RED      PORTB_ID
#define LED_PIN_ID_RED       PIN5_ID

#define LED_PORT_ID_GREEN    PORTB_ID
#define LED_PIN_ID_GREEN     PIN6_ID

#define LED_PORT_ID_BLUE     PORTB_ID
#define LED_PIN_ID_BLUE      PIN7_ID

// Function Prototypes
void LED_init(void);
void LED_on(void);
void LED_off(void);

#endif /* LED_H_ */
