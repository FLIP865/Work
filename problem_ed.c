#include <stdio.h>
#include <stdlib.h>

int edit_distance(char *str1, int len1, char *str2, int len,
                  int cost_insert, int cost_delete, int cost_replase);
int min(int a, int b, int c);

int main()
{
    int cost_insert, cost_delete, cost_replase;
    int len1, len2;
    char *str1, *str2;

    if (scanf("%d %d %d", &cost_insert, &cost_delete, &cost_replase) != 3) {
        fprintf(stderr, "Wrong Input!\n");
        abort();
    }

    if (scanf("%d", &len1) != 1) {
        fprintf(stderr, "Error: Wrong Input!\n");
        abort();
    }

    // Memmory allocation
    str1 = (char *)malloc(len1 + 1);
    if (str1 == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        free(str1);
        abort();
    }
    if (scanf("%s", str1) != 1) {
        fprintf(stderr, "Wrong Input!\n");
        free(str1);
        abort();
    }

    if (scanf("%d", &len2) != 1) {
        fprintf(stderr, "Wrong Input!\n");
        free(str1);
        abort();
    }

    // Memory allocation
    str2 = (char *)malloc(len2 + 1);
    if (str2 == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        free(str1);
        free(str2);
        abort();
    }

    if (scanf("%s", str2) != 1) {
        fprintf(stderr, "Wrong Input!\n");
        free(str1);
        free(str2);
        abort();
    }

    int distance = edit_distance(str1, len1, str2, len2, cost_insert, cost_delete, cost_replase);
    printf("Result = %d\n", distance);

    free(str1);
    free(str2);

    return 0;
}

int min(int a, int b, int c)
{
    int min_ab = (a < b) ? a : b;
    return (min_ab < c) ? min_ab : c;
}

int edit_distance(char *str1, int len1, char *str2, int len2,
                  int cost_insert, int cost_delete, int cost_replase)
{
    int **dp = (int **)malloc((len1 + 1) * sizeof(int *));
    if (dp == NULL) {
        fprintf(stderr, "Error: Memory allocation failed!\n");
        free(dp);
        abort();
    }
    for (int i = 0; i <= len1; i++)
    {
        dp[i] = (int *)malloc((len2 + 1) * sizeof(int));
        if (dp[i] == NULL) {
            fprintf(stderr, "Error Memory allocation for dp[i] failed!\n");
            for (int j = 0; j < i; j++) free(dp[j]);
            free(dp);
            abort();
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= len1; i++) {
        dp[i][0] = dp[i - 1][0] + cost_delete;
    }
    for (int j = 1; j <= len2; j++) {
        dp[0][j] = dp[0][j - 1] + cost_insert;
    }
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int delete_cost = dp[i - 1][j] + cost_delete;
                int insert_cost = dp[i][j - 1] + cost_insert;
                int replace_cost = dp[i - 1][j - 1] + cost_replase;
                // take min
                dp[i][j] = min(delete_cost, insert_cost, replace_cost);
            }
        }
    }

    int result = dp[len1][len2];

    for (int i = 0; i <= len1; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}


