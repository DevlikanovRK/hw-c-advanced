/*
A5 - Подсчет битов.
На вход программе подается беззнаковое 32-битное целое число N. Требуется найти количество единичных битов в двоичном представлении данного числа.
*/

#include <stdio.h>
#include <inttypes.h>

uint32_t countSetBits(uint32_t);

int main()
{
    uint32_t N;
    scanf("%u", &N);  
    printf("%u\n", countSetBits(N));
    return 0;
}

uint32_t countSetBits(uint32_t n)
{
    uint32_t qty = 0, mask = 1;
    for (int i = sizeof(n)*8; i > 0; --i)
    {
        if (n & mask)
            ++qty;
        n >>= 1;
    }    
    return qty;
}
