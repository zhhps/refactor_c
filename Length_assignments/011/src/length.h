#ifndef REFACTOR_LENGTH_C_LENGTH_H
#define REFACTOR_LENGTH_C_LENGTH_H

#ifdef __cplusplus
extern "C" {
#endif


#define INCH "inch" // 英寸
#define FOOT "foot" // 英尺，1英尺=12英寸
#define YARD "yard" // 码，1码=36英寸

typedef struct {
    double val;
    const char *uint;
} Length;


Length *newLength(double val, const char *uint);

Length *as(Length *src, const char *target);

#ifdef __cplusplus
}
#endif
#endif //REFACTOR_LENGTH_C_LENGTH_H
