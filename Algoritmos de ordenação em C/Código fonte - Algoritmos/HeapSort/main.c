#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int V[1000];

void troca(int *a, int *b) {
	int aux = *a;
    *a = *b;
    *b = aux;
}

//Estruturar vetor como árvore binária
void heapify(int *V,int n, int i){
	int pai = i;
    int filhoE = 2 * i + 1;
    int filhoD = 2 * i + 2;
  
    //Se o filho da esquerda é maior que o pai
    if (filhoE < n && V[filhoE] > V[pai])
      pai = filhoE;
  
    //Se o filho da direita é maior que o pai
    if (filhoD < n && V[filhoD] > V[pai])
      pai = filhoD;
  
   
    if (pai != i) {
      troca(&V[i], &V[pai]);
      //faz o heapify recursivamente nos filhos
      heapify(V, n, pai);
    }
}

void heapsort(int *V, int n){

	for (int i = n / 2 - 1; i >= 0; i--)
      heapify(V, n, i);
	
	for (int i = n - 1; i >= 0; i--) {
      troca(&V[0], &V[i]); 
  
      heapify(V, i,0); 
    }
}

void imprimir(){
	for(int i = 0;i<1000;i++){
		printf("V[%d]: %d\n",i+1,V[i]);
	}
}

int main() {
	for(int i = 0;i<1000;i++){
		V[i] = rand() % 1000;
	}
	
	imprimir();
	
	clock_t inicio = clock();
	
	heapsort(V,1000);
	
	clock_t fim = clock();
	
	printf("\n--------Vetor ordenado--------\n");
	
	imprimir();
	
	printf("\nTempo de execucao: %f segundos\n",(double)(fim - inicio) / CLOCKS_PER_SEC);
	return 0;
}
