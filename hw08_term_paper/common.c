#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "common.h"

float f1(float x)
{
    return (0.6*x + 3);
}

float f2(float x)
{
    return ((x-2)*(x-2)*(x-2) - 1);
}

float f3(float x)
{
    if (x != 0)
        return (3/x);
    else
    {
        fprintf(stderr, "Division by zero\n");
        return 0;
    }
}

float f1_f2(float x)
{
    return f1(x) - f2(x);
}

float f1_f3(float x)
{
    return f1(x) - f3(x);
}

float f2_f3(float x)
{
    return f2(x) - f3(x);
}

float df1(float x)
{
    return 0*x + 0.6;
}

float ddf1(float x)
{
    return 0*x + 0;
}

float df2(float x)
{
    return 3*x*x - 12*x + 12;
}

float ddf2(float x)
{
    return 6*x - 12;
}

float df3(float x)
{
    return -3 / (x*x);
}

float ddf3(float x)
{
    return 6 / (x*x*x);
}
