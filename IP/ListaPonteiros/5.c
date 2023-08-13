#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ID;
    int qtd;
    int preco;
} Produto;

int main() {
    int numProdutos = 0;
    Produto *produtos = NULL;
    int i;
    int j;

    while (1) {
        char escolha[4];
        int ID_produto=0, qtd=0, preco=0;
        printf("NEW,RM,END\n");
        scanf(" %s", escolha);

        if (strcmp(escolha, "NEW") == 0) {
            printf("ID,qtd,preco\n");
            scanf("%d %d %d", &ID_produto, &qtd, &preco);
            numProdutos++;
            Produto *aux=produtos;
            produtos=(Produto *) realloc(produtos,sizeof(Produto)*(numProdutos));
            if(produtos==NULL){
                printf("Erro alocacao\n");
                free(aux);
                exit(1);
            }
            produtos[numProdutos-1].ID=ID_produto;
            produtos[numProdutos-1].qtd=qtd;
            produtos[numProdutos-1].preco=preco;
        } else if (strcmp(escolha, "RM") == 0) {
            printf("ID\n");
            scanf("%d", &ID_produto);

            for (i = 0; i < numProdutos; i++) {
                if (produtos[i].ID == ID_produto) {
                    for(j=i+1;j<numProdutos;j++){
                        produtos[j-1]=produtos[j];
                    }
                    numProdutos--;
                    printf("removido\n");
                    if(numProdutos>0){
                        Produto *aux=produtos;
                        produtos=(Produto *) realloc(produtos,sizeof(Produto)*(numProdutos));
                        if(produtos==NULL){
                            printf("Erro alocacao");
                            free(aux);
                            exit(1);
                        }
                    }
                    else produtos=NULL;
                    break;
                }
            }
        } 
        else if (strcmp(escolha, "END") == 0) {
            printf("Lista:\n");
            break;
        }
    }
    for(i=0;i<numProdutos;i++){
        for(j=1;j<numProdutos;j++){
            if(produtos[j].ID<produtos[j-1].ID){
                int aux2=produtos[j].ID;
                int aux3=produtos[j].preco;
                int aux4=produtos[j].qtd;
                produtos[j].ID=produtos[j-1].ID;
                produtos[j].qtd=produtos[j-1].qtd;
                produtos[j].preco=produtos[j-1].preco;
                produtos[j-1].preco=aux3;
                produtos[j-1].ID=aux2;
                produtos[j-1].qtd=aux4;
            }
        }
    }

    for(i=0;i<numProdutos;i++){
        printf("ID:%d-Preco:%d-qtd:%d\n",produtos[i].ID,produtos[i].preco,produtos[i].qtd);
    }


    free(produtos);

    return 0;
}
