/*
            Aula 262: Tabela Hash com struct

            Código escrito por Wagner Gaspar
            Setembro de 2021
*/

// 2 * 15 = 31
#define TAM 15

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char rua[50];
    char bairro[50];
    char cidade[50];
    char pais[50];
    int num, cep;
}Endereco;

typedef struct{
    int codigo;
    Data dataAss;
    char cargo[50];
    float salario;
}Contrato;

typedef struct{
    char nome[50];
    int cpf;
    Data dataNas;
    Endereco end;
    Contrato contr;
}Pessoa;

// -------------- impressão das informaões de uma Pessoa ------------------------

void imprimirData(Data d){
    printf("%d/%d/%d\n", d.dia, d.mes, d.ano);
}

void imprimirEndereco(Endereco end){
    printf("\tEndereco:\n");
    printf("\t\tRua: %s", end.rua);
    printf("\t\tBairro: %s", end.bairro);
    printf("\t\tCidade: %s", end.cidade);
    printf("\t\tPais: %s", end.pais);
    printf("\t\tNumero: %d\n", end.num);
    printf("\t\tCep: %d\n", end.cep);
}

void imprimirContrato(Contrato c){
    printf("\tContrato %d:\n", c.codigo);
    printf("\t\tCargo: %s", c.cargo);
    printf("\t\tSalario R$%.2f\n", c.salario);
    printf("\t\tData de ad.: ");
    imprimirData(c.dataAss);
}

void imprirPessoa(Pessoa p){
    printf("\n\tNome: %s", p.nome);
    printf("\tCpf: %d\n", p.cpf);
    printf("\tData de nas.: ");
    imprimirData(p.dataNas);
    imprimirEndereco(p.end);
    imprimirContrato(p.contr);
}

// ------------ Leitura dos dados de uma Pessoa -------------------------

Data lerData(){
    Data d;
    printf("\nDigite a data no formato dd mm aaaa: ");
    scanf("%d%d%d", &d.dia, &d.mes, &d.ano);
    getchar();
    return d;
}

Endereco lerEndereco(){
    Endereco end;
    printf("\nRua: ");
    fgets(end.rua, 49, stdin);
    printf("\nBairro: ");
    fgets(end.bairro, 49, stdin);
    printf("\nCidade: ");
    fgets(end.cidade, 49, stdin);
    printf("\nPais: ");
    fgets(end.pais, 49, stdin);
    printf("\nNumero: ");
    scanf("%d", &end.num);
    printf("\nCep: ");
    scanf("%d", &end.cep);
    getchar();
    return end;
}

Contrato lerContrato(){
    Contrato c;
    printf("\nCodigo do contrato: ");
    scanf("%d", &c.codigo);
    printf("\nData de assinatura: ");
    c.dataAss = lerData();
    printf("\nCargo: ");
    fgets(c.cargo, 49, stdin);
    printf("\nSalario: R$");
    scanf("%f", &c.salario);
    getchar();
    return c;
}

Pessoa lerPessoa(){
    Pessoa p;
    printf("\nNome: ");
    fgets(p.nome, 49, stdin);
    printf("\nCpf: ");
    scanf("%d", &p.cpf);
    printf("\nData de nascimento: ");
    p.dataNas = lerData();
    p.contr = lerContrato();
    p.end = lerEndereco();
    return p;
}

// ---------- funções e procedimentos para a tabela hash -----------

void inicializarTabela(Pessoa t[]){
    int i;

    for(i = 0; i < TAM; i++)
        t[i].cpf = 0;
}

int funcaoHash(int chave){
    return chave % TAM;
}

void inserir(Pessoa t[]){
    Pessoa p = lerPessoa();
    int id = funcaoHash(p.cpf);
    while(t[id].cpf != 0){
        id = funcaoHash(id + 1);
    }
    t[id] = p;
}

Pessoa* busca(Pessoa t[], int chave){
    int id = funcaoHash(chave);
    printf("\nIndice gerada: %d\n", id);
    while(t[id].cpf != 0){
        if(t[id].cpf == chave)
            return &t[id];
        else
            id = funcaoHash(id + 1);
    }
    return NULL;
}

void imprimir(Pessoa t[]){
    int i;
    for(i = 0; i < TAM; i++){
        printf("%d\n", i);
        if(t[i].cpf != 0)
            imprirPessoa(t[i]);
        printf("\n----------------------\n");
    }
}

int main(){

    int opcao, valor, retorno;
    Pessoa *buscar, tabela[TAM];

    inicializarTabela(tabela);

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 -Imprimir\n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
        case 1:
            inserir(tabela);
            break;
        case 2:
            printf("\tQual cpf desseja buscar? ");
            scanf("%d", &valor);
            buscar = busca(tabela, valor);
            if(buscar){
                printf("\nCpf encontrado:\n");
                imprirPessoa(*buscar);
            }
            else
                printf("\tCpf nao encontrado!\n");
            break;
        case 3:
            imprimir(tabela);
            break;
        default:
            printf("Opcao invalida!\n");
        }
    }while(opcao != 0);

    return 0;
}
