#include <stdio.h>
#include <string.h>

#define TAM 50

// Definimos la estructura "Persona"
struct Persona
{
    int edad;
    float peso;
    char nombre[TAM];
};

// Creamos un alias para la estructura "Persona" llamado "Gente"
typedef struct Persona Gente;

// Función para limpiar el búfer de entrada
void clean_stdin(void);

int main(void)
{
    // Creando e inicializando una instancia de la estructura "Gente" llamada "juana"
    Gente juana = {0, 0.0, "Juana Parra"};

    // Imprimimos información sobre "juana"
    printf("%s tiene %i años y pesa %.2f kg.\n", juana.nombre, juana.edad, juana.peso);

    // Crear e inicializar otra instancia de "Gente" llamada "miguel"
    Gente miguel;
    miguel.edad = 21;
    miguel.peso = 100.1;
    strcpy(miguel.nombre, "Miguel Rodríguez");

    // Imprimimos información sobre "miguel"
    printf("%s tiene %i años y pesa %.2f kg.\n", miguel.nombre, miguel.edad, miguel.peso);

    // Crear una nueva instancia de "Gente" llamada "nuevo_amigo" y recibir datos desde el teclado
    Gente nuevo_amigo;
    printf("Registremos a su nuevo/a amigo/a:\n");
    printf("Edad:\n");
    scanf("%i", &nuevo_amigo.edad);
    printf("Peso:\n");
    scanf("%f", &nuevo_amigo.peso);
    printf("Nombre:\n");
    scanf(" %[^\n]", nuevo_amigo.nombre);
    clean_stdin();

    // Imprimimos información sobre "nuevo_amigo"
    printf("%s tiene %i años y pesa %.2f kg.\n", nuevo_amigo.nombre, nuevo_amigo.edad, nuevo_amigo.peso);
}

// Función para limpiar el búfer de entrada
void clean_stdin(void)
{
    int c;
    do
    {
        c = getchar();
    }
    while (c != '\n' && c != EOF);
}
