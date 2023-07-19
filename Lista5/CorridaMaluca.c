#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int Dinheiro;
    int NumPeca;
}Escolha;

typedef struct{
    char pec[30];
    int valor[20];
    int performance[20];
}Pecas;

int main(){
    int naot=0;
    char Motor[]= "Motor";
    char Lataria[]= "Lataria";
    char Roda[]= "Roda";
    Escolha escolha;
    Pecas pecas [30];
    int Cache=0;
    int resto;
    int pontos=0;
    scanf("%d %d", &escolha.Dinheiro, &escolha.NumPeca);

    for(int i=0;i<escolha.NumPeca;i++){
        scanf(" %s %d %d", pecas[i].pec, &pecas->valor[i], &pecas->performance[i]);
    }

    if(escolha.NumPeca<=2){
        printf("Nao foi possivel construir uma caranga...");
    }

    else{ 
        for(int j=2;j<escolha.NumPeca;j++){
            if(strcmp(pecas[j-2].pec,Motor)==0 && strcmp(pecas[j-1].pec,Roda)==0 && strcmp(pecas[j].pec,Lataria)==0){
                naot=1;
            }
        }
        if(naot==0){
            printf("Nao foi possivel construir uma caranga...");
        }
        else{
            for(int k=0;k<3;k++){
                Cache=pecas->valor[k]+Cache;
                pontos=pontos+pecas->performance[k];
            }
            if(Cache<escolha.Dinheiro){
                resto=escolha.Dinheiro-Cache;
                printf("Minha nave tem uma performance de %d pontos\nE ainda me sobraram %d mangos!", pontos, resto);
            }
            else printf("Nao foi possivel construir uma caranga...");
        }
    }
}