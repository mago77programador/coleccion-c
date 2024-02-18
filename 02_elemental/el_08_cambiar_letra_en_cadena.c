// Cambio de la letra 'a' por un espacio
#include <stdio.h>
#include <string.h>

void cambio(char s[]);

int main(void)
{
    char sentencia[] = "El mar se encuentra en calma.";
    cambio(sentencia);
    printf("%s\n", sentencia);
}

void cambio(char s[])
{
    int i, n;
    for (i = 0; n = strlen(s), i < n; i++)
    {
        if (s[i] == 'a')
        {
            s[i] = ' ';
        }
    }
}