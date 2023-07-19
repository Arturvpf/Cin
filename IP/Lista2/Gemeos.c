// Add some code#include <stdio.h>

int main() {
    int altura;

    scanf("%d", &altura);
    int i, j, k,soma=0;
    for (i = 0; i < altura; i++) {
        for (j = 0; j < altura - i - 1; j++) {
            printf(".");
        }
        for (k = 0; k < i ; k++) {
            printf("&-");
            soma+=250;
        }
        printf("&"); soma+=200;
        for (j = 0; j < altura - i - 1; j++) {
            printf(".");
        }
        printf("\n");
    }
    for (i = 0; i < 2 * altura -1; i++) {
        printf("#");soma+=100;
    }
    printf("\n");

    printf("O valor total foi: %d",soma);

    return 0;
}
