#include <stdio.h>

char *my_strncpy(char *t, const char *s, unsigned long n);
int my_strncmp(const char *s1, const char *s2, unsigned long n);
char *my_strncat(char *t, const char *s, unsigned long n);

int main()
{
    char str1[100] = "Hello";
    char str2[] = "World";
    char coppy[100];

    my_strncpy(coppy, str2, 3);
    printf("my_strncpy result = %s\n", coppy);

    my_strncat(str1, str2, 3);
    printf("my_strncat result = %s\n", str1);

    int cmp = my_strncmp("abcde", "abcfz", 3);
    printf("my_strncmp result (first 3 chars) = %d\n", cmp);

    return 0;
}

char *my_strncpy(char *t, const char *s, unsigned long n)
{
    unsigned long i = 0;
    while (i < n && s[i] != '\0') {
        t[i] = s[i];
        i++;
    }

    while (i < n) {
        t[i++] = '\0';
    }
    return t;
}

int my_strncmp(const char *s1, const char *s2, unsigned long n)
{
    for (unsigned long i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            return s1[i] - s2[i];
        }
        if (s1[i] == '\0') {
            return 0;
        }
    }
    return 0;
}

char *my_strncat(char *t, const char *s, unsigned long n)
{
    unsigned long i = 0, j = 0;
    while (t[i] != '\0') {
        i++;
    }
    
    while (j < n && s[j] != '\0') {
        t[i++] = s[j++];
    }
    t[i] = '\0';
    return t;
}

