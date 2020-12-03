#include "length.h"
#include <string.h>
#include <stdlib.h>

// 单位换算关系
#define INCH_PER_FOOT 12
#define FOOT_PER_YARD 3
#define INCH_PER_YARD (INCH_PER_FOOT * FOOT_PER_YARD)

Length *newLength(double val, const char *uint)
{
    Length *length = (Length *) malloc(sizeof(Length));

    length->val = val;
    length->uint = uint;
    return length;
}

static inline int isFoot(const char *uint)
{
    return (strcmp(uint, FOOT) == 0);
}

static inline int isYard(const char *uint)
{
    return (strcmp(uint, YARD) == 0);
}

static inline int isInch(const char *uint)
{
    return (strcmp(uint, INCH) == 0);
}

// foot转换为其他单位
Length *FootAs(Length *src, const char *target)
{
    if (isInch(target)) {
        return newLength(src->val * INCH_PER_FOOT, target);
    } else if (isYard(target)) {
        return newLength(src->val / FOOT_PER_YARD, target);
    }
    return src;
}

// yard转换为其他单位
Length *YardAs(Length *src, const char *target)
{
    if (isInch(target)) {
        return newLength(src->val * INCH_PER_YARD, target);
    } else if (isFoot(target)) {
        return newLength(src->val * FOOT_PER_YARD, target);
    }
    return src;
}

// inch转换为其他单位
Length *InchAs(Length *src, const char *target)
{
    if (isFoot(target)) {
        return newLength(src->val / INCH_PER_FOOT, target);
    } else if (isYard(target)) {
        return newLength(src->val / INCH_PER_YARD, target);
    }
    return src;
}

Length *as(Length *src, const char *target)
{
    if (isFoot(src->uint)) {
        return FootAs(src, target);
    } else if (isYard(src->uint)) {
        return YardAs(src, target);
    } else if (isInch(src->uint)) {
        return InchAs(src, target);
    }
    return src;
}

