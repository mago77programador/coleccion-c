#include <stdio.h>

void shell(int v[], int n);

int main(void)
{
    int taxes[] = {3, 34, 54, 2, 23, 51, 65, 12};
    int length = sizeof(taxes) / sizeof(taxes[0]);

    shell(taxes, length);

    for (int i = 0; i < length; i++)
    {
        printf("%i ", taxes[i]);
    }
    printf("\n");
}

// Sort v[0]...v[n-1] into increasing order
void shell(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap)
            {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
}