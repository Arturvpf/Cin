#include <stdio.h>

int main(){
    char caminho;
    int passos;
    int linha=20;
    int flag=0;

    while(flag==0){
        scanf(" %c",&caminho);
        if(caminho=='x') flag=1;
        if(flag==0){
            scanf("%d",&passos);
        }
        if(caminho=='d'){
            for(int j=0;j<linha;j++){
                printf(" ");
            }
            for(int i=0;i<passos;i++){
                printf("->");
            }
            linha+=2*passos; 
            printf("\n");
        }
        if(caminho=='e'){
            linha-=2*passos;
            for(int j=0;j<linha;j++){
                printf(" ");
            }
            for(int i=0;i<passos;i++){
                printf("<-");
            }
            printf("\n");
        }
        if(caminho=='f'){
            for(int i=0;i<passos;i++){
                for(int j=0;j<linha;j++){
                printf(" ");
            }printf("|\n");
            }
            
        }
    }
        for(int i=0;i<linha;i++) printf(" ");
        printf("x");
}
