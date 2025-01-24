/*
A0 - Максимум.
На стандартном потоке ввода задаётся натуральное число N (N > 0), после которого следует последовательность из N целых чисел.На стандартный поток вывода напечатайте, сколько раз в этой последовательности встречается максимум. Указание: использовать массивы запрещается. 
*/
#include <stdio.h>

int main()
{
    int qty = 0, count = 1, current = 0, next = 0;
    scanf("%d", &qty);
    scanf("%d", &current);
    while (--qty)
    {
        scanf("%d", &next);
        if (current < next)
        {
            current = next;
            count = 1;
        }
        else if (current == next)
            count++;            
    }
    
    printf("%d\n", count);
       
    return 0;
}

