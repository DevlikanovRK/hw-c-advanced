/*
A8 - Весы.
В стартер боксе Geek Brains есть электронные чашечные весы (вместимость каждой чашки 1 тонна) и гири массами 1г, 3г, 9г, 27г, и т.д. по одной штуке каждой массы. Менеджер из рекламного отдела взял такие весы и не знает, можно ли взвесить что-нибудь тяжелое и если можно, сколько гирь придется положить на весы (на любую чашку). Надо помочь ему. Формат входных данных: единственное натуральное число – масса взвешиваемого товара в граммах (не больше 1000000000). Формат выходных данных: единственное целое число – общее количество гирь или число –1 если данный товар взвесить невозможно.
*/

#include <stdio.h>
#include <inttypes.h>

int main()
{
    uint32_t mass;
    //Max weight 1.000.000.000 g  
    scanf("%" PRIu32, &mass);
    
    uint8_t mass_base_3[sizeof(mass)*8] = {0};
    int i = 0;
    while (mass > 0)
    {
        mass_base_3[i++] = mass % 3;
        mass /= 3;
    }
    
    /*for (int j = 0; j < i; ++j)
        printf("%d\n", mass_base_3[j]);*/
    
    int ans = 0;
    for (--i; i >= 0; --i)
        if (mass_base_3[i] != 0)
            ++ans;
            
    (ans == 0) ? (printf("-1\n")) : (printf("%d\n", ans));
    return 0;
}