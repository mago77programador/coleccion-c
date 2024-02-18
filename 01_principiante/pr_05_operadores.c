#include <stdio.h>

int main(void)
{
    int a = 40;
    printf("Valor original de a:       %i\n", a);
    a++;
    printf("Incremento en 1 unidad:    %i\n", a);
    a--;
    printf("Decremento de 1 unidad:    %i\n", a);
    a += 2;
    printf("Incremento de 2 unidades:  %i\n", a);
    a -= 12;
    printf("Decremento de 12 unidades: %i\n", a);
    a *= 3;
    printf("Multiplicamos por 3:       %i\n", a);
    a /= 6;
    printf("Dividimos entre 6:         %i\n", a);
}