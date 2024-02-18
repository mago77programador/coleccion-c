#include <stdio.h>
#include <locale.h>

#define BUFFER_SIZE 1024

int main(void)
{
    char buffer[BUFFER_SIZE];
    
    // Establecer el idioma a español
    setlocale(LC_ALL, "");
    
    FILE *fp = fopen("../99_archivos/output_av_09a.txt", "w");

    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    while (fgets(buffer, BUFFER_SIZE, stdin) != NULL)
    {
        // read a line of input into the buffer
        //fgets(buffer, BUFFER_SIZE, stdin);
        fputs(buffer, fp);
    }

    fclose(fp);

    return 0;
}