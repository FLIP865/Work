#include <iostream>
#include <climits>
#include <cstdlib>

class Solution {
    public:
        int divide(int dividend, int divisor) {
            if (dividend == INT_MIN && divisor == -1) {
                return INT_MAX;
            }
            bool sign = (dividend < 0) ^ (divisor < 0);
            long long n = llabs(dividend);
            long long d = llabs(divisor);
            long long quotient = 0;

            while (n >= d) {
                int cnt = 0;
                while (n >= (d << (cnt + 1))) {
                    cnt++;
                }
                quotient += (1LL << cnt);
                n -= (d << cnt);
            }
            return sign ? -quotient : quotient;
        }
};

int main() {
    Solution solution;
    int dividend = 10;
    int divisor = 3;

    std::cout << "Result: " << solution.divide(dividend, divisor) << std::endl;

    return 0;
}
