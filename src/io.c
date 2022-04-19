#include "io.h"

#ifdef __AVR_ATmega328P__
#    include <io/io_328p.h>
#endif

// FIXME: INPUT_PULLUP
void pinMode(uint8_t pin, uint8_t mode)
{
    if (pin >= NUM_DIGITAL_PINS)
        return;

    uint8_t port = PIN_TO_PORT(pin);
    uint8_t bit = PIN_TO_BITMASK(pin);
    volatile uint8_t *reg = PORT_TO_MODE(port);

    if (mode == INPUT)
        SET_BIT_OFF(*reg, bit);
    else if (mode == OUTPUT)
        SET_BIT_ON(*reg, bit);
}

void digitalWrite(uint8_t pin, uint8_t state)
{
    if (pin >= NUM_DIGITAL_PINS)
        return;

    uint8_t port = PIN_TO_PORT(pin);
    uint8_t bit = PIN_TO_BITMASK(pin);
    volatile uint8_t *reg = PORT_TO_OUTPUT(port);

    SET_BIT(*reg, bit, state);
}
