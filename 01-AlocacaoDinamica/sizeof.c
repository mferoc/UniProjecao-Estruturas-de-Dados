//Alocacao Dinam 1
//Operador sizeof

#include <stdio.h>

typedef struct ponto {
	float x, y;
}Ponto;

int main() {
	
	int x, f, d, c;
	x = sizeof(int);
	f = sizeof(float);
	d = sizeof(double);
	c = sizeof(char);
	
	printf("Tamanho do int = %d bytes\n", x);
	printf("Tamanho do float = %d bytes\n", f);
	printf("Tamanho do double = %d bytes\n", d);
	printf("Tamanho do char = %d bytes\n", c);
	printf("Tamanho da struct ponto = %d bytes", sizeof(Ponto));	
	
	return 0;
}
