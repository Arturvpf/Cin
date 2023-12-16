#include <stdio.h>
#include <string.h>

void removeABC(char *str) {
    int len = strlen(str);
    int i, j;
    for (i = 0; i < len; ++i) {
        if (str[i] == 'A' && str[i + 1] == 'B' && str[i + 2] == 'C') {
            // Desloca os caracteres para a esquerda para remover "ABC"
            for (j = i; j < len - 2; ++j) {
                str[j] = str[j + 3];
            }
            len -= 3; // Atualiza o comprimento da string
            str[len] = '\0'; // Insere o terminador nulo
            i--; // Volta uma posição para verificar novamente após a remoção
        }
    }
}

int main() {
    char string[200001]; // Tamanho máximo de string
    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);

    // Remove todas as ocorrências de "ABC"
    removeABC(string);

    printf("String sem ocorrências de 'ABC': %s\n", string);

    return 0;
}
