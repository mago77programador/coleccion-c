#include <stdio.h>

float average(int v[], int n);

int main(void)
{
    int points[] = {2, 5, 100, 34, 32};

    int lenght = sizeof(points) / sizeof(points[0]);

    float result = average(points, lenght);

    printf("Average: %.3f\n", result);
}

float average(int v[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
    }
    return (float)sum / (float)n;
}