#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef union {
    float f;
    uint32_t u;
} FloatUnion;

int main()
{
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
        printf("0x0 0x0 0x0 0x0!\n");
        return 0;
    }

    float f = (float)x;

    float f_lower, f_uper;
    if ((double)f == x) {
        f_lower = f;
        f_uper = f;
    } else if ((double)f > x) {
        f_lower = nextafterf(f, -INFINITY);
        f_uper = f;
    } else {
        f_lower = f;
        f_uper = nextafterf(f, INFINITY);
    }
    FloatUnion val;
    val.f = f_lower;
    uint32_t exp_lower = (val.u >> 23) & 0xFF;
    uint32_t mantissa_lower = val.u & 0x7FFFFF;

    val.f = f_uper;
    uint32_t exp_uper = (val.u >> 23) & 0xFF;
    uint32_t mantissa_uper = val.u & 0x7FFFFF;

    printf("0x%x 0x%x 0x%x 0x%x\n", exp_lower, mantissa_lower, exp_uper, mantissa_uper);
    return 0;
}
