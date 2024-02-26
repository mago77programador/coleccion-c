/*
    Inicializadores designados: matrices
    Designated initializers: arrays
    Output:
    0.000000 ·· 3.000000 ·· 0.000000 ·· 0.000000 ·· 0.000000 ··
    0.000000 ·· 0.000000 ·· 0.000000 ·· 0.000000 ·· 0.000000 ··
    0.000000 ·· 0.000000 ·· 5.000000 ·· 0.000000 ·· 1.000000 ··
    0.000000 ·· 0.000000 ·· 0.000000 ·· 0.000000 ·· 0.000000 ··
    0.000000 ·· 0.000000 ·· 0.000000 ·· 0.000000 ··
*/
#include <stdio.h>

int main(void)
{
    double numbers[24] = { [1] = 3, [12] = 5, [14] = 1 };
    int length = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < length; i++)
    {
        printf("%lf ·· ", numbers[i]);
    }
    printf("\n");
}