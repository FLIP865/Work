#include <stdio.h>
#include <stdlib.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
    int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    char *ptr = &daytab[leap][1];
    int result = day;

    if (month < 1 || month > 12 || day < 1 || day > *(ptr + month - 1)) {
        return 1;
    }

    for (int i = 1; i < month; i++)
    {
        result += *ptr;
        ptr++;
    }
    return result;
}

int month_day(int year, int yerday, int *pmonth, int *pday)
{
    int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    char *ptr = &daytab[leap][1];
    int month = 1;
    int max_days = leap ? 366 : 365;

    if (yerday < 1 || yerday > max_days) {
        return 1;
    }

    while (yerday > *ptr) {
        yerday -= *ptr;
        month++;
        ptr++;
    }
    *pmonth = month;
    *pday = yerday;
    return yerday;
}

int main()
{
    int year, month, day, yearday;

    printf("Enter year, month and day (example 2025 4 15): ");
    if (scanf("%d %d %d", &year, &month, &day) != 3) {
        fprintf(stderr, "Inalid input!\n");
        abort();
    }
    yearday = day_of_year(year, month, day);
    printf("Day of year: %d\n", yearday);

    printf("\nEnter year and day year (example 2025 105): ");
    if (scanf("%d %d", &year, &yearday) != 2) {
        fprintf(stderr, "Error: Inalid input!\n");
        abort();
    }

    int new_month, new_day;
    int result = month_day(year, yearday, &new_month, &new_day);
    printf("Month %d, Day: %d\n", new_month, new_day);
    return 0;
}
