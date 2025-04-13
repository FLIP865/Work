#include <stdio.h>
#include <stdlib.h>

int knapsack(int n, int W, int *weights, int *values);
void read_sack(int n, int *weights, int *values);

int main()
{
    int n, W;

    if (scanf("%d %d", &n, &W) != 2) {
        fprintf(stderr, "Error: Failed to read n and W!\n");
        abort();
    }

    int *weights = (int *)malloc(n * sizeof(int));
    int *values = (int *)malloc(n * sizeof(int));
    if (weights == NULL || values == NULL) {
        fprintf(stderr, "Error: Memory allocation failed!\n");
        free(weights);
        free(values);
        abort();
    }

        read_sack(n, weights, values);
        int max_value = knapsack(n, W, weights, values);
        printf("Result = %d\n", max_value);

        free(weights);
        free(values);

        return 0;
}

void read_sack(int n, int *weights, int *values)
{
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &weights[i]) != 1) {
            fprintf(stderr, "Error: Failed to read weights!\n");
            abort();
        }
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &values[i]) != 1) {
            fprintf(stderr, "Error: Failed to read values!\n");
            abort();
        }
    }
}

int knapsack(int n, int W, int *weights, int *values)
{
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)calloc(W + 1, sizeof(int));
        if (dp[i] == NULL) {
            fprintf(stderr, "Error: Memory allocation failed!\n");
            for (int j = 0; j < i; j++) free(dp[j]);
            free(dp);
            abort();
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                int take = dp[i - 1][w - weights[i - 1]] + values[i - 1];
                dp[i][w] = (take > dp[i - 1][w]) ? take : dp[i - 1][w];
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int result = dp[n][W];

    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}
