#include <stdio.h>
#include<string.h>


typedef struct{
   char nome[30];
   int Comida;
   int bebida;
   int artista;
   int agregados;
}Pessoa;


int main(){
   int n;
   char Comidas[20];
   char bebidas[20];
   char artistas[30];
   int c1=0,c2=0,c3=0,c4=0,c5=0;
   int b1=0,b2=0,b3=0,b4=0,b5=0;
   int a1=0,a2=0,a3=0,a4=0,a5=0;
  
   scanf("%d",&n);
   Pessoa Votacao[n];
   for(int i=0;i<n;i++){
       scanf("%s %d %s %s %s",Votacao[i].nome,&Votacao[i].agregados,Comidas,bebidas,artistas);
       if(strcmp(Comidas,"coxinha")==0){
           Votacao[i].Comida=1;
           c1++;
       }
       if(strcmp(Comidas,"brigadeiro")==0){
           Votacao[i].Comida=2;
           c2++;
       }
       if(strcmp(Comidas,"risoto")==0){
           Votacao[i].Comida=3;
           c3++;
       }
       if(strcmp(Comidas,"picanha")==0){
           Votacao[i].Comida=4;
           c4++;
       }
       if(strcmp(Comidas,"pizza")==0){
           Votacao[i].Comida=5;
           c5++;
       }
       if(strcmp(bebidas,"agua")==0){
           Votacao[i].bebida=1;
           b1++;
       }
       if(strcmp(bebidas,"cafe")==0){
           Votacao[i].bebida=2;
           b2++;
       }
       if(strcmp(bebidas,"suco")==0){
           Votacao[i].bebida=3;
           b3++;
       }
       if(strcmp(bebidas,"monster")==0){
           Votacao[i].bebida=4;
           b4++;
       }
       if(strcmp(bebidas,"pitu")==0){
           Votacao[i].bebida=5;
           b5++;
       }
       if(strcmp(artistas,"Gustavo Mioto")==0){
           Votacao[i].artista=1;
           a1++;
       }
       if(strcmp(artistas,"Billie Eilish")==0){
           Votacao[i].artista=2;
           a2++;
       }
       if(strcmp(artistas,"Pericles")==0){
           Votacao[i].artista=3;
           a3++;
       }
       if(strcmp(artistas,"Shevchenko e Elloco")==0){
           Votacao[i].artista=4;
           a4++;
       }
       if(strcmp(artistas,"Joao Gomes")==0){
           Votacao[i].artista=5;
           a5++;
       }
   }


}

