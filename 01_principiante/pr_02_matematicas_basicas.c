// Matemáticas básicas
#include <math.h>
#include <stdio.h>

int main(void)
{
    int x, y;

    x = 20;
    y = 4;

    // Operaciones básicas
    int z = x + y;
    printf("El valor de z es: %i.\n", z);

    int resta = x - y;
    printf("Resta de x - y es: %i.\n", resta);

    // Investiga como realizar la multiplicación y división...
    // Cambio los valores de x e y para los siguientes ejercicios.
    x = 7;
    y = 2;
    // Saltamos a modulo o resto
    int resto = x % y;
    printf("El resto de dividir x entre y es: %i.\n", resto);

    // int parte_entera = x // y; Esto no existe en C.

    // Para las dos operaciones siguientes es necesaria la librería math.h
    int potencia = pow(x, y);
    printf("El valor de x elevado a y es: %i.\n", potencia);

    int raiz_cuadrada = sqrt(x);
    printf("La raíz cuadrada de x es: %i.\n", raiz_cuadrada);

    // Incremento y decremento
    x++;
    printf("%i\n", x);
    y--;
    printf("%i\n", y);
}
