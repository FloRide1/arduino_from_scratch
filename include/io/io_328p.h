#ifndef IO_328P_H_FILE
#define IO_328P_H_FILE

#include <avr/pgmspace.h>

#include "io.h"

#define NUM_DIGITAL_PINS 20
#define NUM_ANALOG_INPUTS 6

#define NOT_A_PORT 0

const uint8_t PROGMEM PGM_PORT_TO_MODE[] = {
    NOT_A_PORT,
    NOT_A_PORT,
    (uint8_t)&DDRB,
    (uint8_t)&DDRC,
    (uint8_t)&DDRD,
};

const uint8_t PROGMEM PGM_PORT_TO_OUTPUT[] = {
    NOT_A_PORT,
    NOT_A_PORT,
    (uint8_t)&PORTB,
    (uint8_t)&PORTC,
    (uint8_t)&PORTD,
};

const uint8_t PROGMEM PGM_PORT_TO_INPUT[] = {
    NOT_A_PORT,
    NOT_A_PORT,
    (uint8_t)&PINB,
    (uint8_t)&PINC,
    (uint8_t)&PIND,
};

const uint8_t PROGMEM PGM_PIN_TO_PORT[] = {
    PD, /* 0, port D */
    PD,
    PD,
    PD,
    PD,
    PD,
    PD,
    PD,
    PB, /* 8, port B */
    PB,
    PB,
    PB,
    PB,
    PB,
    PC, /* 14, port C */
    PC,
    PC,
    PC,
    PC,
    PC,
};

const uint8_t PROGMEM PGM_PIN_TO_BITMASK[] = {
    MAN_BIT(0), /* 0, port D */
    MAN_BIT(1),
    MAN_BIT(2),
    MAN_BIT(3),
    MAN_BIT(4),
    MAN_BIT(5),
    MAN_BIT(6),
    MAN_BIT(7),
    MAN_BIT(0), /* 8, port B */
    MAN_BIT(1),
    MAN_BIT(2),
    MAN_BIT(3),
    MAN_BIT(4),
    MAN_BIT(5),
    MAN_BIT(0), /* 14, port C */
    MAN_BIT(1),
    MAN_BIT(2),
    MAN_BIT(3),
    MAN_BIT(4),
    MAN_BIT(5),
};

#endif
