#include <stdio.h>

int main(){
	
	FILE *arq;
	char *texto, nome[100], letra;
	int tam=0, i=0;
	
	printf("digite o nome: ");
	scanf("%s", nome);
	arq = fopen(nome, "r+");
	
	if(arq == NULL){
		printf("\nerro");
		return 3880;
	}
	
	while(fscanf(arq, "%c", &letra) != EOF){
		tam++;
	}
	rewind(arq);
	
	texto = malloc((tam+1) * sizeof(char));
	
	while(fscanf(arq, "%c", &letra) != EOF){
		texto[i] = letra;
		i++;
	}
	rewind(arq);
	
	texto[i] = '\0';
	printf("%s\n\n", texto);
	
	i=0;
	while(texto[i] != '\0'){
		if(texto[i] == 'a'){
			texto[i] = 'A';
		}
		fprintf(arq, "%c", texto[i]);
		i++;
	}
	
	printf("%s", texto);
	
	free(texto);
	fclose(arq);
	
}
