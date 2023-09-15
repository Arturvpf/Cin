#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char nome[50];
    char raca[50];
    int idade;
    float salario;
    char CPF[12];
} Pessoa;

typedef struct {
    char nome[50];
    int codigo; 
    Pessoa* cidadaos;
    int capacidade;
} Cidade;

Cidade* NovaCidade(Cidade* censo, int* tam);
void InserirOuAtualizar(Cidade* censo, int tam);
void Remover(Cidade* censo, int tam);
void Procura(Cidade* censo, int tam);
void ViewTable(Cidade* censo, int tam);
void Desaloca(Cidade* censo, int tam);

int main(){
    Cidade *Censo=NULL;
    int tam=0,escolha,flag=0;
    Cidade *censo;

    while(flag==0){
        printf("=========MENU=========\n");
        printf("1.Adicionar uma nova cidade\n2.Inserir ou atualizar uma pessoa\n3.Remover uma pessoa\n4.Procurar por um cpf\n5.Mostrar censo\n6.Sair do menu\n");
        scanf("%d",&escolha);
        switch(escolha){
            case 1:{censo=NovaCidade(Censo, &tam);break;}
            case 2:{InserirOuAtualizar(censo,tam);break;}
            case 3:{Remover(censo,tam); break;}
            case 4:{Procura(censo,tam);break;}
            case 5:{ViewTable(censo,tam);break;}
            case 6:{printf("Saindo\n");flag=1;break;}
        }
    }
        Desaloca(Censo,tam);
    return 0;
}

Cidade *NovaCidade(Cidade* censo, int* tam){
    char nome[50];
    int codigo;
     
    printf("Informe o nome da cidade\n");
    scanf(" %s",&nome);
    printf("Informe o codigo da cidade\n");
    scanf("%d",&codigo);
    
    *tam=*tam+1;   //incrementa o conteudo do vetor dinamico censo
    Cidade *tempo=censo;//variavel temporaria para caso o realloc nao funcione

    if(*tam>0){ //testa se o valor de tam eh igual a zero para nao a locar 0 byts
        int aux=*(tam)-1;
        if((censo=(Cidade *) realloc(censo,(*tam)*sizeof(Cidade)))==NULL){ //alocar memoria e testar o caso de nao conseguir alocar memoria
            for(int i=0;i<(*tam);i++){
                free(tempo[i].cidadaos);
            }
            free(tempo);
            printf("Erro de alocacao\n");
            exit(1);
        }
        //cadastrar no censo
        strcpy(censo[aux].nome,nome);
        censo[aux].codigo=codigo;
        printf("Cadastrado\n");
    }
    return censo;
}

