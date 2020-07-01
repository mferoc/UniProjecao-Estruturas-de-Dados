#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct PONTO
{
	
	int x, y;
}Ponto;

Ponto *pontoCreate();
void setPonto(Ponto *, int , int );
void getPonto(Ponto *);
int calculaDistanciaEntrePontos(Ponto *, Ponto *);
void destroyPonto(Ponto *);


int main() {

	Ponto *p1;
	Ponto *p2;

	p1 = pontoCreate();
	p2 = pontoCreate();

	setPonto(p1, 1, 1);
	setPonto(p2, 3, 1);

	getPonto(p1);
	getPonto(p2);

	int d = calculaDistanciaEntrePontos(p1, p2);

	printf("A distancia entre os pontos eh: %d\n", d);

	destroyPonto(p1);
	destroyPonto(p2);

	return 0;
}

Ponto *pontoCreate() {

	Ponto *p;

	p = (Ponto *) malloc(sizeof(Ponto));

	if(p == NULL) {

		printf("Não há memória disponível\n");
		exit(-1);
	}

	p->x = 0;
	p->y = 0;

	return p;
}

void setPonto(Ponto *p, int x , int y ) {

	p->x = x;
	p->y = y;
}

void getPonto(Ponto *p) {

	printf("Ponto(%d, %d)\n", p->x, p->y );
}

int calculaDistanciaEntrePontos(Ponto *p1, Ponto *p2) {

	int d;

	d = sqrt( pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2) );

	return d;
}

void destroyPonto(Ponto *p) {

	free(p);
}