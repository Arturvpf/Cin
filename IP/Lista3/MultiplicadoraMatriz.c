#include <stdio.h>

int main() {
    int linhas_A, colunas_A, linhas_B, colunas_B;

    scanf("%d %d %d %d", &linhas_A, &colunas_A, &linhas_B, &colunas_B);

    if (colunas_A != linhas_B) {
        printf("Nao e possivel multiplicar\n");
    }
    else{

        int matriz_A[linhas_A][colunas_A];
        int matriz_B[linhas_B][colunas_B];
        int matriz_resultante[linhas_A][colunas_B];

        for (int i = 0; i < linhas_A; i++) {
            for (int j = 0; j < colunas_A; j++) {
                scanf("%d", &matriz_A[i][j]);
            }
        }

        for (int i = 0; i < linhas_B; i++) {
            for (int j = 0; j < colunas_B; j++) {
                scanf("%d", &matriz_B[i][j]);
            }
        }

        for (int i = 0; i < linhas_A; i++) {
            for (int j = 0; j < colunas_B; j++) {
                matriz_resultante[i][j] = 0;
                for (int k = 0; k < colunas_A; k++) {
                    matriz_resultante[i][j] += matriz_A[i][k] * matriz_B[k][j];
                }
            }
        }

        for (int i = 0; i < linhas_A; i++) {
            for (int j = 0; j < colunas_B; j++) {
                printf("%d ", matriz_resultante[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
