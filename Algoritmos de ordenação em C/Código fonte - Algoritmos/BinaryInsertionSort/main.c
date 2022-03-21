#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int V[10000];

int buscaBinaria(int *V,int i, int menor, int maior){
	while (menor <= maior) {
        int meio = menor + (maior - menor) / 2;
        if (i == V[meio])
            return meio + 1;
        else if (i > V[meio])
            menor = meio + 1;
        else
            maior = meio - 1;
    }
 
    return menor;
}

void binaryInsertionSort(int *V,int tamanho){
	int i, loc, j, k, selected;
 
    for (i = 1; i < tamanho; ++i) {
        j = i - 1;
        selected = V[i];
 
        // acha a localização onde o selected deveria ser inserido
        loc = buscaBinaria(V, selected, 0, j);
 
        // move todos os elementos depois do selected pra dar espaço
        while (j >= loc) {
            V[j + 1] = V[j];
            j--;
        }
        V[j + 1] = selected;
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
	
	binaryInsertionSort(V,10000);
	
	clock_t fim = clock();
	
	printf("\n--------Vetor ordenado--------\n");
	
	imprimir();
	
	printf("\nTempo de execucao: %f segundos\n",(double)(fim - inicio) / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}
