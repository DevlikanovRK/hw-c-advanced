/*
A10 - Распаковать порядок.
Необходимо реализовать программу, которой на входе передаётся вещественное число в типе float, она возвращает порядок который хранится в поле EXP в виде десятичного целого числа. Функция должна строго соответствовать прототипу.
*/

#include <stdio.h>
#include <inttypes.h>

int extractExp(float);

int main()
{
    float input = 0.0;
    scanf("%f", &input);
    //printf("Input: %f\n", input);
    printf("%d\n", extractExp(input));
    return 0;
}

int extractExp(float input)
{
    // Type casting with pointers
    uint32_t num = *(uint32_t*)&input;
    // Mask for exponent part 0111 1111 1000 0000 0000 0000 0000 0000
    num &= 0x7F800000;
    num >>= 23;
    // printf("NUM: %d\n", num);
    return num;
}
