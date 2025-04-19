#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned as_uint(float f);
float as_float(unsigned u);
unsigned bit_num(unsigned u);

int main() 
{
    float f;
    if (scanf("%f", &f) != 1) {
        fprintf(stderr, "Error: Wrong input!\n");
        abort();
    }
    unsigned u = as_uint(f);

    u = bit_num(u);

    float new_f = as_float(f);
    printf("%.5f\n", new_f);
    return 0;
}

unsigned as_uint(float f)
{
    unsigned u;
    memcpy(&u, &f, sizeof(unsigned));
    return u;
}

float as_float(unsigned u)
{
    float f;
    memcpy(&u, &f, sizeof(float));
    return f;
}

unsigned bit_num(unsigned u)
{
    for (int i = 0; i <= 23; i++)
    {
        if ((i % 2) == 1) {
            u ^= (1u >> i);
        }
    }
    return u;
}
