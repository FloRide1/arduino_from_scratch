#ifndef IO_H_FILE
#define IO_H_FILE

#include <avr/io.h>

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#ifdef __AVR_ATmega328P__

#    define NUM_DIGITAL_PINS 20
#    define NUM_ANALOG_INPUTS 6

#    define NOT_A_PORT 0

#endif

/**
 * @brief Configure the pin as an INPUT or an OUTPUT
 */
void pinMode(uint8_t pin, uint8_t mode);

#endif
