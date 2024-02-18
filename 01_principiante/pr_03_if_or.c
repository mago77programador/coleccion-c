#include <stdio.h>

int main(void)
{
    int num = 0;
    printf("Introduce un nº entre 0 y 30.\n");
    scanf("%i", &num);
    if (num < 0 || num > 30)
    {
        printf("No has seguido las instrucciones.\n");
        return 1;
    }
    printf("Bien, %i es un nº bonito.\n");
}