#include<stdio.h>
#include<string.h>


typedef struct{
    char titulo[20];
    int estado;
    char estrelas[20];
}CD;

typedef struct{
    char Nome[20];
    int Album;
    CD CD[Album];
}artistas;

int main(){
    int n;
    

    scanf("%d",&n);
    artistas artista[n];
    for(int i=0;i<n;i++){
        scanf("%s",artista[i].Nome);
        scanf("%d",&artista[i].Album);
        for(int j=0;j<artista[i].Album;j++){
            Albuns
        }
    }
}