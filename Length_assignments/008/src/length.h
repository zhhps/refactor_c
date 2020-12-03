#ifndef REFACTOR_LENGTH_C_LENGTH_H
#define REFACTOR_LENGTH_C_LENGTH_H

#ifdef __cplusplus
extern "C" {
#endif

enum Unit{
    Foot, Yard, Inch
};

typedef struct {
    double val;
    enum Unit unit;
} Length;

typedef Length *LengthPtr;

LengthPtr newLength(double value, enum Unit unit);

LengthPtr as(LengthPtr obj, enum Unit tempUnit);


#ifdef __cplusplus
}
#endif
#endif //REFACTOR_LENGTH_C_LENGTH_H
