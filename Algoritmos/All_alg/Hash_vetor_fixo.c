

void inicializarTabela(int t[],int TAM){
    int i;

    for(i = 0; i < TAM; i++)
        t[i] = 0;
}

int funcaoHash(int chave,int TAM){
    return chave % TAM;
}

void inserir(int t[], int valor,int TAM){
    int id = funcaoHash(valor,TAM);
    while(t[id] != 0){
        id = funcaoHash(id + 1,TAM);
    }
    t[id] = valor;
}

int busca(int t[], int chave,int TAM){
    int id = funcaoHash(chave,TAM);
    printf("\nIndice gerada: %d\n", id);
    while(t[id] != 0){
        if(t[id] == chave)
            return t[id];
        else
            id = funcaoHash(id + 1,TAM);
    }
    return 0;
}

void imprimir(int t[],int TAM){
    int i;
    for(i = 0; i < TAM; i++){
        printf("%d = %d\n", i, t[i]);
    }
}
