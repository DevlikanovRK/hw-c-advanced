/*
C1 - Префикс и суффикс.
На стандартном потоке ввода задаются две символьные строки, разделённые символом перевода строки. Каждая из строк не превышает подлине 104. В строках не встречаются пробельные символы. На стандартный поток вывода напечатайте два числа, разделённых пробелом: первое число — длина наибольшего префикса первойстроки, являющегося суффиксом второй; второе число — наоборот, длина наибольшего суффикса первой строки, являющегося префиксомвторой. Сравнение символов проводите с учётом регистра (т.е. символы 'a' и 'A' различны).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Input arrays size */
#define L 2003

int main(void)
{
/* Read input */
    char str1[L] = {0};
    char str2[L] = {0};
    if (!fgets(str1, sizeof(str1), stdin))
    {
        //(stderr, "Input error\n");
        printf("0 0\n");
        return 0;
    }
    if (!fgets(str2, sizeof(str2), stdin))
    {
        //fprintf(stderr, "Input error\n");
        printf("0 0\n");
        return 0;
    }
    
/* Check print */
/*    
    printf("\n");
    for (int i = 0; str1[i]; ++i)
        printf("%c", str1[i]);
    printf("\n");
    for (int i = 0; str2[i]; ++i)
        printf("%c", str2[i]);
    printf("\n");
*/    
    
/* Some additiona variables */    
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    int l_min = ((l1 <= l2) ? l1 : l2);
    char str1_tmp[L] = {0};
    char str2_tmp[L] = {0};

/* Prefix - Sufix */
    int l_ps = 0;
    for (int i = 1; i < l_min; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            str1_tmp[j] = str1[j];
            //printf("str1_tmp[j] = %c\n", str1_tmp[j]);
            str2_tmp[j] = str2[l2 - i + j - 1];
            //printf("str2_tmp[j] = %c\n", str2_tmp[j]);
            if (!strcmp(str1_tmp, str2_tmp))
                l_ps = i;
        }
        //printf("------------------\n");
    }
    
/* NULL tmp arrays */
    for (int i = 0; i < L; ++i)
    {
        str1_tmp[i] = 0;
        str2_tmp[i] = 0;
    }
    
/* Sufix - Prefix */
    int l_sp = 0;
    for (int i = 1; i < l_min; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            str1_tmp[j] = str1[l1 - i + j - 1];
            //printf("str1_tmp[j] = %c\n", str1_tmp[j]);
            str2_tmp[j] = str2[j];
            //printf("str2_tmp[j] = %c\n", str2_tmp[j]);
            if (!strcmp(str1_tmp, str2_tmp))
                l_sp = i;
        }
        //printf("------------------\n");
    }
    
    printf("%d %d\n", l_ps, l_sp);
    return 0;
}
