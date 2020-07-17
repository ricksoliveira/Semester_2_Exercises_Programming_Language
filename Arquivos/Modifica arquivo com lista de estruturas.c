#include <stdio.h>
#include <string.h>

typedef struct Aluno{
	char nome[100];
	int RA;
}Aluno;

void imprimeArquivo(char nomeArq[]);
void alteraNome(char nomeArq[], int ra, char nome[]);

int main(){
	
	char nomeArq[] = "alunos.bin";
	Aluno alunos[] = {{"Batata", 1}, {"Isabela", 2}, {"Malu", 3}, {"Beto", 4}};
	FILE *arq = fopen(nomeArq, "w+b");
	
	if(arq == NULL){
		printf("erro\n"); return 1;
	}
	
	fwrite(alunos, sizeof(Aluno), 4, arq);
	fclose(arq);
	
	imprimeArquivo(nomeArq);
	alteraNome(nomeArq, 2, "Isabela");
	imprimeArquivo(nomeArq);
	
}

void imprimeArquivo(char nomeArq[]){
	
	FILE *arq = fopen(nomeArq, "r+b");
	
	if(arq == NULL){
		printf("erro");
		return;
	}
	
	printf("\n----- Dados do Arquivo -----\n");
	Aluno aux;
	while(fread(&aux, sizeof(Aluno), 1, arq) != 0){
		printf("Nome: %s, RA: %d\n", aux.nome, aux.RA);
	}
	
	fclose(arq);
	
}

void alteraNome(char nomeArq[], int ra, char nome[]){
	
	FILE *arq = fopen(nomeArq, "r+b");
	
	if(arq == NULL){
		printf("erro"); return;
	}
	Aluno aux; int achou=0;
	while(fread(&aux, sizeof(Aluno), 1, arq) != 0){
		if(aux.RA == ra){
			achou = 1;
			break;
		}
	}
	
	if(achou){
		fseek(arq, -1 * sizeof(Aluno), SEEK_CUR);
		strcpy(aux.nome, nome);
		fwrite(&aux, sizeof(Aluno), 1, arq);
	}
	
	fclose(arq);
	
}
