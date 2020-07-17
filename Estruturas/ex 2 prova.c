#include <stdio.h>

typedef struct Cell{
	char car;
	int peso;
}Cell;

int somapeso(Cell vet[], int n){
	
	int cont=0, pesotemp=0, soma=0, i;
	
	for(i=0; i<n; i++){
		if(vet[i].car == vet[i+1].car && i+1 <= n && cont == 0){
			cont++;
			pesotemp += vet[i].peso + vet[i+1].peso;
			soma += pesotemp;
			pesotemp = 0;
			break;
		}else if(cont >= 1 && vet[i].car == vet[i+1].car && i+1 <= n){
			cont++;
			pesotemp += vet[i+1].peso;
			soma += pesotemp;
		}else if(vet[i].car != vet[i+1].car && i+1 <= n){
			cont = 0;
		}
	}
	printf("\n%d", soma);
	
}

int main(){
	
	Cell v[100];
	int x, i;
	
	scanf("%d", &x);
	
	for(i=0; i<x; i++){
		scanf("%s", &v[i].car);
		getchar();
		scanf("%d", &v[i].peso);
	}
	
	somapeso(v, x);
	
	/*for(i=0; i<x; i++){
		printf("\n%c\n", v[i].car);
		printf("%d\n\n", v[i].peso);
	}*/
	
}
