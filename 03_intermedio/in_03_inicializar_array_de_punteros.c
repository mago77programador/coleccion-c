#include <stdio.h>

char *month_name(int n);

int main(void)
{
    int month_number = 0;
    printf("What is the number of the month of which you\nwant to know its corresponding name? ");
    scanf("%i", &month_number);
    printf("%s\n", month_name(month_number));
}

// Return name of n-th month
char *month_name(int n)
{
    static char *name[] =
    {
        "illegal month",
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    return((n < 1 || n > 12) ? name[0] : name[n]);
}