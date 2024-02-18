#include <stdio.h>

#define BUFFER_SIZE 1024

int main(void)
{
    char buffer[BUFFER_SIZE];
        
    FILE *fp = fopen("../99_archivos/output_av_09b.txt", "w");

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