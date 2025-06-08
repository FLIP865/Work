#include <stdio.h>
#include <stdlib.h>

int countPartitions(int n);

int main()
{
    int n = 50;
    int result = countPartitions(n);
    if (result >= 0) {
        printf("The number of possible decompositions of the number %d into terms: %d\n", n, result);
    }
    return 0;
}

int countPartitions(int n)
{
    int *dp = (int *)malloc((n + 1) * sizeof(int));
    if (dp == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        abort();
    }
    // Initializing an array
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;

    // Basic algorithm for calculating partitions 
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dp[j] += dp[j - i];
        }
    }
    int result = dp[n];
    free(dp);
    return result;
}
