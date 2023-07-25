#include <stdio.h>
#include<stdlib.h>

void preenchev(int *v,int tam){
	int i;
	for(i=0;i<tam;i++){
		printf("Digite o elemento %d",i+1);
		scanf("%d",&v[i]);
	}
}

int main(){
	int v[5],w[15],i;
	float media;
	preenchev(v,5);
	preenchev(w,15);
}