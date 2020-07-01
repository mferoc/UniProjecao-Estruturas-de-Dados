#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    int *p1, *p2, x, y, z;

    x = 10;
    p1 = &x;
    p2 = p1;

    printf("x: %d \n", x);
    printf("&x: %d \n", &x);
    printf("p1: %d \n", p1);
    printf("&p1: %d \n", &p1);
    printf("p2: %d \n", p2);
    printf("&p2: %d \n", &p2);
    y = *p1;
    printf("y: %d \n", y);

    z = *p2;
    printf("z: %d \n", z);


    return 0;
}
