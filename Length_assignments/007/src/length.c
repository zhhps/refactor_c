#include "length.h"
#include <string.h>
#include <stdlib.h>

typedef int BOOL;

static BOOL IsYard(const char *uinnt)
{
    return strcmp(uinnt, "yard") == 0;
}

static BOOL IsInch(const char *uinnt)
{
    return strcmp(uinnt, "inch") == 0;
}

static BOOL IsFoot(const char *uinnt)
{
    return strcmp(uinnt, "f") == 0;
}

static LengthPtr ToSelf(LengthPtr length, const char *uinnt)
{
    return newLength(length->val, uinnt);
}

static LengthPtr FootToInch(LengthPtr length, const char *uinnt)
{
    return newLength(length->val * 12, uinnt);
}

static LengthPtr FootToYard(LengthPtr length, const char *uinnt)
{
    return newLength(length->val / 3, uinnt);
}

static LengthPtr YardToInch(LengthPtr length, const char *uinnt)
{
    return newLength(length->val * 36, uinnt);
}

static LengthPtr YardToFoot(LengthPtr length, const char *uinnt)
{
    return newLength(length->val * 3, uinnt);
}

static LengthPtr InchToYard(LengthPtr length, const char *uinnt)
{
    return newLength(length->val / 36, uinnt);
}

static LengthPtr InchToFoot(LengthPtr length, const char *uinnt)
{
    return newLength(length->val / 12, uinnt);
}

LengthPtr newLength(double val, const char *uinnt)
{
    LengthPtr length = (LengthPtr)malloc(sizeof(Length));

    length->val = val;
    length->uinnt = uinnt;

    if (IsFoot(uinnt)) {
        length->toFoot = ToSelf;
        length->toInch = FootToInch;
        length->toYard = FootToYard;
    } else if (IsInch(uinnt)) {
        length->toFoot = InchToFoot;
        length->toInch = ToSelf;
        length->toYard = InchToYard;
    } else if (IsYard(uinnt)) {
        length->toFoot = YardToFoot;
        length->toInch = YardToInch;
        length->toYard = ToSelf;
    } else {
        return NULL;
    }

    return length;
}

LengthPtr as(LengthPtr obj, const char *uinnt)
{
    if (IsFoot(uinnt)) {
        return obj->toFoot(obj, uinnt);
    } else if (IsInch(uinnt)) {
        return obj->toInch(obj, uinnt);
    } else if (IsYard(uinnt)) {
        return obj->toYard(obj, uinnt);
    } else {
        return NULL;
    }
}