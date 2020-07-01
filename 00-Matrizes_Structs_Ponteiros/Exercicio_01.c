#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v1, v2;
    int resultado;
    int *p1, *p2;

    p1 = &v1;
    p2 = &v2;

    printf("v1: ");
    //scanf("%d", &v1);
    scanf("%d", p1);

    printf("v2: ");
    //scanf("%d", &v2);
    scanf("%d", p2);

    resultado = (*p1) + (*p2);

    printf("%d + %d = %d\n", (*p1), (*p2), resultado);


    return 0;
}
