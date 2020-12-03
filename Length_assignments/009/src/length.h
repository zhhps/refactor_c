#ifndef REFACTOR_LENGTH_C_LENGTH_H
#define REFACTOR_LENGTH_C_LENGTH_H

enum Unit{
    Inch,
    Foot,
    Yard
};

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    double val;
    enum Unit unit;

} Length;

typedef Length *LengthPtr;

LengthPtr newLength(double val, enum Unit unit);

LengthPtr lengthConvert(LengthPtr obj, enum Unit targetUnit);

#ifdef __cplusplus
}
#endif
#endif //REFACTOR_LENGTH_C_LENGTH_H
