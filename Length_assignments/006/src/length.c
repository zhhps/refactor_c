#include "length.h"
#include <string.h>
#include <stdlib.h>

Length *newLength(double value, const char *unit) {
    LengthPtr length = (LengthPtr) malloc(sizeof(Length));

    length->value = value;
    length->unit = unit;
    return length;
}
/*
 * 疑问1：obj->value使用较多，是否应该新定义1个变量value = obj->value
 * 疑问2：多个if连续判断，是否建议用if-else，或满足条件时直接return
 * 疑问3：常量是否需要修改成宏？ 或是单位进制等属于人人皆知，不需改成宏
 * 疑问4：strcmp(srcUnit, "feet") == 0，是否建议提炼成函数isString(char *srcUnit, char *unit)
 * 疑问5：isUnitAtoUnitB(char *srcUnit, char *unit)是否合适？
 */
LengthPtr unitTransfer(LengthPtr obj, const char *unit) {
    LengthPtr resultLen = obj;
    char *srcUnit = (char *)obj->unit;
    double value = obj->value;

    if ((strcmp(srcUnit, "feet") == 0) && (strcmp(unit, "inch") == 0)) {
        resultLen = newLength(value * 12, unit);
    }

    if ((strcmp(srcUnit, "inch") == 0) && (strcmp(unit, "feet") == 0)) {
        resultLen = newLength(value / 12, unit);
    }

    if ((strcmp(srcUnit, "yard") == 0) && (strcmp(unit, "inch") == 0)) {
        resultLen = newLength(value * 36, unit);
    }

    if ((strcmp(srcUnit, "yard") == 0) && (strcmp(unit, "feet") == 0)) {
        resultLen = newLength(value * 3, unit);
    }

    if ((strcmp(srcUnit, "feet") == 0) && (strcmp(unit, "yard") == 0)) {
        resultLen = newLength(value / 3, unit);
    }

    if ((strcmp(srcUnit, "inch") == 0) && (strcmp(unit, "yard") == 0)) {
        resultLen = newLength(value / 36, unit);
    }
    /* 其他场景：原单位转换，直接返回 */
    return resultLen;
}

