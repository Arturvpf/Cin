#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char Nome_do_aluno[101];
    char cpf_do_aluno[12];
    int qtdNotas;
    float *notas;
}Aluno;

Aluno* carregaAlunos(int *qtdAlunos);
float* leNotas(int *qtdNotas);
float* media(float *notas,int qtdNotas);
void ordena(Aluno *alunos,int qtdAlunos);
void salvaAlunos(Aluno *alunos,int qtdAlunos);

int main(){
    Aluno *alunos=NULL;
    int qtdAlunos=0;

    alunos=carregaAlunos(&qtdAlunos);
    alunos=leNotas(&alunos[i].notas);
    

    return 0;
}
Aluno* carregaAlunos(int *qtdAlunos){
    FILE *Arquivo;
    Aluno *alunos=NULL;
    char Nome[101], CPF[12];

    if((Arquivo=fopen("alunos.txt","r"))==NULL){
        exit(1);
    }
    int i=0;
    while(fscanf(Arquivo,"%[^,], %s",Nome,CPF)!=EOF){
        //formato: (Nome Do aluno), (CPF do aluno)
        (*qtdAlunos)+=1;

        Aluno *tempo=alunos;
        
        alunos=(Aluno *)realloc(alunos,sizeof(Aluno)*(*qtdAlunos));
        if(alunos==NULL){
            free(tempo);
            exit(1);
        }
        strcpy(alunos[i].Nome_do_aluno,Nome);
        strcpy(alunos[i].cpf_do_aluno,CPF);

        i++;

        
    }
    fclose(Arquivo);
    return alunos;
}
float* leNotas(int *qtdNotas){
    float nota=0;
    while(scanf("%f",&nota)>=0){

    }


}
float* media(float *notas,int qtdNotas){

}
void ordena(Aluno *alunos,int qtdAlunos){

}
void salvaAlunos(Aluno *alunos,int qtdAlunos){

}
