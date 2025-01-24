/*
A3 - Извлечение бит.
На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31). Требуется взять K младших битов числа N и вывести полученное таким образом число.
*/

#include <stdio.h>
#include <inttypes.h>

uint32_t setMask(uint32_t);

int main()
{
    uint32_t N, K;
    scanf("%d %d", &N, &K);
    printf("%d\n", (N & setMask(K)));
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
    return mask;
}
