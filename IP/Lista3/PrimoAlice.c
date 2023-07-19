#include <stdio.h>

int main() {
    int n;
    
    scanf("%d", &n);
    
    int matriz[n][n];
    int primos[n * n]; 
    int Qprimos = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
            
            int num = matriz[i][j];
            int Primo = 1;
            
            if (num <= 1) {
                Primo = 0;
            }
            
            for (int k = 2; k * k <= num; k++) {
                if (num % k == 0) {
                    Primo = 0;
                    break;
                }
            }
            
            if (Primo) {
                primos[Qprimos] = num;
                Qprimos++;
            }
        }
    }
    for (int i = 0; i < Qprimos - 1; i++) {
        for (int j = 0; j < Qprimos - i - 1; j++) {
            if (primos[j] > primos[j + 1]) {
                int aux = primos[j];
                primos[j] = primos[j + 1];
                primos[j + 1] = aux;
            }
        }
    }
    for (int i = 0; i < Qprimos; i++) {
        printf("%d ", primos[i]);
    }
    
    return 0;
}
