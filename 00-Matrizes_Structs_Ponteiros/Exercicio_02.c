#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v1, v2;
    int *p1, *p2;

    p1 = &v1;
    p2 = &v2;

    printf("v1: ");
    //scanf("%d", &v1);
    scanf("%d", p1);

    printf("v2: ");
    //scanf("%d", &v2);
    scanf("%d", p2);


    // Comparando os valores
    if(*p1 > *p2)
        printf("v1 eh maior do que v2\n");
    else if(*p2 > *p1)
        printf("v2 eh maior do que v1\n");
    else
        printf("v1 e v2 sao iguais\n");

    return 0;
}
