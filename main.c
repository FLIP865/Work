#include <stdio.h>
#include "my_alloc.h"

#define ALLOCSIZE 1000

int main()
{
    char *p1, *p2;
    p1 = alloc(100);
    if (p1 != 0) {
        printf("Успешно выделено 100 байт по адресу %p\n", (void *)p1);
    } else {
        printf("Ошибка выделения памяти для p1\n");
    }

    afree(p1);
    printf("Освобождена память по адресу %p\n", (void*)p1);

    p2 = alloc(100);
    if (p2 != 0) {
        printf("Успешно выделено 100 байт по адресу %p\n", (void *)p2);
    } else {
        printf("Ошибка выделения памяти для p2\n");
    }
    afree(p2);
    printf("Освобождена память по адресу %p\n", (void *)p2);
    return 0;
}
