#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "common.h"
#include "findRoot.h"
#include "calcIntegral.h"
 
int main()
{
// Переменные для хранения значений абсцисс точек пересечения заданных функций между собой
    float x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0;
// Переменные для хранения значений абсцисс точек пересечения заданных функций с осью Ox
    float ox1 = 0, ox2 = 0;
// Задаем интервалы по оси абсцисс, на которых будем искать корни
    float intervals[4][2] = {{-7.5, -2.5}, {-2.5, -0.001}, {0.001, 2.5}, {2.5, 5}};    

// Вычисляем корни уравнений
    printf("Find roots for f1 and f2 functions:\n");
// Точность вычисления корней
    float eps1 = 0.001;
    // Для прямой f1
    ox1 = rootFindDiv2(intervals[0][0],intervals[0][1], eps1, f1);
    printf("Div2 Search root f1 on [%.1f : %.1f] = %f\n", intervals[0][0], intervals[0][1], ox1);
    // Для кубической параболы f2
    ox2 = rootFindChord(intervals[3][0],intervals[3][1], eps1, f2);
    printf("Chord Search root f2 on [%.1f : %.1f] = %f\n", intervals[3][0], intervals[3][1], ox2);
    printf("-----------------------------------\n");
// Вычисляем абсциссы точек пересечения заданных функций
    printf("Find intersections points:\n");
    x1 = rootFindChord(intervals[0][0],intervals[0][1], eps1, f1_f3);
    printf("Chord Search root f1-f3 on [%.1f : %.1f] = %f\n", intervals[0][0], intervals[0][1], x1);
    x2 = rootFindChord(intervals[1][0],intervals[1][1], eps1, f2_f3);
    printf("Chord Search root f2-f3 on [%.1f : %.1f] = %f\n", intervals[1][0], intervals[1][1], x2);
    x3 = rootFindDiv2(intervals[2][0],intervals[2][1], eps1, f1_f3);
    printf("Div2 Search root f1-f3 on [%.1f : %.1f] = %f\n", intervals[2][0], intervals[2][1], x3);
    x4 = rootFindChord(intervals[3][0],intervals[3][1], eps1, f2_f3);
    printf("Chord Search root f2-f3 on [%.1f : %.1f] = %f\n", intervals[3][0], intervals[3][1], x4);
    x5 = rootFindChord(intervals[3][0],intervals[3][1], eps1, f1_f2);
    printf("Chord Search root f1-f2 on [%.1f : %.1f] = %f\n", intervals[3][0], intervals[3][1], x5);
    printf("-----------------------------------\n");
    
// Вычисляем площади промежуточных фигур
    printf("Find figure area:\n");
// Точность вычисления интегралов
    float eps2 = 1 / eps1;
// Площади искомых фигур
    float S = 0, S1 = 0, S2 = 0, S3 = 0, S4 = 0, S5 = 0;    
    S1 = fabs(calcIntegralSimpson(x1, x2, eps2, f3));
    printf("Simpson S1 of f3 between [%.1f : %.1f] = %.3f\n", x1, x2, S1);
    S2 = fabs(calcIntegralSimpson(x1, ox1, eps2, f1));
    printf("Simpson S2 of f1 between [%.1f : %.1f] = %.3f\n", x1, ox1, S2);
    S3 = fabs(calcIntegralSimpson(ox1, x5, eps2, f1));
    printf("Simpson S3 of f1 between [%.1f : %.1f] = %.3f\n", ox1, x5, S3);
    S4 = fabs(calcIntegralSimpson(x2, ox2, eps2, f2));
    printf("Simpson S4 of f2 between [%.1f : %.1f] = %.3f\n", x2, ox2, S4);
    S5 = fabs(calcIntegralSimpson(ox2, x5, eps2, f2));
    printf("Simpson S5 of f2 between [%.1f : %.1f] = %.3f\n", ox2, x5, S5);
    S = S1 - S2 + S3 + S4 - S5;
    printf("-----------------------------------\n");
    printf("Area of figure is equal %.3f\n\n", S);    
    
// Пауза для просмотра результатов программы. Для выхода нажать "Enter"
    printf("Press \"Enter\" to exit...");
    while (getchar() != '\n');    
    return 0;    
}
