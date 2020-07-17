#include <stdio.h>

typedef struct Data{
	int dia;
	int mes;
	int ano;
}Data;

void ordena( Data vet[], int tam);
void troca(Data tp, Data v[], int a, int b);

int main(){
	
	int i, tam;
	Data datas[80];
	
	scanf("%d", &tam);
	printf("\n");
	
	for(i=0; i<tam; i++){
		printf("Dia: ");
		scanf("%d", &datas[i].dia);
		printf("Mes: ");
		scanf("%d", &datas[i].mes);
		printf("Ano: ");
		scanf("%d", &datas[i].ano);
		printf("\n");
	}
	
	ordena(datas, tam);
	
}

void ordena(Data vet[], int tam){
	
	int i, j;
	Data temp;
	
	for(i=0; i<tam; i++){
		for(j=0; j<tam; j++){
			if((vet[j].ano > vet[j+1].ano) && j+1 < tam){
				troca(temp, vet, i, j);
			}else if((vet[j].ano == vet[j+1].ano) && j+1 < tam){
				if((vet[j].mes > vet[j+1].mes) && j+1 < tam){
					troca(temp, vet, i, j);
				}else if((vet[j].mes == vet[j+1].mes) && j+1 < tam){
					if((vet[j].dia > vet[j+1].dia) && j+1 < tam){
						troca(temp, vet, i, j);
					}
				}
			}
		}
	}
	
	printf("\n----- DATAS EM ORDEM CRONOLOGICA -----\n");
	
	for(i=0; i<tam; i++){
		printf("\n");
		printf("%d / %d / %d", vet[i].dia, vet[i].mes, vet[i].ano);
		printf("\n");
	}
	
}

void troca(Data tp, Data v[], int a, int b){
	tp = v[b+1];
	v[b+1] = v[b];
	v[b] = tp;
}