void InserirOuAtualizar(Cidade* censo, int tam){
    char nome[50];
    char raca[50];
    int idade;
    float salario;
    char CPF[12];
    int codigo;
    int flag=0;
    int i;
    int Atualizar=0;
    int j;
    

    printf("Informe o codigo da cidade\n");
    scanf("%d",&codigo);
    for(i=0;i<tam&&flag==0;i++){ //procurar a cidade atraves do codigo da cidade
        if(censo[i].codigo==codigo){
            flag=1;      //i sera o indice do vetor que contem a cidade informada
        }
    }
    if(flag==0){
        printf("Cidade nao encontrada\n");
    }
    else{
        //checar se o cpf ja possui dono
        
        printf("Informe o CPF da pessoa\n");
        scanf(" %s",CPF);
        
        if(censo[i].capacidade>0){     //checar se ja existe CPF 
            for(j=0;j<censo[i].capacidade&&Atualizar==0;j++){
                if(strcmp(censo[i].cidadaos[j].CPF,CPF)==0){ //j será o indice da pessoa
                    Atualizar=1;
                }
            }
            if(Atualizar==0){
                censo[i].capacidade++; 
            }
        }
        else{
            censo[i].capacidade++;
        }
        
    
        Cidade *tempo=censo; //ponteiro temporario

        if((censo[i].cidadaos=(Pessoa*) realloc(censo[i].cidadaos,censo[i].capacidade*sizeof(Pessoa)))==NULL){   //alocar e checar //tem que inicializar cidadaos como NULL?
            for(int k=0;k<tam;k++){
                free(tempo[k].cidadaos);
            }
            free(tempo);
            printf("Erro de alocacao\n");
            exit(1);
        }
        
        printf("Informe o nome da pessoa\n");
        scanf(" %s",nome);
        printf("Informe o raca da pessoa\n");
        scanf(" %s",raca);
        printf("Informe a idade da pessoa\n");
        scanf("%d",&idade);
        printf("Informe o salario da pessoa\n");
        scanf("%.2f",&salario);
        
        //atualizar ou cadastrar as informacoes  //dando erro aqui
        strcpy(censo[i].cidadaos[j].nome,nome);
        strcpy(censo[i].cidadaos[j].raca,raca);
        censo[i].cidadaos[j].idade=idade;
        censo[i].cidadaos[j].salario=salario;
        strcpy(censo[i].cidadaos[j].CPF,CPF);
    }
}
void Remover(Cidade* censo, int tam){
    int codigo;
    char CPF[12];
    int i;
    int j;
    int flag=0;
    int achei=0;

    printf("Informe o codigo da cidade\n");
    scanf("%d",&codigo);

    for(i=0;i<tam&&flag==0;i++){ //procurar a cidade atraves do codigo da cidade
        if(censo[i].codigo==codigo){
            flag=1;      //i sera o indice do vetor que contem a cidade informada
        }
    }
    if(flag==0){
        printf("cidade nao encontrada");
    }
    else{
        printf("Informe o CPF da pessoa\n");
        scanf(" %s",CPF);

        for(j=0;j<censo[i].capacidade&&achei==0;j++){
            if(strcmp(censo[i].cidadaos[j].CPF,CPF)==0){ //j será o indice da pessoa
                achei=1;
            }
        }
        if(achei==0){
            printf("CPF nao encontrado");
        }
        else{
            for(int k=j+1;k<censo[i].capacidade;k++){  //substituir esse cpf pelo proximo

                strcpy(censo[i].cidadaos[k-1].CPF,censo[i].cidadaos[k].CPF);
                strcpy(censo[i].cidadaos[k-1].nome,censo[i].cidadaos[k].nome);
                censo[i].cidadaos[k-1].idade=censo[i].cidadaos[k].idade;
                censo[i].cidadaos[k-1].salario=censo[i].cidadaos[k].salario;
                strcpy(censo[i].cidadaos[k-1].raca,censo[i].cidadaos[k].raca);
            }
            censo[i].capacidade--; //retirar essa pessoa na capacidade da cidade


            //realocar a quantidade de memoria
            Cidade *tempo=censo; //ponteiro temporario
            if(censo[i].capacidade>0){
                if((censo[i].cidadaos=(Pessoa *) realloc(censo[i].cidadaos,censo[i].capacidade*sizeof(Pessoa)))==NULL){ //checar e alocar memoria
                    for(int L=0;L<tam;L++){
                    free(tempo[L].cidadaos);
                }
                    free(tempo);
                    printf("Erro de alocacao\n");
                    exit(1);
                }
            }
            else {
                free(censo[i].cidadaos);
                censo[i].cidadaos=NULL;
            }
        }
    }

}
void Procura(Cidade* censo, int tam){
    int codigo;
    char CPF[12];
    int flag=0;
    int achei=0;
    int j;
    int i;

    printf("Informe o codigo da cidade\n");
    scanf("%d",&codigo);
    printf("Informe o CPF da pessoa\n");
    scanf(" %s",CPF);

    for(i=0;i<tam&&flag==0;i++){ //procurar a cidade atraves do codigo da cidade
        if(censo[i].codigo==codigo){
            flag=1;      //i sera o indice do vetor que contem a cidade informada
        }
    }
    for(j=0;j<censo[i].capacidade&&achei==0;j++){
        if(strcmp(censo[i].cidadaos[j].CPF,CPF)==0){ //j será o indice da pessoa
            achei=1;
        }
    }
    if(achei==0){
        printf("O CPF nao esta nessa cidade");
    }
    else{
        printf("Nome:%s\n",censo[i].cidadaos[j].nome);
        printf("Raca:%s\n",censo[i].cidadaos[j].raca);
        printf("Idade:%d\n",censo[i].cidadaos[j].idade);
        printf("Salario:%.2f\n",censo[i].cidadaos[j].salario);
        printf("CPF:%s\n\n",censo[i].cidadaos[j].CPF);
    }
}
void ViewTable(Cidade* censo, int tam){
    for(int i=0;i<tam;i++){ //cidade
        printf("Nome da cidade %s\n",censo[i].nome);
        printf("Codigo %d\n",censo[i].codigo);
        printf("Capacidade %d\n\n",censo[i].capacidade);
        for(int j=0;j<tam;j++){  //pessoa
            printf("Nome:%s\n",censo[i].cidadaos[j].nome);
            printf("Raca:%s\n",censo[i].cidadaos[j].raca);
            printf("Idade:%d\n",censo[i].cidadaos[j].idade);
            printf("Salario:%.2f\n",censo[i].cidadaos[j].salario);
            printf("CPF:%s\n\n",censo[i].cidadaos[j].CPF);
        }
    }
}
void Desaloca(Cidade* censo, int tam){
    for(int i=0;i<tam;i++){
        free(censo[i].cidadaos);
    }
    free(censo);
}