/*
A9 - Упаковать массив.
Необходимо реализовать программу, которая упаковывает переданный ей массив из 32-ух элементов 0 и 1 в указанную структуру данных.
*/

#include <stdio.h>
#include <inttypes.h>

struct pack_array
{
    uint32_t array; // поле для хранения упакованного массива из 0 и 1
    uint32_t count0 : 8; // счетчик нулей в array
    uint32_t count1 : 8; // счетчик единиц в array
};

void array2struct(int [], struct pack_array *);

int main()
{
    int input[32] = {0};
    for (int i = 0; i < 32; ++i)
        scanf("%d", &input[i]);
        
    struct pack_array st = {0};
    array2struct(input, &st);
 
    return 0;
}

void array2struct(int *input, struct pack_array *st)
{
    for (int i = 0; i < 32 ; ++i)
    {
        //Count 0 & 1
        if (input[i] == 0)
            st->count0++;
        else
            st->count1++;
        // Bin to dec 
        if (input[i])
            st->array |= (uint32_t) (1 << (31 - i));
    }
    printf("%u %u %u", st->array, st->count0, st->count1);    
    return;
}
