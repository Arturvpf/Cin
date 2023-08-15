#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Bib.h"

void salvaVetor(float *dVet,int tam){
    FILE *arq;
    if((arq=fopen("test.bin","w"))!=NULL){
        fwrite(&tam,sizeof(int),1,arq);
        fwrite(dVet,sizeof(float),tam,arq);
        fclose(arq);
    }
}
float* carregaVetor(int* tam){
    FILE *arq;
    float* uai=NULL;
    if((arq=fopen("test.bin","r"))!=NULL){
        fread(tam,sizeof(int),1,arq);
        uai=(float *)malloc(sizeof(float)*(*tam));
        if(uai==NULL){
            printf("erro de aloc");
            exit(1);
            fread(uai,sizeof(float),*tam,arq);
            fclose(arq);
        }
        
    }
    return uai;
}
float* inserirVetor(float *dVet,int *tamDV,float *vet, int tamV){
    dVet=(float *) realloc(dVet,sizeof(float)*((*tamDV)+tamV));
    if(dVet==NULL){exit(1);}
        for(int i=0;i<tamV;i++){
            dVet[(*tamDV)+i]=vet[i];
        }
        tamDV+=tamV;
}
void printVetor(float *dVet,int tam){
    for(int i=0;i<tam;i++){
        printf("vetor:%f",dVet[i]);
    }
}
int main(){
    float vet[]={13,25,33,44,56};
    float *dVet;
    int tamV;

    dVet=carregaVetor(&tamV);
    if(dVet!=NULL){
        dVet=inserirVetor(dVet,&tamV,vet,5);
        salvaVetor(dVet,tamV);
    }
    printVetor(dVet,tamV);
}