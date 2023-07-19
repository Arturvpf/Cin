#include<stdio.h>
#include<string.h>

typedef struct{
    char nome[50];
    int idade;
    float altura;
    int LetraNome;
    float AxN;
    float diferenca;
}Pessoa;

int main(){
    int n,m;
    float x;
    
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%f",&x);
    Pessoa Filho[n];
    
    
    for(int i=0;i<n;i++){
        scanf(" %s %d %f",Filho[i].nome,&Filho[i].idade,&Filho[i].altura);
        Filho[i].LetraNome=strlen(Filho[i].nome);
        Filho[i].AxN=((Filho[i].altura)*(Filho[i].idade)*(Filho[i].LetraNome));
        if(Filho[i].AxN>=x){
            Filho[i].diferenca=Filho[i].AxN-x;
        }
        else Filho[i].diferenca=x-Filho[i].AxN;
    }
    for (int i = 0; i < n ; i++) {
        for (int j = 1; j < n ; j++) {
            if (Filho[j].diferenca < Filho[j-1].diferenca) {
                float temp = Filho[j].diferenca;
                Filho[j].diferenca = Filho[j-1].diferenca;
                Filho[j-1].diferenca= temp;
                char aux[50];
                strcpy(aux,Filho[j].nome);
                strcpy(Filho[j].nome,Filho[j-1].nome);
                strcpy(Filho[j-1].nome,aux);
            }
        }
    }
    for(int i=0;i<m;i++){
        printf("%s\n",Filho[i].nome);
    }
}