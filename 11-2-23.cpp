#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int encontrar(int b[], int l){
	int a, index;
	a = 1000000;
	index = -1;
	for(int i =0;i<l;i++)
		if(b[i]<a){
			a=b[i];
			index = i;
		}
		return index;
}

int main() {

	int i,j,n,temp=0,posicion=0;
	srand(time(NULL));
	
	printf("Numero de elementos a ordenar\n");
	scanf("%d", &n);
	
	int lista[n];
	printf("Lista sin ordenar\n");
	for (i=0;i<n;i++){
		lista[i]=rand() % (30 + 1 - 1) + 1;
		printf(" %d ",lista[i]);
	}
	printf("\n");
	
	for (i=0;i<n;i++ ){
		posicion = i;
			for (j=i+1;j<n;j++){
				if (lista[posicion]>lista[j])posicion = j;
			}
			if (posicion != i){
				temp = lista[i];lista[i] = lista[posicion];lista[posicion] = temp;
			}
	}
	printf("Lista ordenada\n");
	for (i=0;i<n;i++)printf(" %d ",lista[i]);

printf("\n\nValor minimo: \t%d ", lista[encontrar(lista, n)]);
return 0;
}
