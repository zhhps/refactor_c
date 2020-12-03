#include "length.h"
#include <string.h>
#include <stdlib.h>

LengthPtr newLength(double val, enum Unit unit){
    LengthPtr length = (LengthPtr) malloc(sizeof(Length));
    length->val = val;
    length->unit = unit;
    return length;
}

LengthPtr lengthConvert(LengthPtr obj, enum Unit targetUnit) {
    LengthPtr res = obj;
    if (obj->unit == Foot && targetUnit == Inch) res = newLength(obj->val * 12, targetUnit);
    if (obj->unit == Yard && targetUnit == Inch) res = newLength(obj->val * 36, targetUnit);
    if (obj->unit == Inch && targetUnit == Foot) res = newLength(obj->val / 12, targetUnit);
    if (obj->unit == Yard && targetUnit == Foot) res = newLength(obj->val * 3, targetUnit);
    if (obj->unit == Foot && targetUnit == Yard) res = newLength(obj->val / 3, targetUnit);
    if (obj->unit == Inch && targetUnit == Yard) res = newLength(obj->val / 36, targetUnit);
    return res;
}
