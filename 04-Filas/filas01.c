#include <stdio.h>
#include <stdlib.h>

typedef struct LISTA {
	int info;
	struct LISTA *prox;
} Lista;

typedef struct FILA {
	Lista *ini;
    Lista *fim;
} Fila;

void criaFilaVazia(Fila *);
Lista *criaNovoElemento(int);
void inserirFila(Lista *, Fila *);
void printFila(Fila *);
Lista *pegarDaFila(Fila *);

int main() {
	
    Fila f;
    Lista *elemento;
    criaFilaVazia(&f);
    elemento = criaNovoElemento(42);
    inserirFila(elemento, &f);
    elemento = criaNovoElemento(43);
    inserirFila(elemento, &f);
    elemento = criaNovoElemento(44);
    inserirFila(elemento, &f);

    printFila(&f);
    pegarDaFila(&f);
    printFila(&f);


    return 0;
}

void criaFilaVazia(Fila *f) {

    f->ini = NULL;
    f->fim = NULL;
}

Lista *criaNovoElemento(int i) {

    Lista *e;

    e = (Lista *) malloc(sizeof(Lista));

    if(e == NULL) {
        exit(-1);
    }
    e->info = i;
    e->prox = NULL;

    return e;
}

void inserirFila(Lista *e, Fila *f) {

    if(f->ini==NULL && f->fim==NULL) {
        f->ini = e;
        f->fim = e;
        e->prox = NULL;
    } else {
        f->fim->prox = e;
        e->prox = NULL;
        f->fim = e;
    }
}

void printFila(Fila *f) {

	 Lista *aux;

    for(aux = f->ini; aux != NULL; aux = aux->prox)    {

        printf("%d\n", aux->info);
    }
}

Lista *pegarDaFila(Fila *fila){
    if(fila->ini == NULL)
    {
        printf("A fila esta vazia! Deu ruim!\n");
        exit(-2);
    }
    else
    {
        Lista *aux;

        aux = fila->ini;
        fila->ini = aux->prox;

        return aux;
    }
}

