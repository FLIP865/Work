int is_prime(unsigned x)
{
    if (x <= 1) return 0;
    if (x <= 3) return 1;
    if ((x % 2) == 0) return 0;
    for (unsigned i = 3; i * i <= x; i += 2) {
        if ((x % i) == 0) {
            return 0;
        }
    }
    return 1;
}
