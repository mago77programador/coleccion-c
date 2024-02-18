/*
    Tomamos el papel de un juez deportivo.
    Supongamos que evaluamos la actuación de un atleta
    por varios conceptos:
    - Originalidad
    - Perfección en la realización de ejercicios obligatorios
    - Dificultad
    - Nivel artístico
    Se califica de 0 a 7 (con décimales)
    Y el peso de cada calificación es de:
    2 3 5 2 respectivamente
*/
#include <stdio.h>

float evaluacion_concepto(float concepto, int peso);
void clean_stdin(void);

int main(void)
{
    char *nombre[33];
    float orig, obli, difi, arti, resu;
    orig = obli = difi = arti = resu = 0.0;
    int p_orig, p_obli, p_difi, p_arti, suma_p;
    p_orig = p_arti = 2;
    p_obli = 3;
    p_difi = 5;
    suma_p = p_orig + p_obli + p_difi + p_arti;

    printf("Introduce el nombre de el/la atleta: \n");
    scanf(" %[^\n]", nombre);
    clean_stdin;
    printf("Se puntua de 1 a 7, pudiendo usar decimales.\n");
    printf("Originalidad: ");
    scanf("%f", &orig);
    printf("Ejercicios obligatorios: ");
    scanf("%f", &obli);
    printf("Dificultad: ");
    scanf("%f", &difi);
    printf("Nivel artístico: ");
    scanf("%f", &arti);

    // Comprobamos que el usuario coopera
    if (orig < 0 || orig > 7 || obli < 0 || obli > 7
        || difi < 0 || difi > 7 || arti < 0 || arti > 7)
    {
        printf("Te has equivocado en alguna puntuación.\n");
        return 1;
    }
    // La siguiente línea es una "tontería" puesto que sería lo mismo hacer (orig * p_orig) + ...
    resu = ( evaluacion_concepto(orig, p_orig) + evaluacion_concepto(obli, p_obli) + evaluacion_concepto(difi, p_difi) + evaluacion_concepto(arti, p_arti) ) / suma_p;

    printf("%s ha obtenido una puntuación final de %.3f siendo el máximo alcanzable teóricamente 7 puntos.\n", nombre, resu);
}

float evaluacion_concepto(float concepto, int peso)
{
    return concepto * peso;
}

void clean_stdin(void)
{
    int c;
    do
    {
        c = getchar();
    }
    while (c != '\n' && c != EOF);
}
