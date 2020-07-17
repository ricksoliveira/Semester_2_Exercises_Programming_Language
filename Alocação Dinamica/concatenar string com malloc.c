#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * concatena(char *s1, char *s2, int t1, int t2);

int main(){
	
	char *f1, *f2, *f3;
	int n1, n2;
	
	scanf("%d", &n1);
	scanf("%d", &n2);
	
	f1 = malloc((n1+1) * sizeof(char));
	f2 = malloc((n2+1) * sizeof(char));
	
	fflush(stdin);
	fgets(f1, n1+1, stdin);
	fflush(stdin);
	fgets(f2, n2+1, stdin);
	
	f3 = concatena(f1, f2, n1, n2);
	
	printf("\n%s", f3);
	
	free(f1);
	free(f2);
	free(f3);
}

char * concatena(char *s1, char *s2, int t1, int t2){
	
	char *s3;
	int i;

	s3 = malloc((t1+t2+1)*sizeof(char));
	
	for(i=0; i<t1; i++){
		s3[i] = s1[i];
	}
	for(i=0; i<t2; i++){
		s3[t1+i] = s2[i];
	}
	s3[t1+t2] = '\0';
	
	return s3;
}
