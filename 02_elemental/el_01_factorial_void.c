// Calcular el factorial de un nº usando una función de tipo void
#include <stdio.h>

void factorial();

int main(void)
{
    factorial();
}

void factorial()
{
    int i, n, resultado;
    printf("¿De qué nº deseas calcular el factorial?: ");
    scanf("%i", &n);
    resultado = 1;
    for (i = 2; i <= n; i++)
    {
        resultado *= i;
    }
    
    printf("El factorial de %i es %i.\n", n, resultado);
}