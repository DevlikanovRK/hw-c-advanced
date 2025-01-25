/*
A2 - Циклический сдвиг.
На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31). Требуется циклически сдвинуть биты числа N вправо на K битов и вывести полученное таким образом число.
*/

#include <stdio.h>
#include <inttypes.h>

uint32_t shiftCycleRight(uint32_t, uint32_t);

int main()
{
    uint32_t N, K;
    scanf("%d %d", &N, &K);
    printf("%u\n", shiftCycleRight(N, K));
    return 0;
}

uint32_t shiftCycleRight(uint32_t n, uint32_t k)
{
    
    return (n >> k) | (n << (sizeof(n)*8 - k));
}
