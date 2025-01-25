/*
A6 - Инверсия старших.
На вход программе подается беззнаковое 32-битное целое число N. Требуется изменить значения всех битов старшего байта числа на противоположные и вывести полученное таким образом число.
*/

#include <stdio.h>
#include <inttypes.h>

uint32_t invertMostSignificantByte(uint32_t);

int main()
{
    uint32_t N;
    scanf("%u", &N);  
    printf("%u\n", invertMostSignificantByte(N));
    return 0;
}

uint32_t invertMostSignificantByte(uint32_t n)
{  
    return (n ^ 0xff000000);
}
