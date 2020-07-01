#include <stdio.h>
#include <stdlib.h>

typedef struct LISTA
{
    int info;
    struct LISTA *prox;
}Lista;

typedef struct FILA
{
    Lista *ini;
    Lista *fim;
}Fila;

void criaFilaVazia(Fila *fila);
Lista *criaNovoElemento(int i);
void inserirNaFila(Lista *e, Fila *fila);
void printFila(Fila *fila);
Lista *pegarDaFila(Fila *fila);

int main()
{
    Fila fila;
    Lista *elemento;

    criaFilaVazia(&fila);

    elemento = criaNovoElemento(19487);
    inserirNaFila(elemento, &fila);

    elemento = criaNovoElemento(8);
    inserirNaFila(elemento, &fila);

    elemento = criaNovoElemento(17);
    inserirNaFila(elemento, &fila);

    elemento = criaNovoElemento(13);
    inserirNaFila(elemento, &fila);

    printFila(&fila);

    elemento = pegarDaFila(&fila);

    printf("Elemento retornado da fila: %d\n", elemento->info);

    free(elemento);

    printFila(&fila);

    return 0;
}

void criaFilaVazia(Fila *fila)
{
    fila->ini = NULL;
    fila->fim = NULL;

}

Lista *criaNovoElemento(int i)
{
    Lista *e;

    e = (Lista *) malloc(sizeof(Lista));

    if(e == NULL)
    {
        exit(-1);
    }

    e->info = i;
    e->prox = NULL;

    return e;
}

void inserirNaFila(Lista *e, Fila *fila)
{
    if(fila->ini == NULL && fila->fim == NULL)
    {
        fila->ini = e;
        fila->fim = e;
        e->prox = NULL;
    }
    else
    {
        fila->fim->prox = e;
        e->prox = NULL;
        fila->fim = e;
    }
}

void printFila(Fila *fila)
{
    Lista *aux;

    for(aux = fila->ini; aux != NULL; aux = aux->prox)
    {
        printf("%d\n", aux->info);
    }

    printf("================================\n");
}

Lista *pegarDaFila(Fila *fila)
{
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
