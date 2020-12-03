#ifndef REFACTOR_LENGTH_C_LENGTH_H
#define REFACTOR_LENGTH_C_LENGTH_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    double value;
    const char *unit;
} Length;

typedef Length *LengthPtr;

LengthPtr newLength(double value, const char *unit);

LengthPtr unitTransfer(LengthPtr obj, const char *unit);

#ifdef __cplusplus
}
#endif
#endif //REFACTOR_LENGTH_C_LENGTH_H
