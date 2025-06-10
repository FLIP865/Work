#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define INITIAL_CAPACITY 6000

int compare(const void *x, const void *y);

int main()
{
    FILE *fp = fopen("names.txt", "r");
    char path[] = "names.txt";
    if (!fp) {
        perror(path);
        return 1;
    }

    char **names = malloc(INITIAL_CAPACITY * sizeof(char *));

    int count = 0;
    int capacity = INITIAL_CAPACITY;
    char buffer[MAX_NAME_LEN];

    while (fscanf(fp, "\"%[^\"]\",", buffer) == 1) {
        if (count >= capacity) {
            capacity *= 2;
            char **new_names = realloc(names, capacity * sizeof(char *));
            if (!new_names) {
                fclose(fp);
                perror("Memory reallocation failed");
                for (int i = 0; i < count; i++) free(names[i]);
                free(names);
                return 1;
            }
            names = new_names;
        }
        names[count] = malloc(strlen(buffer) + 1);
        if (!names[count]) {
            fclose(fp);
            perror("Memory allocation failed for name");
            for (int i = 0; i < count; i++) free(names[i]);
            free(names);
            return 1;
        }
        strcpy(names[count], buffer);
        count++;
    }
    fclose(fp);

    qsort(names, count, sizeof(char*), compare);

    long long sum = 0;
    for (int i = 0; i < count; i++) {
        int score = 0;
        for (int j = 0; names[i][j] != '\0'; j++) {
            if (names[i][j] >= 'A' && names[i][j] <= 'Z') {
                score += names[i][j] - 'A' + 1;
            }
        }
        sum += (long long)score * (i + 1);
    }

    for (int i = 0; i < count; i++) {
        free(names[i]);
    }
    free(names);

    printf("%lld\n", sum);

    return 0;
}

int compare(const void *x, const void *y)
{
    return strcmp(*(char * const *)x, *(char * const *)y);
}
