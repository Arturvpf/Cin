#include <iostream>
#include <vector>
#include <algorithm>
/*
Na função maxCoin:

coins: Este é um vetor de inteiros que representa os valores das moedas em uma linha.
n: Este é o número total de moedas na linha.
dp: Este é um vetor de inteiros onde dp[i] representa o valor máximo que pode ser obtido das primeiras i moedas.
i: Este é o índice atual do vetor dp que estamos calculando.
A função maxCoin retorna o valor máximo que pode ser obtido ao pegar moedas da linha, de tal forma que nenhuma duas moedas adjacentes são pegues.
*/

int maxCoin(std::vector<int>& coins) {
    int n = coins.size();
    std::vector<int> dp(n + 1, 0);

    dp[0] = 0;
    dp[1] = coins[0];

    for (int i = 2; i <= n; i++) {
        dp[i] = std::max(dp[i - 1], coins[i - 1] + dp[i - 2]);
    }

    return dp[n];
}

int main() {
    std::vector<int> coins = {5, 1, 2, 10, 6, 2};
    std::cout << "Maximum value: " << maxCoin(coins) << std::endl;

    return 0;
}