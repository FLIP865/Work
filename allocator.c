#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#define POLL_SIZE 1024 * 1024

typedef struct Block {
    size_t size;
    int free;
    struct Block *next;
} Block;

static char memory_pool[POLL_SIZE];
static Block *free_list = (Block *)memory_pool;

void my_init() {
    free_list = (Block *)memory_pool;
    free_list->size = POLL_SIZE - sizeof(Block);
    free_list->free = 1;
    free_list->next = NULL;
}

// Функция поиска подходящего блока
Block *find_free_block(size_t size) {
    Block *current = free_list;
    while (current) {
        if (current->free && current->size >= size) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Разделение блока, если запрашиваемый размер меньше доступного
void split_block(Block *block, size_t size) {
    if (block->size >= size + sizeof(Block) + 8) {
        Block *new_block = (Block *)((char *)block + sizeof(Block) + size);
        new_block->size = block->size - size - sizeof(Block);
        new_block->free = 1;
        new_block->next = block->next;
        block->size = size;
        block->next = new_block;
    }
}

// Аллацируем память
void *my_malloc(size_t size) {
    if (size <= 0) return NULL;

    Block *block = find_free_block(size);
    if (!block) return NULL;

    block->free = 0;
    split_block(block, size);
    return (void *)(block + 1);
}

// Освобождаем память
void my_free(void *ptr) {
    if (!ptr) return;

    Block *block = (Block *)ptr - 1;
    block->free = 1;

    // Попытка слить с последующим блоком
    if (block->next && block->next->free) {
        block->size += block->next->size + sizeof(Block);
        block->next = block->next->next;
    }
}

// Отладочный вывод состояния памяти
void my_dump() {
    Block *current = free_list;
    printf("Состояние памяти:\n");
    while (current) {
        printf("[Адрес: %p | Размер: %zu | %s]\n", (void *)current, current->size, current->free ? "Свободено" : "Занято");
        current = current->next;
    }
}

int main() {
    my_init();

    void *p1 = my_malloc(128);
    void *p2 = my_malloc(128);
    my_dump();

    my_free(p1);
    my_free(p2);
    my_dump();

    return 0;
}