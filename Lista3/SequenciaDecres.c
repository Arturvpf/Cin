#include <stdio.h>

int main() {
    int teste;
    scanf("%d", &teste);

    while (teste > 0) {
        int tam;
        scanf("%d", &tam);

        int sequencia[tam];

        for (int k = 0; k < tam; k++) {
            scanf("%d", &sequencia[k]);
        }

        int tam_maior = 0;
        int inicio_maior = 0;
        int tam_atual = 1;
        int inicio_atual = 0;
        int sequencia_encontrada = 0;

        for (int i = 1; i <= tam; i++) {
            if (i < tam && sequencia[i] < sequencia[i - 1]) {
                tam_atual++;
            } else {
                if (tam_atual > tam_maior) {
                    tam_maior = tam_atual;
                    inicio_maior = inicio_atual;
                    sequencia_encontrada = 1;
                }
                tam_atual = 1;
                inicio_atual = i;
            }
        }

        if (!sequencia_encontrada || tam_maior == 1) {
            tam_maior = 0;
        }

        printf("%d\n", tam_maior);
        if (tam_maior > 0) {
            printf("%d ", sequencia[inicio_maior]);
            for (int i = inicio_maior + 1; i < inicio_maior + tam_maior; i++) {
                if (sequencia[i] != sequencia[i - 1]) {
                    printf("%d ", sequencia[i]);
                }
            }
            printf("\n");
        }

        teste--;
    }

    return 0;
}
