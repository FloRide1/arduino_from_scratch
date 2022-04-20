#ifndef CONSTANT
#define CONSTANT

// Macro
#define IS_TRUE(x) ((x) == true)
#define IS_FALSE(x) ((x) == false)

#define IS_NULL(x) ((x) == NULL)
#define NOT_NULL(x) ((x) != NULL)

#define COMPARE(x, y) (((x) > (y)) - ((x) < (y)))
#define IS_EQUAL(x, y) (COMPARE(x, y) == 0)
#define IS_BIGGER(x, y) (COMPARE(x, y) == 1)
#define IS_LESSER(x, y) (COMPARE(x, y) == -1)

#define SIGN(x) COMPARE(x, 0)
#define IS_POS(x) (SIGN(x) == 1)
#define IS_NEG(x) (SIGN(x) == -1)
#define IS_ZERO(x) (SIGN(x) == 0)

#define ABS(x) (IS_NEG(x) ? -(x) : (x))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

// Bitwise register operation

// Actually avr-libc provide _BV(x)
#define MAN_BIT(x) (1 << (x))

#define GET_BIT(var, bit) ((var) & (bit))
#define GET_BIT_P(var, pos) (GET_BIT(var, MAN_BIT(pos))

#define PUT_BIT_ON(var, bit) ((var) | (bit))
#define PUT_BIT_OFF(var, bit) ((var) & ~(bit))
#define PUT_BIT_INV(var, bit) ((var) ^ (bit))
#define PUT_BIT(var, bit, state) \
    ((state) ? PUT_BIT_ON((var), (bit)) : PUT_BIT_OFF((var), (bit)))

#define PUT_BIT_P_ON(var, pos) (PUT_BIT_ON((var), MAN_BIT(pos)))
#define PUT_BIT_P_OFF(var, pos) (PUT_BIT_OFF((var), MAN_BIT(pos)))
#define PUT_BIT_P_INV(var, pos) (PUT_BIT_INV((var), MAN_BIT(pos)))
#define PUT_BIT_P(var, pos, state) (PUT_BIT((var), MAN_BIT(pos), (state)))

#define SET_BIT_ON(var, bit) ((var) = PUT_BIT_ON((var), (bit)))
#define SET_BIT_OFF(var, bit) ((var) = PUT_BIT_OFF((var), (bit)))
#define SET_BIT_INV(var, bit) ((var) = PUT_BIT_INV((var), (bit)))
#define SET_BIT(var, bit, state) \
    ((state) ? SET_BIT_ON((var), (bit)) : SET_BIT_OFF((var), (bit)))

#define SET_BIT_P_ON(var, pos) (SET_BIT_ON((var), MAN_BIT(pos)))
#define SET_BIT_P_OFF(var, pos) (SET_BIT_OFF((var), MAN_BIT(pos)))
#define SET_BIT_P_INV(var, pos) (SET_BIT_INV((var), MAN_BIT(pos)))
#define SET_BIT_P(var, pos, state) (SET_BIT((var), MAN_BIT(pos), (state)))

#endif
