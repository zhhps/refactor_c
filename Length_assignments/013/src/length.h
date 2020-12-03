#ifndef REFACTOR_LENGTH_C_LENGTH_H
#define REFACTOR_LENGTH_C_LENGTH_H


#ifdef __cplusplus
extern "C" {
#endif
static const char * FOOT = "f";
static const char * INCH = "inch";
static const char * YARD = "yard";

enum UNIT{
    Foot,
    Inch,
    Yard,
    UnitUnkown
};

typedef struct {
    double val;
    enum UNIT unit;
} Length;

typedef struct {
    enum UNIT src;
    enum UNIT dst;
    double factor;
}TransItem;

typedef Length *LengthPtr;

LengthPtr newLength(double val, enum UNIT targetUnit);

LengthPtr as(LengthPtr org, enum UNIT targetUnit);
#ifdef __cplusplus
}
#endif
#endif //REFACTOR_LENGTH_C_LENGTH_H
