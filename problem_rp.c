#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <fenv.h>

typedef union {
    float f;
    uint32_t u;
} FloatUnion;

int main()
{
    fesetround(FE_DOWNWARD);

    int numeration, demuniration;
    printf("Enter number: ");
    if (scanf("%d %d", &numeration, &demuniration) != 2) {
        fprintf(stderr, "Erorr: Wrong input!\n");
        abort();
    }
    
    if (demuniration == 0) {
        fprintf(stderr, "Error: Division by zero!\n");
        abort();
    }

    double x = (double)numeration / (double)demuniration;
    if (!isfinite(x)) {
        fprintf(stderr, "Error: Result not finite (int or NaN)!\n");
        abort();
    }

    if (fabs(x) > 3.4e38) {
        fprintf(stderr, "Error: Result exceeds float range!\n");
        abort();
    }

    if (x == 0.0) {
        printf("0x0 0x0\n");
        return 0;
    }

    float f_lower, f_uper;
    if ((float)x == x) {
        f_lower = f_uper = (float)x;
    } else {
        if (x > 0.0) {
            f_lower = nextafterf((float)x, -INFINITY);
            f_uper = nextafterf((float)x, INFINITY);
        } else {
            f_lower = nextafterf((float)x, INFINITY);
            f_uper = nextafterf((float)x, -INFINITY);
        }
    }
    FloatUnion val;
    val.f = f_lower;
    uint32_t exp_lower = (val.u >> 23) & 0xFF;
    uint32_t mantissa_lower = val.u & 0x7FFFFF;

    val.f = f_uper;
    uint32_t exp_uper = (val.u >> 23) & 0xFF;
    uint32_t mantissa_uper = val.u & 0x7FFFFF;

    if (f_lower == f_uper) {
        printf("0x%x 0x%x\n", exp_lower, mantissa_lower);
    } else {
        printf("0x%x 0x%x 0x%x 0x%x\n", exp_lower, mantissa_lower, exp_uper, mantissa_uper);
    }
    return 0;
}
