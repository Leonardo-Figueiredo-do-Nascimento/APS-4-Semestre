#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int V[100];

int particao(int *V, int inicio, int fim){
	int E, D, pivot, aux;
	E = inicio;
	D = fim;
	pivot = V[inicio];
	
	while(E<D){
		//faz a busca pra encontrar se tem um numero maior que o pivot a sua esquerda
		while(V[E] <= pivot && E <= fim){
			E++;
		}
		
		//faz a busca pra encontrar se tem um numero menor que o pivot a sua direita
		while(V[D] > pivot && D >= 0){
			D--;
		}
		
		if(E<D){
			aux = V[E];
			V[E] = V[D];
			V[D] = aux;
		}
	}
	
	//Após a ultima troca, o elemento da direita troca de posição com o pivot
	V[inicio] = V[D];
	V[D] = pivot;
	return D; 
}

void quicksort(int *V,int E, int D){
	int pivot;
	if(E < D){
		//acha o pivot
		pivot = particao(V,E,D);
		//ordena tudo da esquerda do pivot
		quicksort(V,E,pivot-1);
		//ordena tudo da direita do pivot
		quicksort(V,pivot+1,D);
	}
}

void imprimir(){
	for(int i = 0;i<100;i++){
		printf("\nV[%d]: %d",i+1,V[i]);
	}
}
int main() {
	
	for(int i = 0;i<100;i++){
		V[i] = rand() % 100;
	}
	
	imprimir();

	clock_t inicio = clock();
	quicksort(V,0,100);
	clock_t fim = clock();
	
	printf("\n--------Vetor ordenado--------\n");
	
	imprimir();
	
	printf("\nTempo de execucao: %f segundos\n",(double)(fim - inicio) / CLOCKS_PER_SEC);
	
	return 0;
}
