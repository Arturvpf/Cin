#include <stdio.h>
#include<stdlib.h>

float mediaV(int *vet,int tam){
	float soma=0;
	for(int i=0;i<tam;i++) soma+=vet[i];
	return soma/tam;
}
void melhores(int vet[5], float media){
	for(int i=0;i<5;i++) if(vet[i]>=media) printf("%d",vet[i]);
}

int main(){
	int i,v[5];
	for(i=0;i<5;i++){
		scanf("%d",&v[i]);
	}
	float media=mediaV(v,5);
	melhores(v,media);
}