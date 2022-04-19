#ifndef IO_H_FILE
#define IO_H_FILE

#include <avr/io.h>
#include <avr/pgmspace.h>

#include "constant.h"

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#define PA 1
#define PB 2
#define PC 3
#define PD 4
#define PE 5
#define PF 6
#define PG 7
#define PH 8

extern const uint8_t PROGMEM PGM_PORT_TO_MODE[];
extern const uint8_t PROGMEM PGM_PORT_TO_OUTPUT[];
extern const uint8_t PROGMEM PGM_PORT_TO_INPUT[];
extern const uint8_t PROGMEM PGM_PIN_TO_PORT[];
extern const uint8_t PROGMEM PGM_PIN_TO_BITMASK[];

#define PIN_TO_PORT(x) (pgm_read_byte(PGM_PIN_TO_PORT + (x)));
#define PIN_TO_BITMASK(x) (pgm_read_byte(PGM_PIN_TO_BITMASK + (x)));
#define PORT_TO_MODE(x) ((volatile uint8_t *)pgm_read_word(PGM_PORT_TO_MODE + (x)));
#define PORT_TO_OUTPUT(x) ((volatile uint8_t *)pgm_read_word(PGM_PORT_TO_OUTPUT + (x)));
#define PORT_TO_INPUT(x) ((volatile uint8_t *)pgm_read_word(PGM_PORT_TO_INPUT + (x)));

/**
 * @brief Configure the pin as an INPUT or an OUTPUT
 */
void pinMode(uint8_t pin, uint8_t mode);

#endif
