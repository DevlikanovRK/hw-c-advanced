/*
B0 - Максимальный блок.
Требуется реализовать только одну функцию, которая в данном списке находит адрес блока памяти занимающий больше всего места. Адрес хранится в поле address, поле size - соответствующий размер данного блока. Если список пустой, то функция должна возвращать NULL. Если есть несколько таких блоков, то вернуть адрес любого из них.
*/
/*
#include <stdio.h>
#include <inttypes.h>

typedef struct list {
    uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

uint64_t findMaxBlock(list*);

int main()
{
    list *head = NULL;
    
    uint64_t result = findMaxBlock(head);
    printf("Max block adress: %llu\n", result);
    
    return 0;
}
*/
uint64_t findMaxBlock(list *head)
{
    size_t max_size = 0;
    uint64_t p_max_struct = 0;
    
    for (list *current = head; current != NULL; current = current->next)
    {
        if (current->size > max_size)
        {
            max_size = current->size;
            p_max_struct = current->address;
        }
    }
    
    return p_max_struct;
}
