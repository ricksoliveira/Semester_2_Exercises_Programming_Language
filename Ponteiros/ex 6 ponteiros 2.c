#include <stdio.h>

double media(double vet[], int n, int *i);

int main(){
	
	int tam, k, proximo;
	double v[100], med;
	
	scanf("%d", &tam);
	printf("\n");
	for(k=0; k<tam; k++){
		scanf("%lf", &v[k]);
	}
	
	med = media(v, tam, &proximo);
	printf("\n\nmedia: %.3lf", med);
	printf("\n\nindice do mais proximo: %d", proximo);
	
}

double media(double vet[], int n, int *i){
	
	int k, j, ind;
	double acu=0, dist[100], aux;
	
	for(k=0; k<n; k++){
		acu = acu + vet[k];
	}
	acu = acu/n;
	
	for(k=0; k<n; k++){
		dist[k] = acu - vet[k];
		if(dist[k] < 0) dist[k] = dist[k] * (-1);
	}
	aux = dist[0];
	
	for(k=0; k<n; k++){
		if(aux > dist[k]){
			aux = dist[k];
			ind = k;
		}
	}
	
	*i = ind;
	return acu;
	
}
