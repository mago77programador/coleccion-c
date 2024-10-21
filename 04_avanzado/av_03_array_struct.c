#include <stdio.h>
#include <string.h>

#define ELEM 4
#define TAM 50

typedef struct
{
    int edad;
    float peso;
    char nombre[TAM];
} Persona;

void clean_stdin(void);

int main(void)
{
    Persona bloque_a[ELEM];

    for (int i = 0; i < ELEM; i++)
    {
        printf("Registremos a un vecino del bloque:\n");
        printf("Edad:\n");
        scanf("%i", &bloque_a[i].edad);
        printf("Peso:\n");
        scanf("%f", &bloque_a[i].peso);
        printf("Nombre:\n");
        scanf(" %[^\n]", bloque_a[i].nombre);
        clean_stdin();
    }

    printf("Estos son los datos recopilados:\n");

    for (int i = 0; i < ELEM; i++)
    {
        printf("%s tiene %i años y pesa %.2f kg.\n", bloque_a[i].nombre, bloque_a[i].edad, bloque_a[i].peso);
    }

    printf("_-_-_-_-_\n");
}

void clean_stdin(void)
{
    int c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
