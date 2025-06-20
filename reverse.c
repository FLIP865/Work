#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100 // max line string

void reverse(char *str);
bool isStr(const char *str);

int main()
{
    char str[MAX_LENGTH];

    printf("Enter string (to %d symbols): ", MAX_LENGTH);
    if (fgets(str, MAX_LENGTH, stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';

        if (isStr(str)) {
            printf("String valid: %s\n", str);
            reverse(str);
            printf("Reversed string: %s\n", str);
        } else {
            printf("String not valid: %s\n", str);
        }
    } else {
        printf("Invalid input.\n");
    }
    return 0;
}

bool isStr(const char *str)
{
    if (str == NULL || str[0] == '\0') {
        return false;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))) {
            return false;
        }
    }
    return true;
}
void reverse(char *str)
{
    if (str == NULL) return;
    int n = strlen(str);
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
