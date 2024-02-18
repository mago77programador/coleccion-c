// Find the Minimum Number in an Array
#include <stdio.h>

int main(void)
{
    int arr[] = {6, 90, 23, 43, 2, 98, 1};
    int min;
    int lenght = sizeof(arr) / sizeof(arr[0]);
    
    min = arr[0];

    // From 1, why? Because line 10
    for (int i = 1; i < lenght; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("Minimun: %i\n", min);
}