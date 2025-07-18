#include <iostream>
#include <vector>

int countPartitions(int n) {
    std::vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dp[j] += dp[j - i];
        }
    }
    return dp[n];
}

int main() {
    int n = 50;
    std::cout << "The number of possible decompositions of the number " << n << " into terms: " <<  countPartitions(n) << std::endl;
    return 0;
}
