#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    FILE *ptr;

    char palavra[50];
    ptr=fopen("monitoria.txt","a+");

    /*Write-> ela vai escrever e apagar tudo que estava antes
    read-> ela vai ler o arquivo e apenas isso
    append->escrever no arquivo e manter o que estava la

    printf("Digite uma palavra\n");
    scanf(" %s",palavra);

    fprintf(ptr,"%s\n",palavra);//mermo do printf sendo que o arquivo vem antes, simplesmente*/

    //fscanf(ptr," %[^,],")lê ate a virgula;
    fscanf(ptr," %[^\n]\n", palavra); //mesmo caso do fprintf
    printf("%s\n",palavra);

    scanf(" %s",palavra);
    fprintf(ptr,"%s\n",palavra);

    fscanf(ptr," %[^\n]\n", palavra);
    printf("%s\n",palavra); 
    

    fclose(ptr);//tem que dar fclose
    
    //fscanf e fprintf pra txt resolve muita coisa,fgets eh uma boa também
}