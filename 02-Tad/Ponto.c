#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct PONTO
{
    float x;
    float y;
};

typedef struct PONTO Ponto;

Ponto *criaPonto();
void setPonto(Ponto *p, float novo_x, float novo_y);
void printPonto(Ponto *p);
void liberaPonto(Ponto *p);
float calcDistancia(Ponto *p1, Ponto *p2);

int main()
{
    Ponto *p1;
    Ponto *p2;

    p1 = criaPonto();
    p2 = criaPonto();
    setPonto(p1, 1, 1);
    setPonto(p2, 3, 1);
    printPonto(p1);
    printPonto(p2);

    float d = calcDistancia(p1, p2);

    printf("A distancia entre os pontos eh de %f\n", d);

    liberaPonto(p1);

    return 0;
}

Ponto *criaPonto()
{
    Ponto *p;

    p = (Ponto *) malloc(sizeof(Ponto));

    if(p == NULL)
    {
        printf("Faltou memoria!\n");
        exit(-1);
    }

    p->x = 0;
    p->y = 0;

    return p;
}

void setPonto(Ponto *p, float novo_x, float novo_y)
{
    p->x = novo_x;
    p->y = novo_y;
}

void printPonto(Ponto *p)
{
    printf("\nPonto: (%f, %f)\n",
           p->x, p->y);
}

void liberaPonto(Ponto *p)
{
    free(p);
}

float calcDistancia(Ponto *p1, Ponto *p2)
{
    float d;

    d = sqrt(pow(p1->x - p2->x, 2.0) + pow(p1->y - p2->y, 2.0));

    return d;
}
