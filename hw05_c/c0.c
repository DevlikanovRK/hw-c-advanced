/*
C0 - Вычеркивание.
Сколько различных трехзначных чисел можно получить из заданного натурального N, вычеркивая цифры из его десятичной записи?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Memory allocation size */
#define L 8

int main()
{
/* Allocate memory for char array to store input data */
    char *input = calloc(L, sizeof(*input));
    if (!input)
    {
        printf("Memory allocation error!\n");
        return 1;
    }
    
/* Read input in char array */
    int ch;
    size_t index = 0, length = L;
    while ( (ch = getchar()) != '\n' )
    {
        if (index == length)
        {
            length *= 2;
            char *input_tmp = realloc(input, length * sizeof(*input));
            if (!input_tmp)
            {
                printf("Memory allocation error!\n");
                free(input);
                return 1;
            }
            input = input_tmp;
        }
        input[index++] = ch;        
    }
    
/* Chek print */
/*    
    printf("-----------------------------------\n");
    for (int i = 0; input[i]; ++i)
        printf("%d -> %d\n", i, input[i]);
    printf("\n");
    printf("-----------------------------------\n");
*/
       
/* Generate triplets from input data and count all in array nums*/
    length = strlen(input);
    int num = 0;
    int nums[900] = {0};
    for (int i = 0; i < length; ++i)
        if ( input[i] && (input[i] - '0') )
            for (int j = i + 1; j < length; ++j)
                if (input[j])
                    for (int k = j + 1; k < length; ++k)
                        if (input[k])
                        {
                            num = 100*(input[i]-'0') + 10*(input[j]-'0') + (input[k]-'0');
                            //printf("num = %d\n", num);
                            ++nums[num - 100]; 
                        }
                        
/* Count unique triplets */
    int count = 0;
    for (int i = 0; i < 900; ++i)
        if (nums[i])
            ++count;

/* Print answer */
    printf("%d\n", count);
    return 0;
}
