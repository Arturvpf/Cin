#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    FILE *file=NULL;
    file=fopen("avpf.txt","r");

    char ans[110];
    char CPF[10];

    fscanf(file,"Nome:%[^,],",ans);  //formato Nome:(Nome do aluno), CPF:(CPF do aluno)
    fscanf(file," cpf:%s\n",CPF);
    printf("eu li isso aq %s %s\n",ans,CPF);
    fscanf(file,"Nome:%[^,],",ans);
    fscanf(file," cpf:%s\n",CPF);
    printf("eu li isso aq %s %s\n",ans,CPF);
    fclose(file);
}