#include <stdio.h>
#include <string.h>

int main() {
    char texto1[1000];
    char texto2[1000];
    char palavras1[50][100];
    char palavras2[50][100];
    int numPalavras1 = 0;
    int numPalavras2 = 0;
    int numRepeticoes = 0;

    scanf("%[^\n]%*c", texto1);
    scanf("%[^\n]%*c", texto2);

    int len1 = strlen(texto1);
    int start = 0;
    int end = 0;

    while (start < len1) {
        while (start < len1 && (texto1[start] == ' ' || texto1[start] == '\t' || texto1[start] == '\n')) {
            start++;
        }
        end = start;

        while (end < len1 && texto1[end] != ' ' && texto1[end] != '\t' && texto1[end] != '\n') {
            end++;
        }

        if (start < len1 && end <= len1) {
            int k;
            for (k = start; k < end; k++) {
                palavras1[numPalavras1][k - start] = texto1[k];
            }
            palavras1[numPalavras1][k - start] = '\0';
            numPalavras1++;
        }

        start = end + 1;
    }
    int len2 = strlen(texto2);
    start = 0;
    end = 0;

    while (start < len2) {
        while (start < len2 && (texto2[start] == ' ' || texto2[start] == '\t' || texto2[start] == '\n')) {
            start++;
        }
        end = start;

        while (end < len2 && texto2[end] != ' ' && texto2[end] != '\t' && texto2[end] != '\n') {
            end++;
        }

        if (start < len2 && end <= len2) {
            int k;
            for (k = start; k < end; k++) {
                palavras2[numPalavras2][k - start] = texto2[k];
            }
            palavras2[numPalavras2][k - start] = '\0';
            numPalavras2++;
        }

        start = end + 1;
    }
    for (int i = 0; i < numPalavras1; i++) {
        for (int j = 0; j < numPalavras2; j++) {
            if (strcmp(palavras1[i], palavras2[j]) == 0) {
                numRepeticoes++;
                break;
            }
        }
    }

    float indicePlagio = ((float)numRepeticoes / (numPalavras1 + numPalavras2)) * 100;

    printf("%.1f\n", indicePlagio);

    return 0;
}
