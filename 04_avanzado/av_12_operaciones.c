#include "av_12_operaciones.h"

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    
    return n * factorial(n - 1);
}

int cubo(int n)
{
    return n * n * n;
}
