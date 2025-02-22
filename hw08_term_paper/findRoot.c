#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "common.h"
#include "findRoot.h"

int signF(float x, function f)
{
    return f(x)==0 ? 0 : (f(x) < 0 ? -1 : 1);
}

float rootFindLine(float xl, float xr, float eps, function f)
{
    float x, minx = xl, nextstep;
    nextstep = fabs(xr-xl)/(1/eps); //разбиваем на отрезки интервал
    int stepcount=0; 
    for(x=xl; x<xr; x += nextstep, stepcount++)
        if( fabs(f(x)) < fabs(f(minx)) )
            minx = x;
    printf("Find Line Search root for %d steps\n",stepcount);
    return minx;
}


float rootFindDiv(float xl, float xr, float eps, function f)
{
    int stepcount=0; //число шагов
    float xm;
    while(fabs(xr-xl)>eps) //вещественный модуль разницы или floatabs
    {
        stepcount++;
        xm=(xl+xr)/2; // середина отрезка
        if(signF(xl, f) != signF(xm, f)) //если знак отличается
            xr=xm;
        else
            xl=xm;
    }
    printf("Find Div Search root for %d steps\n",stepcount); //статистика
    return (xl+xr)/2;
}

 float rootFindDiv2(float xl, float xr, float eps, function f)
 {
    int stepcount=0; //число шагов
    float xm;
    while(fabs(xr-xl)>eps) //вещественный модуль разницы
    {
        stepcount++;
        xm=(xl+xr)/2; // середина отрезка
        if(f(xr)==0) // нашли решение на правой границе
        {
            printf("Find Div2 Search root for %d steps\n",stepcount);
            return xr;
        }        
        if(f(xl)==0) // нашли решение на левой границе
        {
            printf("Find Div2 Search root for %d steps\n",stepcount);
            return xl;
        }
        if(signF(xl, f) != signF(xm, f)) //если знак отличается
            xr=xm;
        else
            xl=xm;
    }
    printf("Find Div2 Search root for %d steps\n",stepcount); //статистика
    return (xl+xr)/2;
}

float rootFindChord(float xl, float xr, float eps, function f)
{
    int stepcount=0; 
    while(fabs(xr - xl) > eps)
    {
        xl = xr - (xr - xl) * f(xr) / (f(xr) - f(xl));
        xr = xl - (xl - xr) * f(xl) / (f(xl) - f(xr));
        stepcount++;
    }
    printf("Find Chord Search root for %d steps\n",stepcount);
    return xr;
}

float rootFindTangent(float xn, float eps, function f, function df)
{
    float x1  = xn - f(xn)/df(xn);
    float x0  = xn;
    int stepcount=0;    
    while(fabs(x0-x1) > eps)
    {
        x0 = x1;
        x1 = x1 - f(x1)/df(x1);
        stepcount++;    
    }
    printf("Find Tangent Search root for %d steps\n",stepcount);   
    return x1;
}

float rootFindCombine(float xl, float xr, float eps, function f, function df, function ddf)
{
   int stepcount=0;    
   while(fabs(xl-xr) > 2*eps)
   {
       if( f(xl)*ddf(xl)<0 )
           xl = xl - (f(xl)*(xl - xr))/(f(xl) - f(xr));
       else
           xl = xl - f(xl)/df(xl);
       if( f(xr)*ddf(xr)<0 )
           xr = xr - (f(xr)*(xr - xl))/(f(xr) - f(xl));
       else
           xr = xr - f(xr)/df(xr);
       stepcount++;        
   }
   printf("Find Tangent Search root for %d steps\n",stepcount);
   return (xl+xr)/2;
}
