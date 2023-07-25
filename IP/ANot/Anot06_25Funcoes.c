#include <stdio.h>
#include <stdlib.h>
int *preenche(int tam);
int main(){
	int *vet;
	vet=preenche(5);
	for(int i=0;i<5;i++)
	printf("%d",vet[i]);
	free(vet);
}

int *preenche(int tam){
	int *vet;
	if((vet=(int *) malloc(sizeof(int)*tam))==NULL){
		exit(1);
	}
	for(int i=0;i<tam;i++){
		scanf("%d",&vet[i]);
	}
	
	return vet;
}