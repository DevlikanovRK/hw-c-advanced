/*
A8 - Весы.
В стартер боксе Geek Brains есть электронные чашечные весы (вместимость каждой чашки 1 тонна) и гири массами 1г, 3г, 9г, 27г, и т.д. по одной штуке каждой массы. Менеджер из рекламного отдела взял такие весы и не знает, можно ли взвесить что-нибудь тяжелое и если можно, сколько гирь придется положить на весы (на любую чашку). Надо помочь ему. Формат входных данных: единственное натуральное число – масса взвешиваемого товара в граммах (не больше 1000000000). Формат выходных данных: единственное целое число – общее количество гирь или число –1 если данный товар взвесить невозможно.
*/

#include <stdio.h>
#include <inttypes.h>
#include <math.h>

int main()
{
    uint32_t mass;
    // Max weight 1.000.000 g
    scanf("%" PRIu32, &mass);
    if (mass > 1000000)
    {
        printf("-1\n");
        return 0;
    }
    
    // Convert from decimal to ternary (little-endian)
    // Coefficient with weight "2" replace with "-1" and add "1" to next digit
    int8_t mass_base_3[sizeof(mass)*8] = {0};
    int digits = 0;
    for (int i = 0; mass > 0; ++i)
    {
        digits = i + 1;
        if (mass % 3 == 2)
        {
            mass_base_3[i] = -1;
            mass += 3;
        }
        else
            mass_base_3[i] = mass % 3;
        mass /= 3;
    }
    /* Print out (chek)
    printf("Mass_base_3:\n");
    for (int i = digits - 1; i >= 0; --i)
        printf("%d", mass_base_3[i]);
    printf("\n\n");
    */
    
    // Count not 0 digits
    int ans = 0;
    double left_scale = mass, right_scale = 0;
    for (int i = 0; i < digits; ++i)
    {
        if (mass_base_3[i] == 1)
        {
            right_scale += pow(3, i);
            ++ans;
        }
        if (mass_base_3[i] == -1)
        {
            left_scale += pow(3, i);
            ++ans;
        }
    }
    
    //printf("Left scale mass = %f\nRight scale mass = %f\n", left_scale, right_scale);
        
    (left_scale > 1000000 || right_scale > 1000000) ? (ans = 0) : ({});
    (ans == 0) ? (printf("-1\n")) : (printf("%d\n", ans));
    return 0;
}
