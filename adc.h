#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

// Define the maximum ADC value and reference voltage
#define ADC_MAXIMUM_VALUE 1023
#define ADC_REF_VOLT_VALUE 2.56

// Function Prototypes

void ADC_init(void);
uint16 ADC_readchannel(uint8 channel_num);

#endif /* ADC_H_ */
