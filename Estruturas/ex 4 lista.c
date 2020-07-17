#include <stdio.h>
#include <string.h>

typedef struct Pessoa{
	
	int rg;
	long long int cpf;
	char nome[80];
	
}Pessoa;

int buscarg(Pessoa vet[], int n);

int main(){
	
	int i, j, n, ret;
	Pessoa temp, cadastro[100];
	
	scanf("%d", &n);
	printf("\n");
	
	for(i=0; i<n; i++){
		printf("Nome: ");
		getchar();
		fgets(cadastro[i].nome, 80, stdin);
		cadastro[i].nome[strlen(cadastro[i].nome) - 1] = '\0';
		printf("RG: ");
		scanf("%d", &cadastro[i].rg);
		printf("CPF: ");
		scanf("%lld", &cadastro[i].cpf);
		printf("\n");
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if((cadastro[j].rg > cadastro[j+1].rg) && j+1 < n){
				temp = cadastro[j+1];
				cadastro[j+1] = cadastro[j];
				cadastro[j] = temp;
			}
		}
	}
	
	ret = buscarg(cadastro, n);
	printf("RG esta no indice: %d", ret);
}

int buscarg(Pessoa vet[], int n){
	
	int i, j, k, busca, retorno = -1;
	
	printf("\nProcurar por RG: ");
	scanf("%d", &busca);
	
	for(i=0; i<n; i++){
		if(busca == vet[i].rg){
			retorno = i;
			break;
		}
	}
	
	return retorno;
	
}
