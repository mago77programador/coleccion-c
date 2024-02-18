/*
    Intercambiar el valor de dos variables con una función.
    Aunque no entiendo el motivo, pues es natural que la
    función sea de tipo "void", también logro el mismo
    resultado con esta otra declaración:
        int swap(int *a, int *b);
*/ 
#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x, y;
    printf("Introduce el valor de la variable x: ");
    scanf("%i", &x);
    printf("Introduce el valor de la variable y: ");
    scanf("%i", &y);
    swap(&x, &y);
    printf("Ahora el valor de x es %i y el de y es %i.\n", x, y);
}

// int swap(int *a, int *b)  Ver arriba
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
