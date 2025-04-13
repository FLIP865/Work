#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

const char *pattern = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";

int isValidEmail(const char *email)
{
    int reti;
    regex_t regex;
    regcomp(&regex, pattern, REG_EXTENDED);
    reti = regexec(&regex, email, 0, NULL, 0);

    if (!reti) {
        return 1;
    } else {
        return 0;
    }

    regfree(&regex);
}

int main()
{
    char email[100];
    scanf("%s", email);

    if (isValidEmail(email)) {
        printf("Match\n");
    } else {
        printf("Not Match!\n");
    }
    return 0;
}
