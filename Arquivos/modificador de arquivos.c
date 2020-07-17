#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(){
	
	FILE *arquivo;
	char frase[100], letra, nomeArq[100], mod[1000];
	int tam, i, opcao, reiniciar, ctz;
	
	do{
		setlocale(LC_ALL, "Portuguese");
		system("cls");
		printf("Digite o nome do arquivo que deseja abrir: ");	// usuário especifica o arquivo desejado
		scanf("%s", nomeArq);
		
		arquivo = fopen(nomeArq, "r");	// abre o arquivo desejado pelo usuário
		
		if(arquivo == NULL){	// verifica se o arquivo digitado existe, encerra o programa se não
			printf("\nArquivo inexistente.\n");
			printf("Certifique-se de ele existe e foi digitado corretamente.\n");
			printf("\nExemplo de digitacao correta: nome_do_arquivo.txt\n\n\n");
			system("pause");
			return 0;
		}
		
		printf("\n\nConteudo original do arquivo:\n\n");	// exibe na tela o conteúdo do arquivo ANTES da alteração
		while(fscanf(arquivo, "%c", &letra) != EOF){
			printf("%c", letra);
		}
		rewind(arquivo);
		fclose(arquivo);
		
		printf("\n\n\n---------------\n");	// escolha da alteração a ser feita
		printf("Digite qual modificacao deseja fazer no arquivo\n\n");
		printf("\t[1] - Alterar completamente\n");
		printf("\t[2] - Adicionar uma linha\n ");
		printf("\t[3] - Sair do programa\n\t ");
		scanf("%d", &opcao);
		
		switch(opcao){
			
			case 1:
				
				printf("\n---------------\n");	// confirmaçao de que os arquivos serao apagados, encerra o programa se não
				printf("\nO conteudo do arquivo sera APAGADO.\n");
				printf("Tem certeza que quer continuar?.\n");
				printf("\n\t[1] - Continuar.\n");
				printf("\t[Outro Numero] - Sair do programa.\n\t");
				scanf("%d", &ctz);
				
				if(ctz == 1){
					arquivo = fopen(nomeArq, "w");	// reabre o arquivo para apagar os dados dele
				}else if(ctz != 1){
					return 0;
				}
				
				printf("\n---------------\n");
				printf("Digite qual modificacao deseja fazer: \n\n");
				fflush(stdin);
				fgets(mod, 1000, stdin);	// usuário digita a modificação desejada
				tam = strlen(mod);
				mod[tam-1] = '\0';	
				
				for(i=0; mod[i] != '\0'; i++){		// troca o conteúdo do arquivo pela modificação
					fprintf(arquivo, "%c", mod[i]);
				}
				
				system("cls");
				printf("\n---------------\n");
				printf("Arquivo foi alterado com sucesso!\n");
				
				fclose(arquivo);
				break;
				
			case 2:
				
				printf("\n---------------\n");
				printf("Digite qual linha deseja adicionar: \n\n");
				fflush(stdin);
				fgets(mod, 1000, stdin);	// usuário digita a modificação desejada
				tam = strlen(mod);
				mod[tam-1] = '\0';
				
				arquivo = fopen(nomeArq, "a");	// reabre o arquivo para adicionar uma linha
				
				fprintf(arquivo, "\n");
				for(i=0; mod[i] != '\0'; i++){		// adiciona a linha digitada
					fprintf(arquivo, "%c", mod[i]);
				}
				
				system("cls");
				printf("\n---------------\n");
				printf("\nLinha adicionada com sucesso!\n");
				
				fclose(arquivo);
				break;
			
			case 3:
				return 0;
			
			default:
				printf("\nVoce deve escolher apenas as opcoes 1, 2 ou 3.\n");
				break;
		}
		
		printf("\n---------------\n");		// menu para reinicialização do programa, encerra o programa se não
		printf("Deseja fazer outra alteracao?\n\n");
		printf("\t[1] - Reiniciar o programa.\n");
		printf("\t[Outro Numero] - Sair do programa.\n");
		printf("\t\t");
		scanf("%d", &reiniciar);
		
	}while(reiniciar == 1);
}
