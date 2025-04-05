#include <stdio.h>
#include <assert.h>

int majority_element(const int * parr, unsigned len);
void run_test(const int *arr, unsigned len, int expected, const char *test_name);

int main()
{
    int test1[] = {3, 2, 9, 2, 2};

    int x = majority_element(test1, 5);

    printf("Result = %d\n", x);

    run_test(test1, 5, 2, "Test 1: есть большинство");

    return 0;
}

void run_test(const int *arr, unsigned len, int expected, const char *test_name)
{
    int result = majority_element(arr, len);
    if (result == expected)
    {
        printf("[ %s ] PASSED\n", test_name);
    }
    else
    {
        printf("[ %s ] FAILED (Ожидал %d, получили %d)\n", test_name, expected, result);
    }
}

int majority_element(const int * parr, unsigned len)
{
    int candidate;
    int count = 0;
    for (unsigned i = 0; i < len; i++)
    {
        if (count == 0) {
            candidate = parr[i];
            count = 1;
        } else if (parr[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    count = 0;
    for (unsigned i = 0; i < len; i++)
    {
        if (parr[i] == candidate) {
            count++;
        }
    }

    if (count > len / 2) {
        return candidate;
    } else {
        return -1;
    }
}

