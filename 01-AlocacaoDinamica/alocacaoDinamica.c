//Alocacao Dinam 2
//Função malloc
#include <stdio.h>
#include <stdlib.h>

typedef struct ponto {
	float x, y;
}Ponto;

int main() {
	
	//Cria um array de 50 inteiros (200 bytes);
	//int * i = malloc(200); //nao recomendado
	int *i = (int *) malloc(50 * sizeof(int));
	//Cria um array de 200 char (200 bytes);	
	//char * c = malloc(200); //nao recomendado
	char *c = (char *) malloc(200 * sizeof(char));
	
	int cont;
	
	for(cont = 0; cont < 50; cont++) {
		*(i + cont) = cont;
		printf("%d = %d\n", cont, *(i + cont));
	}
	
	for(cont = 0; cont < 200; cont++) {
		*(c + cont)= 'a';
		printf("%d - %c\n",cont, *(c + cont));
	}
	
	//Alocando um vetor de 5 posicoes e lendo os valores das posicoes do vetor do teclado
	//usando alocacao dinamica:
	int *p;
	p = (int *) malloc(5 * sizeof(int));
	
	//verificando se a alocacao de memoria deu certo
	if(p == NULL) {
		printf("Erro na alocacao\n");
		exit(1); //aborta a execucao do programa
	}
	
	for(cont = 0; cont < 5; cont++) {
		printf("Digite um valor para vetor[%d] = ", cont);
		scanf("%d", &p[cont]);
	}
	for(cont = 0; cont < 5; cont++) {
		printf("Vetor[%d] = %d\n", cont, *(&p[cont]));
	}
	free(p);
	
	return 0;
}
