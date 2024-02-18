#include <stdio.h>

int main(void)
{
    int matriz[3][5] = {{2, 87, 12, 21, 77}, {25, 68, 100, 12, 9}, {4, 5, 101, 13, 2}};

    // Imprimir en pantalla la matriz
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }
}