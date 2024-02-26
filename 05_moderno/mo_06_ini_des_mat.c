/*
    Inicializadores designados: matrices
    Designated initializers: arrays
    For arrays with unknown size, the largest designator subscript
    is used to determine it
    Output
    2.000000 ·· 0.000000 ·· 0.000000 ·· 0.000000 ·· 0.000000 ·· 0.000000 ··
    0.000000 ·· 0.000000 ·· 0.000000 ·· 0.000000 ·· 3.000000 ·· 0.000000 ··
    0.000000 ·· 90.000000 ·· 1.000000 ·· 0.000000 ·· 0.000000 ·· 0.000000 ··
    0.000000 ·· 35.000000 ·· 4.000000 ··
    21 elements
    numbers has type double[21]
    '35' lives in index 19; the '4' lives in the next (numbers[20])
    Thus, the array contains 21 elements
*/
#include <stdio.h>

int main(void)
{
    double numbers[] = { 2, [10] = 3, [19] = 35, 4, [13]90, 1 };
    int length = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < length; i++)
    {
        printf("%lf ·· ", numbers[i]);
    }
    printf("\n");
}