#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int V[10000];

void troca(int *a, int *b) {
	int aux = *a;
    *a = *b;
    *b = aux;
}

void selectionSort(int *V, int tamanho){
	int i, j, menor;
	for(i = 0;i<tamanho-1;i++){
		menor = i;
		for(j = i+1; j<tamanho ;j++){
			if(V[j]<V[menor]){
				menor = j;
			}
		}
		if(i != menor){
			troca(&V[i],&V[menor]);
		}
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
	
	selectionSort(V,10000);
	
	clock_t fim = clock();
	
	printf("\n--------Vetor ordenado--------\n");
	
	imprimir();
	
	printf("\nTempo de execucao: %f segundos\n",(double)(fim - inicio) / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}
