#include <cstdio>
#include <stdexcept>

template<typename To, typename From>
To narrow_cast(From value) {
    const auto converted = static_cast<To>(value);
    const auto backwards = static_cast<From>(converted);
    if (value != backwards) {
        throw std::runtime_error{ "Narrowed!" };
    }
    return converted;
}

int main() {
    int perfect = 500;
    const auto perfect_short = narrow_cast<short>(perfect);
    printf("perfect_short %d\n", perfect_short);
    try {
        int cyclis = 142857;
        const auto cyclis_short = narrow_cast<short>(cyclis);
        printf("cyclis_short %d\n", cyclis_short);
    } catch (const std::runtime_error& e) {
        printf("Expection: %s\n", e.what());
    }
    return 0;
}
