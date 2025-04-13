#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char *read_word(int *len);
char *read_string(int *len);
char *replace(char *str, char const *from, char const *to);

int main()
{
    int nword, nrepl, nstr;
    char *word, *repl, *str;
    char *result;

    if (scanf("%d", &nword) != 1) {
        fprintf(stderr, "Error: Failed to read length for str!\n");
        return 1;
    }

    word = read_word(&nword);
    if (word == NULL) {
        return 1;
    }

    if (scanf("%d", &nrepl) != 1) {
        fprintf(stderr, "Error!!!!!!\n");
        free(word);
        return 1;
    }

    repl = read_word(&nrepl);
    if (repl == NULL) {
        free(word);
        return 1;
    }

    if (scanf("%d", &nstr) != 1) {
        fprintf(stderr, "ERROR!!!!!\n");
        free(word);
        free(repl);
        return 1;
    }

    str = read_string(&nstr);
    if (str == NULL) {
        free(word);
        free(repl);
        return 1;
    }

    printf("Replacing in: <%s>\n", str);
    printf("Text to find: <%s>\n", word);
    printf("Text to replace: <%s>\n", repl);

    result = replace(str, word, repl);
    if (result == NULL) {
        free(word);
        free(repl);
        free(str);
        return 1;
    }

    printf("Result is <%s>\n", result);

    free(word);
    free(repl);
    free(str);
    free(result);

    return 0;
}

char *read_string(int *len)
{
    char buffer[1024];
    int c;

    while ((c = getchar()) != '\n' && c != EOF);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        fprintf(stderr, "Error: Failed to read string\n");
        return NULL;
    }

    int buffer_len = strlen(buffer);
    if (buffer[buffer_len - 1] == '\n') {
        buffer[buffer_len - 1] = '\0';
        buffer_len--;
    }
    
    if (buffer_len != *len) {
        fprintf(stderr, "Error: String length does not match\n");
        return NULL;
    }

    char *text = (char *)malloc(buffer_len + 1);
    if (text == NULL) {
        fprintf(stderr, "Error: Memory allocation failed!\n");
        return NULL;;
    }
    strcpy(text, buffer);
    return text;
}
char *read_word(int *len)
{
    char buffer[1024];
    int c;

    while ((c = getchar()) != '\n' && c != EOF);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        fprintf(stderr, "Error: Failed to read word!\n");
        return NULL;
    }

    int buffer_len = strlen(buffer);
    if (buffer[buffer_len - 1] == '\n') {
        buffer[buffer_len - 1] = '\0';
        buffer_len--;
    }
    
    if (buffer_len != *len) {
        fprintf(stderr, "Error: Word length does not match!\n");
        return NULL;
    }

    char *text = (char *)calloc(*len + 1, sizeof(char));
    if (text == NULL) {
        fprintf(stderr, "Error: Memory allocation failed!\n");
        return NULL;;
    }
    strcpy(text, buffer);

    return text;
}

char *replace(char *str, char const *from, char const *to)
{
    int str_len = strlen(str);
    int from_len = strlen(from);
    int to_len = strlen(to);

    int count = 0;
    char *pos = str;

    while ((pos = strstr(pos, from)) != NULL) {
        count++;
        pos += from_len;
    }

    int new_len = str_len + count * (to_len - from_len);

    char *result = (char *)malloc(new_len + 1 * sizeof(char));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return NULL;
    }

    int result_pos = 0;
    int str_pos = 0;

    while (str_pos < str_len) {
        char *next = strstr(str + str_pos, from);
        if (next == NULL) {
            while (str_pos < str_len) {
                result[result_pos] = str[str_pos];
                result_pos++;
                str_pos++;
            }
            break;
        } else {
            int chars_to_coppy = next - (str + str_pos);
            while (chars_to_coppy > 0) {
                result[result_pos] = str[str_pos];
                result_pos++;
                str_pos++;
                chars_to_coppy--;
            }
            for (int i = 0; i < to_len; i++) {
                result[result_pos] = to[i];
                result_pos++;
            }
            str_pos += from_len;
        }
    }
    result[result_pos] = '\0';
    return result;
}
