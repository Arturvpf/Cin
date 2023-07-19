#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    char placa[N][8];

    for (int i = 0; i < N; i++) {
        scanf("%s", placa[i]);
    }
    int placaC = 0;
    int placaI = 0;
    int letras = 0;
    int num = 0;
    int c = 0;
    int I = 0;
    char certo[N][8];
    char errado[N][8];

    for (int j = 0; j < N; j++) {
        letras = 0;
        num = 0;

        for (int i = 0; i < 7; i++) {
            if ((placa[j][i] >= 'A' && placa[j][i] <= 'Z')) {
                letras++;
            } else if (placa[j][i] >= '0' && placa[j][i] <= '9') {
                num++;
            }
        }

        if (letras == 3 && num == 4) {
            placaC++;
            strcpy(certo[c], placa[j]);
            c++;
        } else {
            placaI++;
            strcpy(errado[I], placa[j]);
            I++;
        }
    }

    printf("%d placas:\n", placaC);
    for (int i = 0; i < c; i++) {
        printf("%s\n", certo[i]);
    }

    printf("%d erros:\n", placaI);
    for (int i = 0; i < I; i++) {
        printf("%s\n", errado[i]);
    }

    return 0;
}
