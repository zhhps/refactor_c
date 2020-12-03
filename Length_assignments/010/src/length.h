#ifndef REFACTOR_LENGTH_C_LENGTH_H
#define REFACTOR_LENGTH_C_LENGTH_H

#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

enum Unit{
    Inch, Foot, Yard
};

typedef struct {
    double value;
    enum Unit unit;
} Length;

typedef Length *LengthPtr;

LengthPtr newLength(double value, enum Unit unit);

LengthPtr as(LengthPtr obj, enum Unit targetUnit);

#ifdef __cplusplus
}
#endif
#endif //REFACTOR_LENGTH_C_LENGTH_H
