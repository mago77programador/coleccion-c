#include <stdbool.h>
#include <stdio.h>

typedef struct Socio
{
    const char *nombre;
    int anio_nacimiento;
    bool cuota_al_dia;
}
Socio;

int main(void)
{
    double value = { 0 };
    double numbers[6] = { 0 };
    Socio miembro_gym = { 0 };

    printf("Variable value = %lf\n****\n", value);

    int length = sizeof(numbers) / sizeof(numbers[0]);
    for (int i = 0; i < length; i++)
    {
        printf("%lf\n", numbers[i]);
    }

    printf("%s, %i\n", miembro_gym.nombre, miembro_gym.anio_nacimiento);
    printf("¿Está al corriente de pago?: %s\n", miembro_gym.cuota_al_dia ? "true" : "false");
}