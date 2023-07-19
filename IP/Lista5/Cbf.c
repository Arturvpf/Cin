#include <stdio.h>
#include <string.h>

typedef struct {
    char Nome[16];
    float Valor;
    int Jogadorcaro;
    int titulos;
    char OhNeyma[4];
    char Flaaamengo[4];
    float pontos;
} ranking;

int main() {
    int n;
    scanf("%d", &n);
    ranking clube[n];
    for (int i = 0; i < n; i++) {
        clube[i].pontos = 0;
        scanf(" %15[^\n]%*c", clube[i].Nome); // Corrigido o formato de leitura
        scanf("%f %d %d", &clube[i].Valor, &clube[i].Jogadorcaro, &clube[i].titulos);
        scanf("%s", clube[i].OhNeyma); // Limitado a leitura em 3 caracteres (sim\0)
        scanf("%s", clube[i].Flaaamengo); // Limitado a leitura em 3 caracteres (sim\0)
        if (strcmp(clube[i].OhNeyma, "sim") == 0) {
            clube[i].pontos += 10000;
        }
        if (strcmp(clube[i].Flaaamengo, "sim") == 0) {
            clube[i].pontos += 20000;
        }
        clube[i].pontos += clube[i].Valor;
        clube[i].pontos += ((clube[i].Jogadorcaro) * 100);
        clube[i].pontos += ((clube[i].titulos) * 2000);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (clube[j - 1].pontos < clube[j].pontos) {
                float aux = clube[j - 1].pontos;
                char aux2[16];
                strcpy(aux2, clube[j - 1].Nome);
                clube[j - 1].pontos = clube[j].pontos;
                strcpy(clube[j - 1].Nome, clube[j].Nome);
                clube[j].pontos = aux;
                strcpy(clube[j].Nome, aux2);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s %.2f\n", clube[i].Nome, clube[i].pontos);
    }
}
