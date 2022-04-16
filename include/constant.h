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
#define GET_BIT(var, pos) ((var) & (1 << (pos)))

#define PUT_BIT_ON(var, pos) ((var) | (1 << (pos)))
#define PUT_BIT_OFF(var, pos) ((var) & ~(1 << (pos)))
#define PUT_BIT_INV(var, pos) ((var) ^ (1 << (pos)))
#define PUT_BIT(var, pos, state)                                               \
    ((state) ? PUT_BIT_ON((var), (pos)) : PUT_BIT_OFF((var), (pos)))

#define SET_BIT_ON(var, pos) ((var) = PUT_BIT_ON((var), (pos)))
#define SET_BIT_OFF(var, pos) ((var) = PUT_BIT_OFF((var), (pos)))
#define SET_BIT_INV(var, pos) ((var) = PUT_BIT_INV((var), (pos)))
#define SET_BIT(var, pos, state)                                               \
    ((state) ? SET_BIT_ON((var), (pos)) : SET_BIT_OFF((var), (pos)))

#endif
