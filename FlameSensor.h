#ifndef FLAMESENSOR_H_
#define FLAMESENSOR_H_

#include "std_types.h"

// Set pins definitions

#define FLAME_SENSOR_PORT_ID   PORTD_ID
#define FLAME_SENSOR_PIN       PD2

// Functions Prototypes

void FlameSensor_init(void);

uint8 FlameSensor_getValue(void);


#endif /* FLAMESENSOR_H_ */
