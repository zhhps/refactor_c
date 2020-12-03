#ifndef REFACTOR_LENGTH_C_LENGTH_H
#define REFACTOR_LENGTH_C_LENGTH_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LengthStru{
    double val;
    const char *uinnt;
    struct LengthStru *(*toFoot)(struct LengthStru *length, const char *uinnt);
    struct LengthStru *(*toInch)(struct LengthStru *length, const char *uinnt);
    struct LengthStru *(*toYard)(struct LengthStru *length, const char *uinnt);
} Length;

typedef Length *LengthPtr;

LengthPtr newLength(double val, const char *uinnt);

LengthPtr as(LengthPtr obj, const char *u);

#ifdef __cplusplus
}
#endif
#endif //REFACTOR_LENGTH_C_LENGTH_H
