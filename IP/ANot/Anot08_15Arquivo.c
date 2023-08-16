#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Bib.h"

int main() {
    float vet[]={13,25,33,44,56}, *dVet;
    int tamV,i;
    FILE *arq;
    if((arq=fopen("test.bin","r+"))!=NULL) {
        dVet = carregaVetor(arq, &tamV);
        printf("Apos a carga inicial\n");
        printVetor(dVet, tamV);
        if(dVet!=NULL) {
            dVet = inserirVetor(dVet, &tamV, vet, 5);
            printf("Apos a insercao\n");
            printVetor(dVet, tamV);
            salvaVetor(arq, dVet, tamV);
        }
        free(dVet);
        fclose(arq);
    }
    return 0;
}