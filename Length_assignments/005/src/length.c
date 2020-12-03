#include "length.h"
#include <stdlib.h>

LengthPtr as(LengthPtr object, enum Unit tempUnit);

LengthPtr newLength(double value, enum Unit unit){
    LengthPtr length = (LengthPtr) malloc(sizeof(Length));
    length->value = value;
    length->tempUnit = unit;
    return length;
}

LengthPtr as(LengthPtr object, enum Unit tempUnit)
{
    LengthPtr length = object;
    if (object->tempUnit == Foot && tempUnit == Inch) {
        length = newLength(object->value * 12, tempUnit);
    }
    if (object->tempUnit == Inch && tempUnit == Foot) {
        length = newLength(object->value / 12, tempUnit);
    }

    if (object->tempUnit == Yard && tempUnit == Inch) {
        length = newLength(object->value * 36, tempUnit);
    }

    if (object->tempUnit == Yard && tempUnit == Foot) {
        length = newLength(object->value * 3, tempUnit);
    }

    if (tempUnit == Yard && object->tempUnit == Foot) {
        length = newLength(object->value / 3, tempUnit);
    }

    if (tempUnit == Yard && object->tempUnit == Inch) {
        length = newLength(object->value / 36, tempUnit);
    }
    return length;
}

