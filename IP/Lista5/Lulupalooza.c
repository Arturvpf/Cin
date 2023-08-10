#include <stdio.h>
#include<string.h>

typedef struct{
    char Comidas[20];
    char bebidas[20];
    char artistas[30];
    int c[5]={0,0,0,0,0};
    int b[5]={0,0,0,0,0};
    int a[5]={0,0,0,0,0};
}Favorito;

typedef struct{
   char nome[30];
   int Comida;
   int bebida;
   int artista;
   int agregados;
}Pessoa;


int main(){
   int n;
   
   char comidafav[20];
   char bebidafav[20];
   char artistasfav[30];
  
   scanf("%d",&n);
   Favorito Favorito;
   Pessoa Votacao[n];
   char convidadovip[n][30];

   for(int i=0;i<n;i++){
       scanf(" %s %d %s %s %[\n]",Votacao[i].nome,&Votacao[i].agregados,Favorito.Comidas,Favorito.bebidas,Favorito.artistas);
       if(strcmp(Favorito.Comidas,"coxinha")==0){
        Favorito.c[0]++;
        Votacao[i].Comida=0;
       }
       if(strcmp(Favorito.Comidas,"brigadeiro")==0){
        Favorito.c[1]++;
        Votacao[i].Comida=1;
       }
       if(strcmp(Favorito.Comidas,"risoto")==0){
        Favorito.c[2]++;
        Votacao[i].Comida=2;
       }
       if(strcmp(Favorito.Comidas,"picanha")==0){
        Favorito.c[3]++;
        Votacao[i].Comida=3;
       }
       if(strcmp(Favorito.Comidas,"pizza")==0){
        Favorito.c[4]++;
        Votacao[i].Comida=4;
       }
       if(strcmp(Favorito.bebidas,"agua")==0){
        Favorito.b[0]++;
        Votacao[i].bebida=0;
       }
       if(strcmp(Favorito.bebidas,"cafe")==0){
        Favorito.b[1]++;
        Votacao[i].bebida=1;
       }
       if(strcmp(Favorito.bebidas,"suco")==0){
        Favorito.b[2]++;
        Votacao[i].bebida=2;
       }
       if(strcmp(Favorito.bebidas,"monster")==0){
        Favorito.b[3]++;
        Votacao[i].bebida=3;
       }
       if(strcmp(Favorito.bebidas,"pitu")==0){
        Favorito.b[4]++;
        Votacao[i].bebida=4;
       }
       if(strcmp(Favorito.artistas,"Gustavo Mioto")==0){
        Favorito.a[0]++;
        Votacao[i].artista=0;
       }
       if(strcmp(Favorito.artistas,"Billie Eilish")==0){
        Favorito.a[1]++;
        Votacao[i].artista=1;
       }
       if(strcmp(Favorito.artistas,"Pericles")==0){
        Favorito.a[2]++;
        Votacao[i].artista=2;
       }
       if(strcmp(Favorito.artistas,"Shevchenko e Elloco")==0){
        Favorito.a[3]++;
        Votacao[i].artista=3;
       }
       if(strcmp(Favorito.artistas,"Joao Gomes")==0){
        Favorito.a[4]++;
        Votacao[i].artista=4;
       }
    }
    for(int i=0;i<5;i++){
        for(int j=1;j<5;j++){
            if(Favorito.c[j]>Favorito.c[j-1]){
                int aux=Favorito.c[j];
                Favorito.c[j]=Favorito.c[j-1];
                Favorito.c[j-1]=aux;
            }
        }
    }
    for(int i=0;i<5;i++){
        for(int j=1;j<5;j++){
            if(Favorito.b[j]>Favorito.b[j-1]){
                int aux=Favorito.b[j];
                Favorito.b[j]=Favorito.b[j-1];
                Favorito.b[j-1]=aux;
            }
        }
    }
    for(int i=0;i<5;i++){
        for(int j=1;j<5;j++){
            if(Favorito.a[j]>Favorito.a[j-1]){
                int aux=Favorito.a[j];
                Favorito.a[j]=Favorito.a[j-1];
                Favorito.a[j-1]=aux;
            }
        }
    }

    if
}

