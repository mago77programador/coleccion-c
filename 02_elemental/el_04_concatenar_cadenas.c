#include <stdio.h>
#include <string.h>

#define N 40

int main(void)
{
    char uno[N] = {"La vida"};
    char dos[N] = {" de Brian"};

    printf("Antes de strcat:\n");
    printf("uno: %s\n", uno);
    printf("dos: %s\n", dos);

    strcat(uno, dos);

    printf("Después de strcat(uno, dos):\n");
    printf("uno: %s\n", uno);
    printf("dos: %s\n", dos);
}