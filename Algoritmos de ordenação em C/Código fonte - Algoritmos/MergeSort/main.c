#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int V[10000];

void merge(int *V, int inicio, int meio, int fim){
	int *vAUX,p1,p2,tamanho,i,j,k;
	int fim1 = 0, fim2 = 0;
	tamanho = fim - inicio + 1;
	p1 = inicio;
	p2 = meio+1;
	vAUX = (int *) malloc(tamanho*sizeof(int));
	if(vAUX != NULL){
		for(i=0;i<tamanho;i++){
			if(!fim1 && !fim2){
				if(V[p1] < V[p2]){
					vAUX[i] = V[p1++];
				} else{
					vAUX[i] = V[p2++];
				}
				if(p1>meio) fim1 = 1;
				if(p2>fim) fim2 = 1; 
			}
			else{
				if(!fim1){
					vAUX[i] = V[p1++];
				}
				else{
					vAUX[i] = V[p2++];
				}
			}
		}
		for(j = 0, k = inicio; j<tamanho; j++, k++){
			V[k] = vAUX[j];
		}
	}
	free(vAUX);
}

void mergeSort(int *V, int inicio, int fim){
	int meio;
	if(inicio<fim){
		meio = floor((inicio+fim)/2);
		mergeSort(V,inicio,meio);
		mergeSort(V,meio+1,fim);
		merge(V,inicio,meio,fim);	
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
	
	mergeSort(V,0,10000);
	
	clock_t fim = clock();
	
	printf("\n--------Vetor ordenado--------\n");
	
	imprimir();
	
	printf("\nTempo de execucao: %f segundos\n",(double)(fim - inicio) / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}
