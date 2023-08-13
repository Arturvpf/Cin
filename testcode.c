#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void ordem_crescente(int vetor[],int n);
int main(){
    int vetor[]={4,7,1,3,7,4,7,9,0};
    ordem_crescente(vetor,9);
    for(int i=0;i<9;i++){
        printf("%d\n",vetor[i]);
    }
}
void ordem_crescente(int vetor[],int n){
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            if(vetor[j-1]>vetor[j]){
                int aux=vetor[j];
                vetor[j]=vetor[j-1];
                vetor[j-1]=aux;
            }
        }
    }

}
/*
i=0;
while(*copiardaqui+i!='\0'){
*(colaraqui+i)= *(copiardaqui+i);
i++
}
*/
