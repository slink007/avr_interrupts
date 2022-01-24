#ifndef AD_H
#define AD_H

typedef enum {AD0, AD1, AD2, AD3, AD4, AD5, AD6, AD7} analog_input_t;


/*
 * Provide the A-to-D channel to read and get the raw A-to-D count
 * as an output.  The caller must convert this back into volts, or temperature,
 * or whatever is being measured.
 *
 * Uses blocking to wait on conversion to complete.
 */
 unsigned int ad_read(analog_input_t channel);

#endif
