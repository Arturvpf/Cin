#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct{
    char placa[6];
}Caminhao;

typedef struct{
    int codigo;
    float loc_x,loc_y;
    Caminhao *caminhao;
    int n_caminhao;
}Filial;

typedef struct{
    float origem_x,origem_y;
    float destino_x,destino_y;
}Produto;

Caminhao remover_caminhao(Filial *filiais,int codigo_filial);
Filial *cadastrar_filial(Filial *filiais, int *n_filial);
void cadastrar_caminhao(Filial *filiais,Caminhao caminhao,int codigo_filial);
void realizar_entrega(Filial *filiais,Produto produto,int n_filiais);
void imprimir_filiais(float *filiais,int n_filiais);

int main(){
    int escolha=0,codigo_filial,qtdfiliais=0;
    Filial *filial=NULL;
    Caminhao add;
    Produto new;
    while(escolha!=5){
        printf("\n=================Menu=================\n");
        printf("1.cadastrar filial\n2.cadastrar caminhao\n3.realizar entrega\n4.imprimir filiais\n5.sair\n");
        scanf("%d",&escolha);
        switch(escolha){
            case 1:filial=cadastrar_filial(filial,qtdfiliais);
                    break;
            case 2:cadastrar_caminhao(filial,add,codigo_filial);
                    break;
            case 3:realizar_entrega(filial,new,qtdfiliais);
                    break;
            case 4:imprimir_filiais(filial,qtdfiliais);
                    break;
            case 5:printf("Saindo");
                    break;
        }
    }
    free(filial);


    return 0;
}

Caminhao remover_caminhao(Filial *filiais,int codigo_filial){

}
Filial *cadastrar_filial(Filial *filiais, int *n_filial){

}
void cadastrar_caminhao(Filial *filiais,Caminhao caminhao,int codigo_filial){

}
void realizar_entrega(Filial *filiais,Produto produto,int n_filiais){

}
void imprimir_filiais(float *filiais,int n_filiais){

}