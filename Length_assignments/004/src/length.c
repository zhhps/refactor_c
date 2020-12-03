#include "length.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

enum {
    SUPPORT_UNIT_F,
    SUPPORT_UNIT_INCH,
    SUPPORT_UNIT_YARD,
    SUPPORT_UNIT_NUM
};

static double f2inch(double value)
{
    return value * 12;
}

static double inch2f(double value)
{
    return value / 12;
}

static double f2yard(double value)
{
    return value / 3;
}

static double yard2f(double value)
{
    return value * 3;
}

static double inch2yard(double value)
{
    return value / 36;
}

static double yard2inch(double value)
{
    return value * 36;
}

static double convertUnit(int srcIndex, int dstIndex, double value)
{
    double (*ops[SUPPORT_UNIT_NUM][SUPPORT_UNIT_NUM])(double) = {
        {  NULL,    f2inch,    f2yard},
        {inch2f,      NULL, inch2yard},
        {yard2f, yard2inch,      NULL}
    };
    return ops[srcIndex][dstIndex](value);
}

static bool isUnitsConvertible(int index1, int index2)
{
    return index1 >= 0 && index1 < SUPPORT_UNIT_NUM &&
           index2 >= 0 && index2 < SUPPORT_UNIT_NUM &&
           index1 != index2;
}

static int getUnitIndex(const char *unit)
{
    char *unitStrs[SUPPORT_UNIT_NUM] = {
        [SUPPORT_UNIT_F] = "f",
        [SUPPORT_UNIT_INCH] = "inch",
        [SUPPORT_UNIT_YARD] = "yard"
    };
    for (int i = 0; i < SUPPORT_UNIT_NUM; i++) {
        if (strcmp(unitStrs[i], unit) == 0) {
            return i;
        }
    }
    return SUPPORT_UNIT_NUM;
}

LengthPtr newLength(double val, const char *uinnt)
{
    LengthPtr length = (LengthPtr)malloc(sizeof(Length));
    if (length == NULL) {
        return NULL;
    }
    length->val = val;
    length->uinnt = uinnt;
    return length;
}

LengthPtr as(LengthPtr obj, const char *u) {
    if (obj == NULL) {
        return NULL;
    }
    int srcIndex = getUnitIndex(obj->uinnt);
    int dstIndex = getUnitIndex(u);
    if (!isUnitsConvertible(srcIndex, dstIndex)) {
        return obj;
    }
    double newValue = convertUnit(srcIndex, dstIndex, obj->val);
    return newLength(newValue, u);
}

