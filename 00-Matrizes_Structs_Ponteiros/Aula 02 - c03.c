#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    int *p, q, x;

    x = 15;
    p = &x;
    q = *p;

    printf("%d \n", p);
    printf("%d \n", *p);
    printf("%d \n", q);

    return 0;
}

