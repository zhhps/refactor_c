#ifndef REFACTOR_LENGTH_C_LENGTH_H
#define REFACTOR_LENGTH_C_LENGTH_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    INCH,
    FOOT,
    YARD,
} UintType;

typedef struct {
    double val;
    UintType uint;
} Length;

typedef Length *LengthPtr;

LengthPtr NewLength(double val, UintType uint);

LengthPtr As(LengthPtr obj, UintType uint);

#ifdef __cplusplus
}
#endif
#endif //REFACTOR_LENGTH_C_LENGTH_H
