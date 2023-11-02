#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int minimo(int b[], int l){
    int a, index;
    a=1000000;
    index=-1;
    for(int i=0;i<l;i++){
        if(b[i]<a){
            a=b[i];
            index=i;
        }
    }
    return index;
}

int maximo(int b[], int l){
    int a=-1000000;
    int index=-1;
    for (int i=0;i<l;i++){
        if (b[i]>a){
            a=b[i];
            index=i;
        }
    }
    return index;
}

double media(int b[], int l){
    int suma=0;
    for (int i=0;i<l;i++){
        suma+=b[i];
    }
    return(double)suma/l;
}

int mediana(int b[], int l){
    int posicion, temp;
    for (int i=0; i<l;i++){
        posicion=i;
        for (int j=i+1;j<l;j++){
            if (b[posicion]>b[j]){
                posicion=j;
            }
        }
        if (posicion!=i){
            temp=b[i];
            b[i]=b[posicion];
            b[posicion]=temp;
        }
    }
    if (l%2==0){
        return (b[l/2-1]+b[l/2])/2;
    } else{
        return b[l/2];
    }
}

int moda(int b[], int l){
    int moda=b[0];
    int maxFrecuencia=1;

    for (int i=0;i<l;i++){
        int contador=1;

        for (int j=i+1;j<l;j++){
            if (b[i]==b[j]){
                contador++;
            }
        }

        if (contador>maxFrecuencia){
            moda=b[i];
            maxFrecuencia=contador;
        }
    }

    return moda;
}

void Histograma(int b[], int l) {
    printf("Histograma en representacion de la frecuencia de cada numero:\n\n");

    for (int i=1;i<=30;i++){
        printf("%2d: ", i);
        for (int j=0;j<l;j++){
            if (b[j]==i){
                printf("*");
            }
        }
        printf("\n");
    }
}

int main(){
    int i, j, n, temp=0, posicion=0;
    srand(time(NULL));

    printf("Numero de elementos a ordenar\n");
    scanf("%d", &n);

    int lista[n];
    printf("Lista sin ordenar\n");
    for (i=0;i<n;i++){
        lista[i]=rand()%30+1;
        printf(" %d ", lista[i]);
    }
    printf("\n");

    for (i=0;i<n;i++){
        posicion=i;
        for (j=i+1;j<n;j++){
            if(lista[posicion]>lista[j])posicion=j;
        }
        if (posicion!=i){
            temp=lista[i];
            lista[i]=lista[posicion];
            lista[posicion]=temp;
        }
    }
    printf("Lista ordenada\n");
    for(i=0;i<n;i++){
		printf(" %d ", lista[i]);}
	    printf("\n\nValor minimo: %d ", lista[minimo(lista, n)]);
	    printf("\n\nValor maximo: %d ", lista[maximo(lista, n)]);
	    printf("\n\nValor de la media: %.2f ", media(lista, n));
	    printf("\n\nValor de la mediana: %d ", mediana(lista, n));
	    printf("\n\nValor de la moda: %d ", moda(lista, n));
		Histograma(lista, n);
	
    return 0;
}
