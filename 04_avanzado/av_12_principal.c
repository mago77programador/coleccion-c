#include <stdio.h>
#include "av_12_operaciones.h"

int main(void)
{
    int num;
    printf("Escribe un nº entero: \n");
    scanf("%i", &num);
    printf("El factorial de %i es %i.\nEl cubo es %i.\n", num, factorial(num), cubo(num));
}
