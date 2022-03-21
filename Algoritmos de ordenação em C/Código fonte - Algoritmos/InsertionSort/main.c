#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int V[10000];

void insertionSort(int *V,int tamanho){
	int i, j, aux;
	for(i=0;i<tamanho;i++){
		aux = V[i];
		for(j=i;(j>0) && (aux < V[j - 1]);j--){
			V[j] = V[j-1];
		}
		V[j] = aux;
	}
}

void imprimir(){
	for(int i = 0;i<10000;i++){
		printf("V[%d]: %d\n",i+1,V[i]);
	}
}

int main() {
	for(int i = 0;i<10000;i++){
		V[i] = rand() % 10000;
	}
	
	imprimir();
	
	clock_t inicio = clock();
	
	insertionSort(V,10000);
	
	clock_t fim = clock();
	
	printf("\n--------Vetor ordenado--------\n");
	
	imprimir();
	
	printf("\nTempo de execucao: %f segundos\n",(double)(fim - inicio) / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}
