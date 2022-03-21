#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct balde{
	int qtd;
	int valores[10000];
};

int V[10000];

void insertionSort(int *V,int tamanho){
	int i, j, aux;
	for(i=1;i<tamanho;i++){
		aux = V[i];
		for(j=i;(j>0) && (aux < V[j - 1]);j--){
			V[j] = V[j-1];
		}
		V[j] = aux;
	}
}

void bucketSort(int *V,int tamanho){
	int i,j,maior,menor,nBaldes,pos;
	struct balde *b;
	
	maior = menor = V[0];
	for(i=0;i<tamanho;i++){
		if(V[i]>maior){
			maior = V[i];
		}
		if(V[i]<menor){
			menor = V[i];
		}
	}
	
	nBaldes = (maior - menor) /100+1;
	b = (struct balde *) malloc(nBaldes * sizeof(struct balde));
	for(i=0; i<nBaldes;i++){
		b[i].qtd =0;
	}
	
	for(i=0;i<tamanho;i++){
		pos = (V[i] - menor)/100;
		b[pos].valores[b[pos].qtd] = V[i];
		b[pos].qtd++;
	}
	pos = 0;
	for(i=0;i<nBaldes;i++){
		insertionSort(b[i].valores,b[i].qtd);
		for(j=0;j<b[i].qtd;j++){
			V[pos] = b[i].valores[j];
			pos++;
		}
	}
	free(b);
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
	
	bucketSort(V,10000);
	
	clock_t fim = clock();
	
	printf("\n--------Vetor ordenado--------\n");
	
	imprimir();
	
	printf("\nTempo de execucao: %f segundos\n",(double)(fim - inicio) / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}
