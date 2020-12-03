#include "length.h"
#include <stdlib.h>

#define INCH_PER_FOOT 12
#define FOOT_PER_YARD 3
#define INCH_PER_YARD (INCH_PER_FOOT * FOOT_PER_YARD)

typedef LengthPtr (*SingleAsFunc)(LengthPtr obj, UintType uint);

LengthPtr NewLength(double val, UintType uint) {
    LengthPtr length = (LengthPtr) malloc(sizeof(Length));

    length->val = val;
    length->uint = uint;
    return length;
}

LengthPtr InchAs(LengthPtr obj, UintType uint) {
    double val = (uint == FOOT) ? (obj->val / INCH_PER_FOOT) : (obj->val / INCH_PER_YARD);
    return  NewLength(val, uint);
}

LengthPtr FootAs(LengthPtr obj, UintType uint) {
    double val = (uint == INCH) ? (obj->val * INCH_PER_FOOT) : (obj->val / FOOT_PER_YARD);
    return  NewLength(val, uint);
}

LengthPtr YardAs(LengthPtr obj, UintType uint) {
    double val = (uint == INCH) ? (obj->val * INCH_PER_YARD) : (obj->val * FOOT_PER_YARD);
    return  NewLength(val, uint);
}

SingleAsFunc g_procFuncList[] = {InchAs, FootAs, YardAs};

LengthPtr As(LengthPtr obj, UintType uint) {
    if (obj->uint == uint) {
        return obj;
    }

    return g_procFuncList[obj->uint](obj, uint);
}

