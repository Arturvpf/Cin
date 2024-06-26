#include <iostream>
#include <vector>
#include <limits>
/*
Na função ChangeMaking:

D: Este é um vetor de inteiros que representa os diferentes tipos de moedas disponíveis.
n: Este é o valor total para o qual estamos tentando fazer o troco.
F: Este é um vetor de inteiros onde F[i] representa o número mínimo de moedas necessárias para fazer o troco para o valor i.
temp: Esta é uma variável temporária usada para armazenar o número mínimo de moedas necessárias para fazer o troco para o valor i - D[j - 1].
j: Este é o índice atual do vetor D que estamos considerando.
A função ChangeMaking retorna o número mínimo de moedas necessárias para fazer o troco para o valor n.
*/

int ChangeMaking(std::vector<int>& D, int n) {
    std::vector<int> F(n + 1, std::numeric_limits<int>::max());
    F[0] = 0;

    for (int i = 1; i <= n; i++) {
        int temp = std::numeric_limits<int>::max();
        int j = 1;
        while (j <= D.size() && i >= D[j - 1]) {
            temp = std::min(F[i - D[j - 1]], temp);
            j++;
        }
        F[i] = temp + 1;
    }

    return F[n];
}

int main() {
    std::vector<int> coins = {1, 5, 10, 25};
    int amount = 37;

    int minCoins = ChangeMaking(coins, amount);
    std::cout << "Minimum number of coins needed: " << minCoins << std::endl;

    return 0;
}