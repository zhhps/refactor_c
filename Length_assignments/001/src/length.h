#ifndef REFACTOR_LENGTH_C_LENGTH_H
#define REFACTOR_LENGTH_C_LENGTH_H


#ifdef __cplusplus
extern "C" {
#endif

typedef enum{
    Yard,
    Foot,
    Inch
} Unit;

typedef struct {
    double value;
    Unit unit;
} Length;

typedef Length *LengthPtr;

LengthPtr NewLength(double value, Unit unit);

LengthPtr As(LengthPtr rawLength, Unit targetUnit);
#ifdef __cplusplus
}
#endif
#endif //REFACTOR_LENGTH_C_LENGTH_H
