#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

int main() {
    char** str = NULL; // Ponteiro para o vetor de strings
    char buffer[BUFFER_SIZE];
    int num_strings = 0;
    int i;

    // Loop para receber as strings enquanto houver entrada no buffer
    while (1) {
        printf("Digite uma string (ou 'sair' para terminar): ");
        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
            printf("Erro ao ler a entrada.\n");
            break;
        }

        // Remove a quebra de linha do final da string, se houver
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        // Verifica se a entrada é "sair" para terminar o loop
        if (strcmp(buffer, "sair") == 0) {
            break;
        }

        // Realoca o vetor de strings para armazenar mais uma string
        char** temp = (char**)realloc(str, (num_strings + 1) * sizeof(char*));
        if (temp == NULL) {
            printf("Erro ao alocar memória.\n");
            break;
        }

        str = temp;

        // Aloca memória para armazenar a nova string
        str[num_strings] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        if (str[num_strings] == NULL) {
            printf("Erro ao alocar memória.\n");
            break;
        }

        // Copia a nova string para o vetor
        strcpy(str[num_strings], buffer);
        num_strings++;
    }

    // Imprime as strings armazenadas
    printf("\nStrings armazenadas:\n");
    for (i = 0; i < num_strings; i++) {
        printf("%s\n", str[i]);
    }

    // Libera a memória alocada para cada string
    for (i = 0; i < num_strings; i++) {
        free(str[i]);
    }

    // Libera o vetor de strings
    free(str);

    return 0;
}
