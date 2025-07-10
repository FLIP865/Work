#include <stdio.h>

#define M 1000

int find_cycle_length(long long d);

int main()
{
    long long max_d = 0;
    long long max_length = 0;

    for (long long d = 2; d < M; d++) {
        long long length = find_cycle_length(d);
        if (length > max_length) {
            max_length = length;
            max_d = d;
        }
    }

    printf("%lld\n", max_d);

    return 0;
}

int find_cycle_length(long long d)
{
    if (d <= 1) return 0;

    if ((d % 2) == 0 || ((d % 5) == 0)) return 0;

    long long seen[1000] = {0};
    long long remainders = 1;
    long long position = 0;

    while (remainders != 0) {
        remainders = (remainders * 10) % d;
        position++;

        if (seen[remainders] != 0) {
            return position - seen[remainders];
        }

        seen[remainders] = position;

        if (remainders == 1) {
            return position;
        }
    }
    return 0;
}
