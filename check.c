#include <stdio.h>
#include <iso646.h>

#define MAXSTACK 1024

int check_syntax(FILE *input);

int main() {
    char again;
    do {

        if (check_syntax(stdin)) {
            printf("Syntax is correct.\n");
        } else {
            printf("Syntax is not correct.\n");
        }

        printf("\nDo you want to chack again? (y/n): ");
        scanf(" %c", &again);

        // Очистка буфера ввода, если остались данные
        while (getchar() != '\n') {
            continue;
        }

    } while (again == 'y' or again == 'Y');

    printf("Exiting. Goodbye!\n");
    return 0;
}

int check_syntax(FILE *input) {
    char stack[MAXSTACK];
    int top = 0;
    int c, next;
    int in_string = 0, in_char = 0, in_comment = 0;

    while ((c = fgetc(input)) != EOF) {
        if (in_string) {
            // Внутри строки
            if (c == '"' and stack[top - 1] == '"') {
                in_string = 0;
                top--;
            } else if (c == '\\') {
                // Пропускаем экранированый символ
                fgetc(input);
            }
        } else if (in_comment) {
            // Внутри многострочного комментария
            if (c == '*' and (next = fgetc(input)) == '/') {
                in_comment = 0;
            }
        } else {
            if (c == '"') {
                stack[top++] = c;
                in_string = 1;
            } else if (c == '\'') {
                stack[top++] = c;
                in_char = 1;
            } else if (c == '/') {
                next = fgetc(input);
                if (next == '*') {
                    in_comment = 1;
                } else if (next == '/') {
                    while ((c = fgetc(input)) != EOF and c != '\n') {
                        // Пропускаем
                    }
                } else {
                    // Не комментарий
                    ungetc(next, input);
                }
            } else if (c == '(' or c == '[' or c == '{') {
                stack[top++] = c;
            } else if (c == ')' or c == ']' or c == '}') {
                if (top == 0) {
                    printf("Unmatched closing bracket: %c\n", c);
                } 
                char last = stack[--top];
                if ((c == ')' and last != '(') or
                    (c == ']' and last != '[') or
                    (c == '}' and last != '{')) {
                    printf("Mismatched brackets: %c and %c\n", last, c);
                    return 0;
                }
            }
        }

        // Проверка переполнения стека
        if (top >= MAXSTACK) {
            printf("Stack overflow.\n");
            return 0;
        }
    }

    if (top != 0) {
        printf("Unmatched opening bracket or quote.\n");
        return 0;
    }
    return 1;
}
