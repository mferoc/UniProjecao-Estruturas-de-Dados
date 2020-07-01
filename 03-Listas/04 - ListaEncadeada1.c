#include <stdio.h>
#include <stdlib.h>

struct ELEMENTO
{
    int dado;
    struct ELEMENTO *prox;
};

typedef struct ELEMENTO Lista;

Lista *criaListaVazia();
Lista *insereInicioLista(Lista *l, Lista *novo);
Lista *criaElemento(int numero);
void imprimeLista(Lista *l);
void liberaLista(Lista *l);
void insereMeioLista(Lista *l, Lista *novo, int pos);

int main()
{
    Lista *l;
    Lista *novo;

    l = criaListaVazia();

    l = insereInicioLista(l, criaElemento(3));
    l = insereInicioLista(l, criaElemento(9));
    l = insereInicioLista(l, criaElemento(7));
    insereMeioLista(l, criaElemento(4), 2);
    insereMeioLista(l, criaElemento(5), 4);

    imprimeLista(l);





    liberaLista(l);

    return 0;
}

Lista *criaListaVazia()
{
    return NULL;
}

Lista *insereInicioLista(Lista *l, Lista *novo)
{
    novo->prox = l;

    return novo;
}

Lista *criaElemento(int numero)
{
    Lista *novo;

    novo = (Lista *) malloc(sizeof(Lista));

    if(novo == NULL)
        exit(-1);

    novo->dado = numero;
    novo->prox = NULL;

    return novo;
}

void imprimeLista(Lista *l)
{
    Lista *aux;

    for(aux = l; aux != NULL; aux = aux->prox)
    {
        printf("%d\t", aux->dado);
    }
}

void liberaLista(Lista *l)
{
    Lista *aux;

    for(aux = l; aux != NULL; l = aux)
    {
        aux = aux->prox;
        free(l);
    }
}

void insereMeioLista(Lista *l, Lista *novo, int pos)
{
    int contador = 0;
    Lista *aux;

    aux = l;

    do
    {
        aux = aux->prox;
        contador++;
    }while(contador != pos - 1);

    novo->prox = aux->prox;
    aux->prox = novo;


}
