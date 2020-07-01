#include <stdio.h>
#include <stdlib.h>

typedef struct LISTA {
	int valor;
	struct LISTA *prox;
} Lista;

typedef struct PILHA {
	Lista *topo;
} Pilha;

Lista *criaPilhaVazia();
Lista *criaElemento(int);
void push (Lista *, Pilha *);
void printPilha(Pilha *);
Lista *pop (Pilha *);

int main() {
	Pilha p;
	Lista *elemento;
	//criar a pilha vazia:
	p.topo = criaPilhaVazia();
	
	//cria elementos da pilha:
	elemento = criaElemento(1);
	push (elemento, &p);
	
	elemento = criaElemento(2);
	push (elemento, &p);
	
	elemento = criaElemento(3);
	push (elemento, &p);
	
	printPilha(&p);
	
	elemento = pop(&p);
	
	printf("Elemento retornado: %d\n", elemento->valor);
	
	free(elemento);
	
	printPilha(&p);
	
	return 0;
}

Lista *criaPilhaVazia() {
	return NULL;
}

Lista *criaElemento (int i){
	//utilizar alocação dinâmica sempre que for adicionar algo à pilha
	Lista *e;
	
	e = (Lista *) malloc(sizeof (Lista));
	
	if (e==NULL) {
		exit(-1);
	}
	
	e->prox = NULL;
	e->valor = i;
	
	return e;
}

void push (Lista *e, Pilha *p){
	e->prox = p->topo;
	p->topo = e;
}
//para imprimir uma lista, é preciso ter uma variavel auxiliar que vai percorrer os elementos da lista
void printPilha(Pilha *p){
	Lista *aux;
	
	for (aux = p->topo; aux != NULL ;aux = aux->prox){
		printf("%d\n", aux->valor);
	}
	
}

Lista *pop (Pilha * p){
	Lista *aux;
	
	aux = p->topo;
	
	p->topo = aux->prox;
	
	return aux;
	}


