/*
    Convertir cadena a entero en C usando strtol
    (Este programa calcula la media aritmética de los números introducidos
    como argumentos del programa por el usuario
    Ejemplo: ./el_03_media_aritmetica 3 98 1 7  ==== 27,25)
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        char *ptr;
        int sum = 0;
        for (int i = 1; i < argc; i++)
        {
            sum += strtol(argv[i], &ptr, 10);
        }
        printf("La media de tus números es: %.3f\n", (float)sum / ((float)argc - 1));
    }
    else
    {
        printf("No, así no.\n");
    }
}
