#include "length.h"
#include <string.h>
#include <stdlib.h>

Length *newLength(double val, const char *uinnt)
{
    LengthPtr length = (LengthPtr)malloc(sizeof(Length));

    length->val = val;
    length->uinnt = uinnt;
    return length;
}

typedef struct {
    const char *uinnt;
    const char *u;
    double multiply;
} tranShip;

LengthPtr as(LengthPtr obj, const char *u)
{
    LengthPtr len = obj;

    int i;
    tranShip ships[] = {
        {"f", "inch", 12},
        {"inch", "f", 1.0 / 12},
        {"yard", "inch", 36},
        {"yard", "f", 3},
        {"f", "yard", 1.0 / 3},
        {"inch", "yard", 1.0 / 36},
    };

    for (i = 0; i < sizeof(ships) / sizeof(ships[0]); i++) {
        if (strcmp(obj->uinnt, ships[i].uinnt) == 0 && strcmp(u, ships[i].u) == 0) {
            len = newLength(obj->val * ships[i].multiply, u);
            break;
        }
    }

    return len;
}
