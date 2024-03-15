#include <iostream>
#include <vector>
#include <algorithm>
/*
Na função knapsack:

n: Este é o número total de itens disponíveis.
W: Esta é a capacidade total da mochila.
w: Este é um vetor que contém os pesos dos itens.
v: Este é um vetor que contém os valores dos itens.
F: Esta é uma matriz onde F[i][j] representa o valor máximo que pode ser obtido considerando os primeiros i itens e uma mochila com capacidade j.
i e j: Estes são os índices atuais que estamos considerando na matriz F.
A função knapsack retorna o valor máximo que pode ser obtido ao colocar itens na mochila de tal forma que o peso total dos itens na mochila não exceda a capacidade da mochila.
*/

int knapsack(int n, int W, std::vector<int>& w, std::vector<int>& v) {
    std::vector<std::vector<int>> F(n + 1, std::vector<int>(W + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                F[i][j] = 0;
            } else if (w[i - 1] <= j) {
                F[i][j] = std::max(F[i - 1][j], v[i - 1] + F[i - 1][j - w[i - 1]]);
            } else {
                F[i][j] = F[i - 1][j];
            }
        }
    }

    return F[n][W];
}

int main() {
    std::vector<int> weights = {10, 20, 30};
    std::vector<int> values = {60, 100, 120};
    int capacity = 50;
    int n = weights.size();

    int max_value = knapsack(n, capacity, weights, values);
    std::cout << "Maximum value that can be obtained: " << max_value << std::endl;

    return 0;
}