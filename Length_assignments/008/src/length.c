#include "length.h"
#include <string.h>
#include <stdlib.h>

LengthPtr newLength(double value, enum Unit unit) {
    LengthPtr length = (LengthPtr) malloc(sizeof(Length));

    length->val = value;
    length->unit = unit;
    return length;
}

LengthPtr as(LengthPtr obj, enum Unit tempUnit)
{
    LengthPtr length = obj;
    if (obj->unit == Foot && tempUnit == Inch) {
        length = newLength(obj->val * 12, tempUnit);
    }

    if (obj->unit == Inch && tempUnit == Foot) {
        length = newLength(obj->val / 12, tempUnit);
    }

    if (obj->unit == Yard && tempUnit == Inch) {
        length = newLength(obj->val * 36, tempUnit);
    }

    if (obj->unit == Yard && tempUnit == Foot) {
        length = newLength(obj->val * 3, tempUnit);
    }

    if (tempUnit == Yard && obj->unit == Foot) {
        length = newLength(obj->val / 3, tempUnit);
    }

    if (tempUnit == Yard && obj->unit == Inch) {
        length = newLength(obj->val / 36, tempUnit);
    }

    return length;
}

