// Fahrenheit-Celsius table
#include <stdio.h>

// Lower limit of table
#define LOWER 0
// Upper limit
#define UPPER 300
// Step size
#define STEP 20

int main(void)
{
    for (int fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    {
        printf("%4d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}