#include <stdio.h>

int main(void)
{
    int goals = 0;

    printf("2034 Football World Cup quarterfinals\n\n");
    do
    {
        printf("Spain %i - Canada 0\n", goals);
        goals++;
        printf("Wait a moment... Goooalll!\n");        
    }
    while (goals < 3);

    printf("\nFinal score: Spain %i - Canada 0\n", goals);
}