// Ejercicio similar al anterior pero usamos una función
#include <stdio.h>

int find_max(int arr[], int lenght);

int main(void)
{
    int first[] = {12, 56, 98, 11, 23};
    int second[] = {45, 34, 9, 39, 44, 23, 76};

    int lenght_1 = sizeof(first) / sizeof(first[0]);
    int lenght_2 = sizeof(second) / sizeof(second[0]);
    int max_1 = find_max(first, lenght_1);
    int max_2 = find_max(second, lenght_2);

    printf("Max_1: %i --- Max_2: %i\n", max_1, max_2);
}

int find_max(int arr[], int lenght)
{
    int max = arr[0];

    // From 1, why? Because line 21
    for (int i = 1; i < lenght; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}