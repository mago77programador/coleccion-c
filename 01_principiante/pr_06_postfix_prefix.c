/* 
    Mira atentamente. 'x' e 'y' se van a incrementar en 1
    Pero ¿que pasa con 'a' y 'b'?
    'a' recibe el valor de 'x' UNA VEZ se ha incrementado en 1
    'b' recibe el valor de 'y' ANTES de que el valor de este se incremente en 1
*/
#include <stdio.h>

int main(void)
{
    int x = 7;
    int y = 3;

    int a = ++x;
    int b = y++;

    printf("x: %i\ny: %i\na: %i\nb: %i\n", x, y, a, b);
}
