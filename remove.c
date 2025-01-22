#include <stdio.h>
#include <iso646.h>

const char *colors[] = {
    "\033[31m",
    "\033[32m",
    "\033[33m",
    "\033[34m",
    "\033[35m",
    "\033[36m",
};

const char *reset = "\033[0m";

void remove_comments(FILE *input, FILE *output);

int main() {
    remove_comments(stdin, stdout);
    return 0;
}

void remove_comments(FILE *input, FILE *output)
{
    int c, next;
    int in_string = 0; // Флаг нахождения в строке
    int in_char = 0;  // Флаг нахождения в символьной константе
    
    while ((c = fgetc(input)) != EOF) {
        if (in_string) {
            // Если в строке
            //fputc(fgetc(input), output);
            fprintf(output, "%s%c", colors[3], c);
            if (c == '\\') {
                // Экранированый символ
                fputc(fgetc(input), output);
                //fprintf(output, "%c", fgetc(input));
            } else if (c == '"') {
                in_string = 0; // Конец строки
                //fprintf(output, "%s", reset); // Сброс цвета
            }
        } else if (in_char) {
            // Если в символьной константе
            fputc(c, output);
            //fprintf(output, "%s%c", colors[4], c);
            if (c == '\\') {
                // Экранированый символ
                fputc(fgetc(input), output);
                //fprintf(output, "%c", fgetc(input));
            } else if (c == '\'') {
                in_char = 0; // Конец символьной константе
                //fprintf(output, "%s", reset);
            }
        } else if (c == '/') {
            // Возвожное начало коментария
            next = fgetc(input);
            if (next == '/') {
                // Однострочный коментарий
                //fprintf(output, "%s", colors[1]);
                while ((c = fgetc(input)) != EOF and c != '\n') {
                    // Пропускаем
                }
                fputc('\n', output);
                //fprintf(output, "%s\n", reset);
            } else if (next == '*') {
                // Многострочный комментарий
                while ((c = fgetc(input)) != EOF) {
                    if (c == '*' && (next = fgetc(input)) == '/') {
                        break;
                    }
                }
            } else {
                // Это не комментарий
                fputc(c, output);
                fputc(next, output);
                //fprintf(output, "%c%c", c, next);
            }
        } else {
            // Обычный тескт
            //fputc(c, output);
            fprintf(output, "%s%c", colors[0], c);
            if (c == '"') {
                in_string = 1;
            } else if (c == '\'') {
                in_char = 1; // Начало символьной константы
            }
        }
    }
}
