#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int idade;
    float altura;
}Pessoa;


void carregardados(Pessoa teste){
    FILE *ptr;

    ptr = fopen("monitoria.txt","r");

    fscanf(ptr, "%s %d %f", (teste).nome, &(teste).idade, &(teste).altura);

    fclose(ptr);
}

void salvardados(Pessoa teste){

    FILE *ptr;

    ptr = fopen("monitoria.bin","wb");

    fwrite(&teste, sizeof(Pessoa), 1, ptr);

    fclose(ptr);
}


int main(){

    FILE * ptr;

    ptr = fopen("monitoria.bin", "rb");

    Pessoa teste;

    fread(&teste,sizeof(Pessoa),1,ptr);

    printf("%s %d %f", teste.nome, teste.idade, teste.altura);

    //carregardados(&teste);
    //salvardados(teste);

    return 0;
}