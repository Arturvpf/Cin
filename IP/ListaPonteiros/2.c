#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int vet[5] = {1,2,3,4,5};
    int *p=vet;

    printf("A)Endereco de vet%p\nEndereco de p:%p\n",vet,p);
    printf("\nB)");
        for(int i=0;i<5;i++){
            printf("p[%d]:%d\n",i+1,p[i]);
        }
    printf("\nC)");
        for(int i=0;i<5;i++){
            printf("p[%d]:%d\n",i+1,*(p+i));
        }
    printf("\nD)");
        for(int i=0;i<5;i++){
            printf("vet[%d]:%d\n",i+1,vet[i]);
        }
        printf("\n");
        for(int i=0;i<5;i++){
            printf("vet[%d]:%d\n",i+1,*(vet+i));
        }
}