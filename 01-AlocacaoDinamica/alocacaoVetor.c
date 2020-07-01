#include <stdio.h>
#include <stdlib.h>

int main(void) {
  
  int *vetA, *vetB, *vetC, n, cont;

  printf("Digite o tamanho N do vetor: \n");
  scanf("%d", &n);

  
  vetA = (int *) malloc(n * sizeof(int));

  for(cont = 0; cont < n; cont++) {

      *(vetA + cont) = cont;
  }

  printf("O vetor A eh:\n");

  for(cont = 0; cont < n; cont++) {

      printf("Elemento %d = %d\n", cont, *(vetA + cont));
  }

  vetB = (int *) malloc(n * sizeof(int));

  for(cont = 0; cont < n; cont++) {

      *(vetB + cont) = 2 * cont;
  }

  printf("O vetor B eh:\n");

  for(cont = 0; cont < n; cont++) {

      printf("Elemento %d = %d\n", cont, *(vetB + cont));
  }


  vetC = (int *) malloc(n * sizeof(int));

  for(cont = 0; cont < n; cont++) {

      *(vetC + cont) = (*(vetA + cont) + *(vetB + cont));
  }

  printf("O vetor C eh:\n");

  for(cont = 0; cont < n; cont++) {

      printf("Elemento %d = %d\n", cont, *(vetC + cont));
  }
  
  free(vetA);
  free(vetB);
  free(vetC);
  
  return 0;
}