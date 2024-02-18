// Programa que pide un número entero positivo y 
// escribe en la salida estándar si es par o impar

#include <stdio.h>

int main(void)
{
    int number;

    do
    {     
        printf("Please, enter a positive integer: ");
        scanf("%i", &number);
    }
    while (number < 1);    

    if (number % 2 == 0)
    {
        printf("%i is a even integer.\n", number);
    }
    else
    {
        printf("%i is a odd integer.\n", number);
    }
}