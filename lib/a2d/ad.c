#include <avr/io.h>
#include "ad.h"


unsigned int ad_read(analog_input_t channel)
{
    unsigned int temp,result;
    ADMUX |= channel;
    ADCSRA = 0x80;  // ADC enabled

    // clear out anything that might already be in results register
    ADCH = 0x00;
    ADCL = 0x00;

    ADCSRA |= (1 << 6);  // start conversion
    while ( (ADCSRA & 0x40) != 0 )  // wait for conversion to complete
    {
        asm ("nop");
    }

    // result is 10 bits long and split across two registers
    temp = ADCL;
    result = ADCH;
    result = (result << 8);
    result |= temp;
    return result;
}
