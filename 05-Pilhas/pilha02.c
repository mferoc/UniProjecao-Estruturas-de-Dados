#include <stdio.h>
#include <stdlib.h>

typedef struct LISTA {
	int valor;
	struct LISTA *prox;
} Lista;

typedef struct PILHA {
	Lista *topo;
} Pilha;

Lista *pilhaVazia();
Lista *criaElemento(int);
void push(Lista *, Pilha *);
void printPilha(Lista *);

int main() {

	Pilha p;
	Lista *elemento;

	p.topo = pilhaVazia();
	
	elemento = criaElemento(42);
	push(elemento, &p);
	elemento = criaElemento(43);
	push(elemento, &p);
	
	printPilha(p.topo);
	return 0;
}

Lista *pilhaVazia() {
	return NULL;
}

Lista *criaElemento(int i) {
	Lista *e;

	e = (Lista *) malloc(sizeof(Lista));

	if(e = NULL) {
		exit(-1);
	}

 	e->prox = NULL;

	e->valor = i;

	return e;

}

void push(Lista *e, Pilha *p) {

	e->prox = p->topo;
	p->topo = e;
}

void printPilha(Lista *topo) {

	 Lista *aux;



    for(aux = topo; aux != NULL; aux = aux->prox)

    {

        printf("%d\n", aux->valor);

    }

}
