#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int V[10000];

void bubbleSort(int *V, int tamanho){
	int i, aux, continua;
	int fim = tamanho;
	do{
		continua = 0;
		for(i = 0; i<=fim-1;i++){
			if(V[i]>V[i+1]){
				aux = V[i];
				V[i] = V[i+1];
				V[i+1] = aux;
				continua = i;
			}
		}
		fim--;
	} while(continua != 0);
}

void imprimir(){
	for(int i = 0;i<10000;i++){
		printf("\nV[%d] = %d",i+1,V[i]);
	}
}

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	for(int i=0;i<10000;i++){
		V[i] = rand() % 10000;
	}
	
	imprimir();
	
	clock_t inicio = clock();
	
	bubbleSort(V,10000);
	
	clock_t fim = clock();
	
	
	printf("\n-----Valores ordenados-----\n");
	imprimir();

	printf("\nTempo de execucao: %f segundos\n",(double)(fim - inicio) / CLOCKS_PER_SEC);
	
	system("pause");
}

