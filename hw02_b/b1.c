/*
B1 - Всего памяти.
Требуется реализовать только одну функцию, которая анализирует данный список и возвращает сколько всего памяти используется. Адрес хранится в поле address, поле size - соответствующий размер данного блока. Если список пустой, то функция должна возвращать NULL.
*/
/*
#include <stdio.h>
#include <inttypes.h>

typedef struct list {
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

size_t totalMemoryUsage(list*);

int main()
{
    list *head = NULL;
    
    size_t result = totalMemoryUsage(head);
    printf("Total memory usage: %llu\n", result);
    
    return 0;
}
*/
size_t totalMemoryUsage(list *head)
{
    size_t memo = 0;    
    for (list *current = head; current != NULL; current = current->next)
        memo += current->size;    
    return memo;
}
