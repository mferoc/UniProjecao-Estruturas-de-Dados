#include <stdio.h>
#include <stdlib.h>

typedef struct CONTEUDO
{
    int inteiro;
    float real;
}Conteudo;

typedef struct LISTA
{
    Conteudo c;
    struct LISTA *prox;
}Lista;

typedef struct PILHA
{
    Lista *topo;
}Pilha;

Lista *criaPilhaVazia();
Lista *criaElemento(int i, float r);
void push(Lista *e, Pilha *pilha);
void printPilha(Lista *topo);
Lista *pop(Pilha *pilha);

int main()
{
    Pilha pilha;
    Lista *elemento;

    pilha.topo = criaPilhaVazia();
    elemento = criaElemento(1, 1.0);
    push(elemento, &pilha);

    elemento = criaElemento(2, 2.0);
    push(elemento, &pilha);

    elemento = criaElemento(3, 3.0);
    push(elemento, &pilha);

    printPilha(pilha.topo);

    elemento = pop(&pilha);

    printf("Elemento retornado pelo pop: %d\t%f\n", elemento->c.inteiro, elemento->c.real);

    free(elemento);

    printPilha(pilha.topo);

    return 0;
}

Lista *criaPilhaVazia()
{
    return NULL;
}

Lista *criaElemento(int i, float r)
{
    Lista *e;

    e = (Lista *) malloc(sizeof(Lista));

    if(e == NULL)
    {
        exit(-1);
    }

    e->prox = NULL;
    e->c.inteiro = i;
    e->c.real = r;

    return e;
}

void push(Lista *e, Pilha *pilha)
{
    e->prox = pilha->topo;

    pilha->topo = e;
}

void printPilha(Lista *topo)
{
    Lista *aux;

    for(aux = topo; aux != NULL; aux = aux->prox)
    {
        printf("%d\t%f\n", aux->c.inteiro, aux->c.real);
    }
}

Lista *pop(Pilha *pilha)
{
    Lista *aux;

    aux = pilha->topo;

    pilha->topo = aux->prox;

    return aux;
}
