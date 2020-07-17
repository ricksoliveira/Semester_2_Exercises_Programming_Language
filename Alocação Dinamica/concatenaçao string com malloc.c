#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatena(char *s1, char *s2);

int main(){
	
	char *f1, *f2, *f3;
	int n1, n2, i;
	
	scanf("%d", &n1);
	scanf("%d", &n2);
	
	f1 = malloc((n1+1) * sizeof(char));
	f2 = malloc((n2+1) * sizeof(char));
	
	fflush(stdin);
	fgets(f1, n1+1, stdin);
	f1[n1] = '\0';
	fflush(stdin);
	fgets(f2, n2+1, stdin);
	f2[n2] = '\0';
	
	f3 = concatena(f1, f2);
	
	printf("\n%s", f3);
	
	free(f1); free(f2); free(f3);
	
}

char * concatena(char *s1, char *s2){
	
	int i, tam1, tam2;
	char *s3;
	
	tam1 = strlen(s1);
	tam2 = strlen(s2);
	
	s3 = malloc((tam1+tam2+1) * sizeof(char));
	
	for(i=0; i<tam1; i++){
		s3[i] = s1[i];
	}
	for(i=0; i<tam2; i++){
		s3[tam1+i] = s2[i];
	}
	s3[tam1+tam2] = '\0';
	
	return s3;
}
