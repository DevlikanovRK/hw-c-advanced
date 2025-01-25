/*
A4 - Поиск последовательности бит.
На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31). Требуется взять K подряд идущих битов числа N так, чтобы полученное число было максимальным. Программа должна вывести полученное число.
*/

#include <stdio.h>
#include <inttypes.h>

uint32_t setMask(uint32_t);

int main()
{
    uint32_t N, K, result = 0, tmp = 0;
    scanf("%d %d", &N, &K);
    
    uint32_t mask = setMask(K);
    for (int i = sizeof(N)*8 - K; i >= 0; --i)
    {
        tmp = (N & mask);
        if (result < tmp)
            result = tmp;
        N >>= 1;
    }    
    printf("%u\n", result);
    return 0;
}

uint32_t setMask(uint32_t qty)
{
    int mask = 1;
    while (--qty)
    {
        mask <<= 1;
        ++mask;
    }
    //printf("mask = %d\n", mask);
    return mask;
}
