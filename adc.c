#include "adc.h"
#include "avr/io.h"
#include "common_macros.h"

void ADC_init(void) {
    // Configure ADC
    ADMUX |= (1 << REFS1) | (1 << REFS0);
    ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Enable ADC and set prescaler to 128

} //from instruction set


uint16 ADC_readchannel(uint8 channel_num) {
    channel_num &= 0x07; // Ensure channel number is between 0 and 7
    ADMUX &= 0xE0; // Clear the previous channel selection
    ADMUX |= channel_num; // Set the new channel

    SET_BIT(ADCSRA, ADSC); // Start the conversion
    while (BIT_IS_SET(ADCSRA, ADSC)); // Wait for conversion to complete
    return ADC; // Return the ADC value
}



