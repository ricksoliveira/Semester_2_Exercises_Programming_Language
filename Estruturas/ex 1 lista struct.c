#include <stdio.h>
#include <string.h>

typedef struct Produto{
	char nome[80];
	double preco;
	int quantidade;
}Produto;

void ordenaPreco(Produto vet[], int n);
void ordenaQuant(Produto vet[], int n);

int main(){
	
	int n, i;
	Produto produtos[80];
	
	scanf("%d", &n);
	printf("\n");
	
	for(i=0; i<n; i++){
		printf("Nome: ");
		getchar();
		fgets(produtos[i].nome, 80, stdin);
		produtos[i].nome[strlen(produtos[i].nome) - 1] = '\0';
		printf("Preco: ");
		scanf("%lf", &produtos[i].preco);
		printf("Quantidade: ");
		scanf("%d", &produtos[i].quantidade);
		printf("\n\n");
	}
	
	ordenaPreco(produtos, n);
	ordenaQuant(produtos, n);
	
}

void ordenaPreco(Produto vet[], int n){
	
	int i, j;
	Produto temp;
	
	for(j=0; j<n; j++){
		for(i=0; i<n; i++){
			if((vet[i].preco > vet[i+1].preco) && i+1 < n){
				temp = vet[i+1];
				vet[i+1] = vet[i];
				vet[i] = temp;
			}
		}
	}
	
	printf("----- LISTA DE PRODUTOS ORDENADOS POR PRECO ");
	
	for(i=0; i<n; i++){
		printf("-----\n\n");
		printf("Nome: %s", vet[i].nome);
		printf("\nPreco: %.2lf reais", vet[i].preco);
		printf("\nQuantidade: %d", vet[i].quantidade);
		printf("\n\n\n");
	}
	
}

void ordenaQuant(Produto vet[], int n){
	
	int i, j;
	Produto temp;
	
	for(j=0; j<n; j++){
		for(i=0; i<n; i++){
			if((vet[i].quantidade > vet[i+1].quantidade) && i+1 < n){
				temp = vet[i+1];
				vet[i+1] = vet[i];
				vet[i] = temp;
			}
		}
	}
	
	printf("----- LISTA DE PRODUTOS ORDENADOS POR QUANTIDADE ");
	
	for(i=0; i<n; i++){
		printf("-----\n\n");
		printf("Nome: %s", vet[i].nome);
		printf("\nPreco: %.2lf reais", vet[i].preco);
		printf("\nQuantidade: %d", vet[i].quantidade);
		printf("\n\n\n");
	}
	
}
