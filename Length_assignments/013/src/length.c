#include "length.h"
#include <string.h>
#include <stdlib.h>

static TransItem g_TransItems[] = {
        {Foot, Inch, 12},
        {Inch, Foot, 1.0 / 12},
        {Yard, Foot, 3},
        {Foot, Yard, 1.0 / 3},
        {Yard, Inch, 36},
        {Inch, Yard, 1.0 / 36}
};

Length *newLength(double val, enum UNIT unit) {
    LengthPtr length = (LengthPtr) malloc(sizeof(Length));
    length->val = val;
    length->unit = unit;
    return length;
}

enum UNIT transStrToUnit(const char *targetUnit) {
    if (strcmp(targetUnit, FOOT) == 0) {
        return Foot;
    }
    if (strcmp(targetUnit, INCH) == 0) {
        return Inch;
    }
    if (strcmp(targetUnit, YARD) == 0) {
        return Yard;
    }
}

double transByUnit(double val, enum UNIT src, enum UNIT dst) {
    int len = sizeof(g_TransItems) / sizeof(TransItem);
    for (int i = 0; i < len; ++i) {
        TransItem *transItem = &g_TransItems[i];
        if (transItem->src == src && transItem->dst == dst) {
            return val * transItem->factor;
        }
    }
    return val;
}

LengthPtr as(LengthPtr org, enum UNIT targetUnit) {
    double newVal = transByUnit(org->val, org->unit, targetUnit);
    return newLength(newVal, targetUnit);
}


