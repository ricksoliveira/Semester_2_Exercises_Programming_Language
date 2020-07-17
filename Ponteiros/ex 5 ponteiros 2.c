#include <stdio.h>

int primo(int n, int *p1, int *p2);

int main(){
	
	int num, maiorantes, menordepois;
	
	scanf("%d", &num);
	
	primo(num, &maiorantes, &menordepois);
	
	printf("%d\n%d", maiorantes, menordepois);
	
}

int primo(int n, int *p1, int *p2){
	
	int candidato=2, primosachados=0, div, eprimo, subs;
	subs = n;
	
	while(primosachados<1){
		div=2;
		eprimo=1;
		
		while(div<n/2){
			if(n%div==0){
				eprimo=0;
			}
			div++;
		}
		if(eprimo==1){
			*p1 = n;
			primosachados++;
		}
		n--;
	}
	
	primosachados=0;
	
	while(primosachados<1){
		div=2;
		eprimo=1;
		
		while(div<subs/2){
			if(subs%div==0){
				eprimo=0;
			}
			div++;
		}
		if(eprimo==1){
			*p2 = subs;
			primosachados++;
		}
		subs++;
	}
	
}
