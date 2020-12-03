#include "length.h"
#include <string.h>
#include <stdlib.h>



LengthPtr NewLength(double value, Unit unit)
{
    LengthPtr length = (LengthPtr) malloc(sizeof(Length));

    length->value = value;
    length->unit = unit;
    return length;
}

LengthPtr As(LengthPtr rawLength, Unit targetUnit)
{
    LengthPtr length = rawLength;

    if (Foot == rawLength->unit && Inch == targetUnit) {
        length = NewLength(rawLength->value * 12, targetUnit);
    }

    if (Inch == rawLength->unit && Foot == targetUnit) {
        length = NewLength(rawLength->value / 12, targetUnit);
    }


    if (Yard == rawLength->unit && Inch == targetUnit) {
        length = NewLength(rawLength->value * 36, targetUnit);
    }

    if (Yard == rawLength->unit && Foot == targetUnit) {
        length = NewLength(rawLength->value * 3, targetUnit);
    }

    if (Foot == rawLength->unit && Yard == targetUnit) {
        length = NewLength(rawLength->value / 3, targetUnit);
    }

    if (Inch == rawLength->unit && Yard == targetUnit) {
        length = NewLength(rawLength->value / 36, targetUnit);
    }

    return length;
}

