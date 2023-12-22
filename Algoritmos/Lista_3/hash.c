#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int TAM;

// Estrutura para armazenar uma entrada (chave e valor)
typedef struct {
    int key;
    char *value;
} Entry;

// Estrutura para armazenar uma lista de entradas
typedef struct {
    Entry* entries;
    int size;
} List;

// Estrutura para o dicionário
typedef struct {
    int m; // tamanho da tabela hash
    int cnt; // número de elementos no dicionário
    List* H; // tabela hash como um array de listas
    int (*h)(int key); // função hash
} Dictionary;
int Hash();
int h();
Entry *find();
Entry create_entry();
Dictionary* create_dict();
void insert();

int Hash(char str[]){ 
    return (h(str)%101);
}
int h(char str[]){
    int hash=0;
    char aux;
    for(int i=0;i<strlen(str);i++){
        aux=str[i];
        hash += aux * (i + 1);
    }
    return hash*19;
}

// Função para adicionar uma entrada à lista
void append(List* list, Entry entry) {
    list->entries = (Entry*) realloc(list->entries, (list->size + 1) * sizeof(Entry));
    list->entries[list->size] = entry;
    list->size++;
}
// Função para encontrar uma chave no dicionário
Entry* find(Dictionary* d, int key) {
    int pos = d->h(key);
    List* list = &d->H[pos];
    for (int i = 0; i < list->size; i++) {
        if (list->entries[i].key == key) {
            return &list->entries[i];
        }
    }
    return NULL;
}

// Função para criar uma nova entrada
Entry create_entry(int key, char* value) {
    Entry entry;
    entry.key = key;
    entry.value = strdup(value); // duplica a string para evitar problemas de memória
    return entry;
}

// Função para criar um novo dicionário
Dictionary* create_dict(int size, int (*hash_func)(int)) {
    Dictionary* d = (Dictionary*) malloc(sizeof(Dictionary));
    d->m = size;
    d->cnt = 0;
    d->H = (List*) malloc(size * sizeof(List));
    for (int i = 0; i < size; i++) {
        d->H[i].entries = NULL;
        d->H[i].size = 0;
    }
    d->h = hash_func;
    return d;
}

// Função para inserir uma chave e um valor no dicionário
void insert(Dictionary* d, char* value) {
    int hashed_key=Hash(value);
    if (find(d, hashed_key) == NULL) {
        int pos = d->h(hashed_key);
        List l=d->H[pos];
        Entry entry=create_entry(hashed_key,value);
        append(&l,entry);
    }
    else{
        for(int i=1;i<20;i++){
            if(find(d, hashed_key+i) == NULL){
                int pos = d->h(hashed_key);
                List l=d->H[pos];
                Entry entry=create_entry(hashed_key,value);
                append(&l,entry);
            }
        }
    }
}


//funcao remove  incompleto
/*int removeItem(List* l) {
    if (l->curr < 0 || l->curr >= l->listSize) {
        return -1; // Retorna -1 se o índice atual não estiver dentro dos limites da lista
    }

    int it = l->listArray[l->curr];
    int i = l->curr;

    while (i < l->listSize - 1) {
        l->listArray[i] = l->listArray[i + 1]; // Shift para a esquerda
        i++;
    }

    l->listSize--;

    return it;
}*/



int main(){
    int t;
    scanf("%d",&t);
    int n[t];
    int j=0;
    char op[5];
    char name[16];
    while(j<t){
        scanf("%d",&n[j]);
        for(int i=0;i<n[j];i++){
            scanf("%s:%s",op,name);
            if(strcmp(op,"ADD")==0){  //ler operador e o nome

            }
            else{

            }
        }
        j++;
    }
}