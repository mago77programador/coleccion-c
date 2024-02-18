#include <stdio.h>
#include <string.h>

void clean_stdin(void);

int main(void)
{
    // 7, un carácter para el querido NUL
    // char passw[7] = {"holITA"};   ---- También vale
    char passw[7] = "holITA";
    char user_input[7];

    printf("Su contraseña, por favor:\n");
    fgets(user_input, 7, stdin);
    clean_stdin();

    if (strcmp(passw, user_input) == 0)
    {
        printf("Acceso permitido\n");
        return 0;
    }
    printf("Acceso denegado\n");
    return 1;
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