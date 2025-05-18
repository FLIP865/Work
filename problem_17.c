#include <stdio.h>

const char *ones[] =  {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char *tens[] =  {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const char *hundred = "hundred";
const char *thousand = "thousand";
const char *and = "and";

int count_letters(const char *word);

int number_to_english(int n);

int main()
{
    int target = 1000;
    int answer = 0;

    for (int i = 1; i <= target; i++) {
        answer += number_to_english(i);
    }
    printf("%d\n", answer);
}

int count_letters(const char *word)
{
    int count = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] != ' ' && word[i] != '-') {
            count++;
        }
    }
    return count;
}

int number_to_english(int n)
{
    int letter_count = 0;

    if (n == 1000) {
        letter_count += count_letters(ones[1]);
        letter_count += count_letters(thousand);
        return letter_count;
    }

    if (n >= 100) {
        letter_count += count_letters(ones[n / 100]);
        letter_count += count_letters(hundred);
        if ((n % 100) != 0) {
            letter_count += count_letters(and);
        }
        n %= 100;
    }

    if (n >= 20) {
        letter_count += count_letters(tens[n / 10]);
        n %= 10;
    } 
    
    else if (n >= 10) {
        letter_count += count_letters(teens[n - 10]);
        return letter_count;
    }

    if (n > 0) {
        letter_count += count_letters(ones[n]);
    }

    return letter_count;
}
