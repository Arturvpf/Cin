#include <stdio.h>
#include <string.h>

#define MAX_PECA 100

typedef struct {
    char tipo[20];
    int valor;
    int performance;
} Peca;

int main() {
    int dinheiro, numPecas, i;
    int performanceTotal = 0;
    int carroMontado = 0;
    int dinheiroRestante = 0;

    Peca pecas[MAX_PECA];

    
    scanf("%d %d", &dinheiro, &numPecas);

    for (i = 0; i < numPecas; i++) {
        scanf("%s %d %d", pecas[i].tipo, &pecas[i].valor, &pecas[i].performance);

       
        if (strcmp(pecas[i].tipo, "Motor") == 0 ||
            strcmp(pecas[i].tipo, "Roda") == 0 ||
            strcmp(pecas[i].tipo, "Lataria") == 0) {
            
           
            if (dinheiro >= pecas[i].valor) {
                dinheiro -= pecas[i].valor;
                performanceTotal += pecas[i].performance;
                if (strcmp(pecas[i].tipo, "Motor") == 0)
                    carroMontado |= 1;
                else if (strcmp(pecas[i].tipo, "Roda") == 0)
                    carroMontado |= 2;
                else if (strcmp(pecas[i].tipo, "Lataria") == 0)
                    carroMontado |= 4;
            }
        }
    }

    
    if (carroMontado == 7) {
        printf("Minha nave tem uma performance de %d pontos\n", performanceTotal);
        if (dinheiro > 0) {
            printf("E ainda me sobraram %d mangos!\n", dinheiro);
        }
    } else {
        printf("Nao foi possivel construir uma caranga...\n");
    }

    return 0;
}
