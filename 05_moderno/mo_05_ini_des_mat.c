/*
    Inicializadores designados: matrices
    Designated initializers: arrays
    Initialization order is arbitrary
    Positional and designated initializers can be freely mixed
    You can initialize a range of elements to the same value
    You can ignore "="
    Output:
    2.000000 ·· 0.000000 ·· 0.000000 ·· 0.000000 ·· 1.012010 ··
    0.000000 ·· 0.000000 ·· 45.000000 ·· 0.000000 ·· 0.000000 ··
    3.000000 ·· 5.000000 ·· 13.000000 ·· 100.000000 ·· 1.000000 ··
    200.000000 ·· 200.000000 ·· 200.000000 ·· 200.000000 ··
    200.000000 ·· 0.000000 ·· 32.000000 ·· 0.000000 ·· 57.000000 ··
*/
#include <stdio.h>

int main(void)
{
    double numbers[24] = { 2, [10] = 3, 5, [12] = 13, 100, [7]45, [14] = 1,
                        [23]57, [21]32, [15 ... 19] = 200, [4]1.01201 };
    int length = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < length; i++)
    {
        printf("%lf ·· ", numbers[i]);
    }
    printf("\n");
}