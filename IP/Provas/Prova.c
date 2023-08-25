#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct{
    int linha, coluna; 
    char medic[50];
}localM;

typedef struct{
    int qtdM; 
    char medic[50];
}TMed;

typedef struct{
    int qtd;
    TMed *tmed;
}pedido;

localM *carregaConfig(int *tamC);
pedido *carregaPedidos(int *tamP);
TMed **inicializa();
void processaPedido(pedido meuPedido, TMed **estoque, localM *config, int tamC);
void processaPedidos(pedido *todosPedidos, int tamP, TMed **estoque, localM *config, int tamC);

int main(){
    int tamC=0,tamP=0;

    localM *config=carregaConfig(&tamC);
    pedido *todosPedidos=carregaPedidos(&tamP);
    TMed **estoque=inicializa();
    processaPedidos(todosPedidos,tamP,estoque,config,tamC);

    return 0;
}
//coliseu=matriz de TMED
localM *carregaConfig(int *tamC){
    localM *config=NULL;
    FILE *arq;
    int linha,coluna;
    char medic[50];

    if((arq=fopen("config.txt","rt"))==NULL){ //checar se tem arquivo
        printf("Erro ao abrir arquivo config.txt\n");
        exit(1);
    }

    while(!feof(arq)){
        fscanf(arq,"%d, %d, %[^\n]\n",&linha,&coluna,medic);    //formato: (linha), (coluna), (medic)\n
        (*tamC)+=1;             //incrementa o tamanho de config
 
        localM *temp=config;    //variavel temporaria para dar free em caso de erro de alocacao

        config=(localM *) realloc(config,sizeof(localM)*(*tamC));

        if(config==NULL){  //checar alocacao
            printf("Erro de alocacao em config\n");
            free(temp);
            exit(1);
        }

        config[(*tamC)-1].linha=linha;
        config[(*tamC)-1].coluna=coluna;
        strcpy(config[(*tamC)-1].medic,medic);   //guardar as informacoes no vetor
    }
    fclose(arq);
    return config;
}
pedido *carregaPedidos(int *tamP){
    pedido *todosPedidos=NULL;
    FILE *arq;
    int *qtd=NULL;  //ponteiro que ira armazenar o tamanho do vetor
    
    if((arq=fopen("pedido.bin","rb"))==NULL){    //checar se tem arquivo
        printf("Erro ao abrir arquivo pedido.bin\n");
        exit(1);
    }
    while(!feof(arq)){

        fread(qtd,sizeof(int),1,arq); //ler tamanho do vetor
        (*tamP)+=1;             //incrementa o tamanho do vetor todospedidos

        pedido *temp=todosPedidos; //variavel temporaria para dar free em caso de erro de alocacao

        todosPedidos=(pedido *) realloc(todosPedidos,sizeof(pedido)*(*tamP));

        if(todosPedidos==NULL){ //checar alocacao
            printf("Erro de alocacao\n");
            free(temp);
            exit(1);
        }
        
        todosPedidos[(*tamP)-1].tmed=(TMed *)malloc(sizeof(TMed)*(*qtd));  //alocar em TMed a quantidade de medicamentos
        
        if(todosPedidos[(*tamP)-1].tmed==NULL){   //checar alocacao
            for(int i=0;i<(*qtd);i++){
                free(temp[i].tmed);
            }
            free(temp);
        }
        fread(todosPedidos[(*tamP)-1].tmed,sizeof(TMed),(*qtd),arq);   //ler conteudo do vetor e armazenar

        todosPedidos[(*tamP)-1].qtd=(*qtd);   //armazenar a quantidade de produtos do pedido
    }
    fclose(arq);    //fechar arquivo
    return todosPedidos;
}
TMed **inicializa(){
    TMed **estoque;
    TMed **tempo=estoque;

    estoque=(TMed **) malloc(sizeof(TMed)*20);   //20 linhas alocadas
    if(estoque==NULL){
        printf("Erro de alocacao\n");
        free(tempo);
        exit(1);
    }
    for(int i=0;i<20;i++){     //adicionar 2 colunas para cada linha
        estoque[i]=(TMed *)malloc(sizeof(TMed)*(20+(i*2)));
        if(estoque[i]==NULL){   //verificar se foi alocado
            for(int i=0;i<20;i++){
                free(tempo[i]);
            }
            free(tempo);
            printf("Erro de alocacao\n");
            exit(1);
            }
    }
    
    for(int i=0;i<20;i++){    //preencher a matriz com 20 quantidade de medicamentos
        for(int j=0;j<(i*2)+20;j++){
            estoque[i][j].qtdM=20;
        }
    }


    return estoque;
}
void processaPedido(pedido meuPedido, TMed **estoque, localM *config, int tamC){
    FILE *arq;
    int linha,coluna;

    if((arq=fopen("pedidos.txt","at"))==NULL){   //checar se o arquivo abriu corretamente
        printf("Erro ao abrir arquivo pedidos.txt\n");
        exit(1);
    }
    for(int i=0;i<meuPedido.qtd;i++){       //procurar a linha e coluna que o medicamento do pedido está
        for(int j=0;j<tamC;j++){
            if(strcmp(meuPedido.tmed[i].medic,config[j].medic)==0){
                fprintf(arq,"separei %d unidades do medicamento %s\n",meuPedido.tmed[i].qtdM,meuPedido.tmed[i].medic);  //printar no arquivo o que foi retirado
                linha=config[j].linha; coluna=config[j].coluna;   //a linha e a coluna do medicamento para retirar na matriz
                estoque[linha][coluna].qtdM-=meuPedido.tmed[i].qtdM;    //retirar da matriz a quantidade separada
            }
        }
    }
    
    fclose(arq);    //fechar o arquivo
    
}
void processaPedidos(pedido *todosPedidos, int tamP, TMed **estoque, localM *config, int tamC){
    FILE *arq;
    if((arq=fopen("pedidos.txt","at"))==NULL){    //checar se o arquivo abriu corretamente
            printf("Erro ao abrir arquivo pedidos.txt\n");
            exit(1);
        }

    for(int i=0;i<tamP;i++){     
        fclose(arq);        //tem que fechar o arquivo antes de chamar a funcao
        processaPedido(todosPedidos[i],estoque,config,tamC);     //processar todos os pedidos 

        if((arq=fopen("pedidos.txt","at"))==NULL){    //reabro o arquivo
            printf("Erro ao abrir arquivo pedidos.txt\n");
            exit(1);
        }
        fprintf(arq,"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");  //separo a linha com 70'+' 
    }
    fclose(arq);     //fechar o arquivo
    for(int i=0;i<20;i++){      //dar free na matriz
            free(estoque[i]);
    }
    free(estoque);
    for(int i=0;i<tamP;i++){        //liberar pedidos
        free(todosPedidos[i].tmed);
    }
    free(todosPedidos);
    free(config);       //liberar config
}
