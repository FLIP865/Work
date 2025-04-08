#include <stdio.h>
#include <stdlib.h>

struct list_t {
    struct list_t *next;
    int data;
};

int list_is_a_loop(struct list_t *top);

int main() {
    struct list_t *a = malloc(sizeof(struct list_t));

    a->data = 1; a->next = a;

    int loop1 = list_is_a_loop(a);
    printf("Loop (no loop expected): %d\n", loop1);

    free(a);
    return 0;
}

int list_is_a_loop(struct list_t *top)
{
    struct list_t *rabbit = top;
    struct list_t *turtle = top;
    
    while (rabbit != NULL)
    {
        turtle = turtle->next;
        rabbit = rabbit->next;
        if (rabbit == NULL)
        {
            return 0;
        }

        rabbit = rabbit->next;
        if (turtle == rabbit)
        {
            return 1;
        }
        else if (rabbit == turtle)
        {
            return 1;
        }
    }
    return 0;
}

