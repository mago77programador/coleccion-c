# include <stdio.h>

typedef struct point
{
    int x;
    int y;
}
point_s;

point_s makepoint(int x, int y);

int main(void)
{
    point_s p = makepoint(42, 24);
    printf("%i, %i\n", p.x, p.y);
}

point_s makepoint(int x, int y)
{
    /* The C Programming Language, Brian Kernighan y Dennis Ritchie
    point_s temp;
    temp.x = x;
    temp.y = y;
    return temp; */

    // Up-to-date C
    point_s tmp = {x, y};
    return tmp;
}
