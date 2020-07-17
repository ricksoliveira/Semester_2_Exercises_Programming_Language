#include <stdio.h>
#include <string.h>

typedef struct Pessoa{
	int rg;
	int cpf;
	char nome[80];
}Pessoa;

void ordenaRG(Pessoa v[], int n);
int buscaRG(Pessoa v[], int n);

int main(){
	
	Pessoa cadastro [100];
	int i, k, ret;
	
	scanf("%d", &k);
	printf("\n");
	
	for(i=0; i<k; i++){
		printf("nome: ");
		getchar();
		fgets(cadastro[i].nome, 80, stdin);
		cadastro[i].nome[strlen(cadastro[i].nome) - 1] = '\0';
		printf("RG: ");
		scanf("%d", &cadastro[i].rg);
		printf("CPF: ");
		scanf("%d", &cadastro[i].cpf);
		printf("\n\n");
	}
	
	ordenaRG(cadastro, k);
	ret = buscaRG(cadastro, k);
	
	if(ret == -1) printf("\n%d", ret);
	else printf("\nRG no indice %d", ret);
	
}

void ordenaRG(Pessoa v[], int n){
	
	int i, j;
	Pessoa temp;
	
	for(j=0; j<n; j++){
		for(i=0; i<n; i++){
			if((v[i].rg > v[i+1].rg) && i+1 < n){
				temp = v[i+1];
				v[i+1] = v[i];
				v[i] = temp;
			}
		}
	}
}

int buscaRG(Pessoa v[], int n){
	
	int i, j, num, retorno;
	retorno = -1;
	
	scanf("%d", &num);
	
	for(i=0; i<n; i++){
		if(v[i].rg == num){
			retorno = i;
			break;
		}
	}
	
	return retorno;
	
}
