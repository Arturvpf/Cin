#include <stdio.h>
#include <string.h>

int main() {
    char letras[30];
    int n;
    int podeFormarPalavra = 1;
    char aux[30];
    int contador = 0;

    scanf("%s", letras);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char palavra[30];
        scanf("%s", palavra);

        int tamPalavra = strlen(palavra);
        int tamLetras = strlen(letras);
        
        strcpy(aux, letras);

        for (int j = 0; j < tamPalavra; j++) {
            int pos = -1;
            for (int k = 0; k < tamLetras; k++) {
                if (aux[k] == palavra[j]) {
                    pos = k;
                    break;
                }
            }
            if (pos == -1) {
                podeFormarPalavra = 0;
                break;
            }
            aux[pos] = '-';
        }
        if (podeFormarPalavra == 1)contador++;

        podeFormarPalavra = 1;
    }
    printf("E possivel formar %d palavras com esse conjunto\n", contador);

    return 0;
}
