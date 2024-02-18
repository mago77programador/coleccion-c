#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day( int year, int yearday, int *pmonth, int *pday);

static int day_tab[2][13] =
{
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main(void)
{
    // TO DO: ask the user for input and improve the printf
    // But I leave the code like this so as not to delay
    int m, d;
    int question = day_of_year(1969, 8, 9);
    month_day(1969, 221, &m, &d);
    printf("%i\n", question);
    printf("%i %i\n", m, d);
}

// Set day of year from month & day
int day_of_year(int year, int month, int day) 
{     
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; i < month; i++)
        day += day_tab[leap][i];
    return day;
}

// Set month, day from day of year
void month_day( int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; yearday > day_tab[leap][i]; i++)
        yearday -= day_tab[leap][i];
    *pmonth = i;
    *pday = yearday;
}
