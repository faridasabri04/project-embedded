#ifndef LDR_H_
#define LDR_H_

#include "std_types.h"

// Light intensity thresholds
#define LDR_THRESHOLD_1  15  // 15%
#define LDR_THRESHOLD_2  50  // 50%
#define LDR_THRESHOLD_3  70  // 70%

// LDR Pin Definition
#define LDR_SENSOR_CHANNEL   0  // ADC channel for LDR (ADC0, connected to PA0)
#define LDR_MAX_VOLTAGE      2.56 // Reference voltage for the ADC
#define LDR_MAX_LIGHT_INTENSITY 100  // Maximum light intensity (in percentage)

uint16 LDR_getLightIntensity(void);        // Get the light intensity reading

#endif /* LDR_H_ */
