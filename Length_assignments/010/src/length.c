#include "length.h"
#include <stdlib.h>


LengthPtr convertToInch(enum Unit unit, double value);
LengthPtr convertToFoot(enum Unit unit, double value);
LengthPtr convertToYard(enum Unit unit, double value);

LengthPtr newLength(double value, enum Unit unit)
{
    LengthPtr length = (LengthPtr) malloc(sizeof(Length));
    length->value = value;
    length->unit = unit;
    return length;
}

LengthPtr as(LengthPtr obj, enum Unit targetUnit)
{
    LengthPtr len = obj;
    if (obj->unit == targetUnit) {
        return  len;
    }
    if (targetUnit == Inch) {
        return convertToInch(obj->unit, obj->value);
    }else if (targetUnit == Foot){
        return convertToFoot(obj->unit, obj->value);
    }else {
        return convertToYard(obj->unit, obj->value);
    }
}

LengthPtr convertToInch(enum Unit unit, double value)
{
    LengthPtr len;
    if (unit == Foot) {
        len = newLength(value * 12, Inch);
    }else{
        len = newLength(value * 36, Inch);
    }
    return len;
}

LengthPtr convertToFoot(enum Unit unit, double value)
{
    LengthPtr len;
    if (unit == Inch) {
        len = newLength(value / 12, Foot);
    }else{
        len = newLength(value * 3, Foot);
    }
    return len;
}

LengthPtr convertToYard(enum Unit unit, double value)
{
    LengthPtr len;
    if (unit == Foot) {
        len = newLength(value / 3, Yard);
    }else{
        len = newLength(value / 36, Yard);
    }
    return len;
}
