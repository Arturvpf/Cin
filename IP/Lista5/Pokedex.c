#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct{
    int Qpokemons;
    char Poke[200];
    char ElementoP[200];
    

}pok;


int main(){
    
    pok emon[3100];
    int i;
    char pokeI[20];
    char ElementoI[20];
    char agua[]="agua";
    char grama[]="grama";
    char fogo[]="fogo";
    float ataqueI;
    float defesaI;
    
    scanf(" %s %s %f %f", pokeI, ElementoI, &ataqueI, &defesaI);
    scanf("%d", &emon->Qpokemons);

    float Defesa[emon->Qpokemons];
    float Ataque[emon->Qpokemons];
    

        for(i =0 ;i<emon->Qpokemons;i++){
            scanf(" %s %s %f %f", emon[i].Poke, emon[i].ElementoP, &Ataque[i],&Defesa[i]);
        }

    for(i=0;i<emon->Qpokemons;i++){
        if(strcmp(emon[i].ElementoP,agua)==0 && strcmp(ElementoI,fogo)==0){
                Ataque[i]=Ataque[i]*1.5;
        }
        if(strcmp(emon[i].ElementoP,grama)==0 && strcmp(ElementoI,agua)==0){
                Ataque[i]=Ataque[i]*1.5;
        }
        if(strcmp(emon[i].ElementoP,fogo)==0 && strcmp(ElementoI,grama)==0){
                Ataque[i]=Ataque[i]*1.5;
        }
        if(strcmp(emon[i].ElementoP,fogo)==0 && strcmp(ElementoI,agua)==0){
                Defesa[i]=Defesa[i]-ataqueI*0.5;                
        }
        if(strcmp(emon[i].ElementoP,agua)==0 && strcmp(ElementoI,grama)==0){
                Defesa[i]=Defesa[i]-ataqueI*0.5;                
        }
        if(strcmp(emon[i].ElementoP,grama)==0 && strcmp(ElementoI,fogo)==0){
                Defesa[i]=Defesa[i]-ataqueI*0.5;                
        }
    }

    float defesai[emon->Qpokemons];
    float ataquei[emon->Qpokemons];
    
    for(i=0;i<emon->Qpokemons;i++){
       defesai[i]=Ataque[i]-defesaI;
       ataquei[i]=Defesa[i]-ataqueI;
    }
    float cache1;
  //daq pra baixo eu ordenei de forma decrescente mas falta ordernar os nomes dos pokemons com os numeros   { float cache1;
    char cache3;
    for(int x1=0; x1<i; x1++){
         for(int y1=1; y1<i; y1++){
            if (defesai[y1]>defesai[y1-1]){
                cache1=defesai[y1-1];
                strcpy(&cache3,emon[y1-1].Poke);
                defesai[y1-1]=defesai[y1];
                strcpy(emon[y1-1].Poke,emon[y1].Poke);
                defesai[y1]= cache1;
                strcpy(emon[y1].Poke,&cache3);
            }
        }
    }
    float cache2;
    char aux;
//colocar defesas iguais em ordem alfabetica
    for(int j=0;j<emon->Qpokemons;j++){
    for(i=1;i<emon->Qpokemons;i++){
        if(defesai[i]==defesai[i-1]){
              if(strcmp(emon[i-1].Poke,emon[i].Poke)>0){        
                strcpy(&aux,emon[i-1].Poke);
                strcpy(emon[i-1].Poke,emon[i].Poke);
                strcpy(emon[i].Poke,&aux);
            }
        }  
    } 
    }
    for(i=0;i<emon->Qpokemons;i++){
        printf("%d. %s\n",i+1,emon[i].Poke);
    }


return 0;
}