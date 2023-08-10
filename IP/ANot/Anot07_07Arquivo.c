#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arq;
    char linha[100];

    // Abre o arquivo para leitura
    if ((arq = fopen("Test.txt", "rt")) == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Lê a primeira linha do arquivo
    fscanf(arq, " %99[^\n]\n", linha);
    printf("%s\n", linha);
    

    // Fecha o arquivo
    fclose(arq);

    return 0;
}
