#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

void print_str(char *str);
void reverse(char *str, int len);
int read_str(char **str, int *len);
int read_text(char **str);

int main()
{
    int len1, len2;
    char *str1 = NULL, *str2 = NULL;
    int res = 0;

    res = read_str(&str2, &len2);
    if (res != 1)
        return 1;

    res = read_text(&str1);

    if (res != 1) {
        free(str2);
        return -1;
    }

    len1 = strlen(str1);
    if (str1[len1 - 1] == '\n') {
        str1[len1 - 1] = '\0';
        len1--;
    }

    regex_t regex;
    int reti = regcomp(&regex, str2, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Error: Could not compile regex\n");
        free(str1);
        free(str2);
        return -1;
    }

    regmatch_t match;
    char *current = str1;

    while (regexec(&regex, current, 1, &match, 0) == 0) {
        int start = match.rm_so + (current - str1);
        int end = match.rm_eo + (current - str1);
        int match_len = end - start;

        reverse(str1 + start, match_len);

        current += match.rm_eo;
    }

    regfree(&regex);

    print_str(str1);

    free(str1);
    free(str2);

    return 0;
}

void print_str(char *str)
{
    printf("%s\n", str);
}

void reverse(char *str, int len)
{
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int read_str(char **str, int *len)
{
    if (scanf("%d", len) != 1) {
        fprintf(stderr, "Error: Invalid input!\n");
        return -1;
    }

    while (getchar() != '\n');

    *str = (char *)calloc(*len + 1, sizeof(char));
    if (str == NULL) {
        fprintf(stderr, "Error: Memory allocation failed!\n");
        abort();
    }

    if (scanf("%s", *str) != 1) {
        fprintf(stderr, "Error: Invalid input!\n");
        free(*str);
        return -1;
    }

    if (strlen(*str) != *len) {
        fprintf(stderr, "Error: Word length does not match\n");
        free(*str);
        return 0;
    }
    return 1;
}

int read_text(char **str)
{
    char buffer[1024];

    while (getchar() != '\n');

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        fprintf(stderr, "Error: Invalid input!\n");
        return -1;
    }

    *str = (char *)malloc(strlen(buffer) + 1);
    if (*str == NULL) {
        fprintf(stderr, "Error: Memory allocation failed!\n");
        abort();
    }

    strcpy(*str, buffer);
    return 1;
}

