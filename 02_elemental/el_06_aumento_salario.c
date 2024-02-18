/*
    Programa que recibe el salario de un trabajador y
    un porcentaje del aumento recibido; devuelve la cantidad aumentada
    y el nuevo salario
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float sal, perc, aum, nuevo;
    sal = perc = aum = nuevo = 0.0;

    printf("Salario actual: ");
    scanf("%f", &sal);
    printf("Aumento a aplicar (%): ");
    scanf("%f", &perc);

    aum = sal * (perc / 100);
    nuevo = sal + aum;

    printf("El aumento bruto obtenido es de %.2f euros.\nEl nuevo salario será %.2f euros\n", aum, nuevo);
}