#include <stdio.h>

#define GRID_SIZE 21

int main()
{
    long long dp[GRID_SIZE][GRID_SIZE] = {0};

    dp[0][0] = 1;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
            if (i == 0 && j == 0) dp[0][0] = 1;
        }
    }
    printf("%lld\n", dp[GRID_SIZE - 1][GRID_SIZE - 1]);
    return 0;
}
