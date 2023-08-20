#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int vetorpordentro[10];
}Candidatos;

int main(){

    FILE *ptr;

    char palavra[50];
    //Candidatos vetor[10];//fazer com vetor de struct
    ptr=fopen("monitoria.bin","rb");

    //for(int i=0;i<10;i++){
    //    scanf("%d",&vetor[i]);
    //}
    //fwrite(&vetor,sizeof(int),10,ptr);
    fread(&vetor,sizeof(int),10,ptr);

    for(int i=0;i<10;i++){
        printf("%d\n",vetor[i]);
    }
    //if tamtamtam ==NULL


    fclose(ptr);//tem que dar fclose
    
}