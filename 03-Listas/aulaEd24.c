//Aula ed dia 24/05
//Lista encadeada simples
#include <stdio.h>
#include <stdlib.h>

typedef struct ElementoLista{
	int dado;
	struct ElementoLista *prox; //armazena o endereço de uma struct ElementoLista
}Lista;

Lista *criaListaVazia();
Lista *criaElemento(int);
Lista *insereElementoLista(Lista *, Lista *);
void imprimeLista(Lista *);
void desalocaLista(Lista *);

int main() {
	
	Lista *prim; //ponteiro para a primeira posicao da lista
	Lista *novo;
		
	prim = criaListaVazia();
	
	novo = criaElemento(42);
	prim = insereElementoLista(prim, novo);
	prim = insereElementoLista(prim, criaElemento(43));
	prim = insereElementoLista(prim, criaElemento(44));
	
	if(prim == NULL)
		printf("NULL\n");
		
	imprimeLista(prim);
	desalocaLista(prim);
	
	
	return 0;
}

Lista *criaListaVazia() {
	
	return NULL;
	//A função retorna o endereço do primeiro elemento de uma lista vazia;
}

Lista *criaElemento(int numero) {
	
	//cria um elemento para a lista, preenche o elemento e o retorna
	Lista *novo;
	novo = (Lista *) malloc(sizeof(Lista));
	
	if(novo == NULL) {
		exit(-1);
	}
	
	novo->dado = numero;
	novo->prox = NULL;
	
	return novo;
}

Lista *insereElementoLista(Lista *prim, Lista *novo) {
	//Os parametros sao o inicio da lista e o novo elemento a ser inserido na lista
	novo->prox = prim;
	
	return novo;
}

void imprimeLista(Lista *prim) {
	
	//Loop que percorre todos os elementos da lista
	Lista *aux;
	
	for(aux = prim; aux != NULL; aux = aux->prox) {
		printf("%d\t", aux->dado);
	}
}

void desalocaLista(Lista *prim) {
	
	Lista *aux;
	
	for(aux = prim; aux != NULL; prim = aux) {
		
		aux = aux->prox;
		free(prim);
	}
}


