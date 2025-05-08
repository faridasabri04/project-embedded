#include "LDR.h"
#include "adc.h"
#include "avr/io.h"

uint16 LDR_getLightIntensity(void) {

    uint16 adc_value = 0;

    adc_value = ADC_readchannel(LDR_SENSOR_CHANNEL);

    uint16 light_intensity = (uint16)(((uint32)adc_value*LDR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_MAX_VOLTAGE));

    return light_intensity;  // Return the light intensity (0-100%)
}
