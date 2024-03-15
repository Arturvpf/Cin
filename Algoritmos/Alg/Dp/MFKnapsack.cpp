#include <iostream>
#include <vector>
#include <algorithm>
/*
Na função MFKnapsack:

i: Este é o índice atual do item que estamos considerando.
j: Esta é a capacidade atual da mochila que estamos considerando.
w: Este é um vetor que contém os pesos dos itens.
v: Este é um vetor que contém os valores dos itens.
F: Esta é uma matriz onde F[i][j] representa o valor máximo que pode ser obtido considerando os primeiros i itens e uma mochila com capacidade j.
value: Esta é uma variável temporária usada para armazenar o valor máximo que pode ser obtido considerando o item atual.
A função MFKnapsack retorna o valor máximo que pode ser obtido ao colocar itens na mochila de tal forma que o peso total dos itens na mochila não exceda a capacidade da mochila. A função usa memoização para evitar o recálculo de subproblemas já resolvidos.
*/

int MFKnapsack(int i, int j, std::vector<int>& w, std::vector<int>& v, std::vector<std::vector<int>>& F) {
    if (F[i][j] < 0) {
        int value;
        if (j < w[i - 1]) {
            value = MFKnapsack(i - 1, j, w, v, F);
        } else {
            value = std::max(MFKnapsack(i - 1, j, w, v, F), v[i - 1] + MFKnapsack(i - 1, j - w[i - 1], w, v, F));
        }
        F[i][j] = value;
    }

    return F[i][j];
}

int main() {
    std::vector<int> weights = {10, 20, 30};
    std::vector<int> values = {60, 100, 120};
    int capacity = 50;
    int n = weights.size();

    std::vector<std::vector<int>> F(n + 1, std::vector<int>(capacity + 1, -1));

    int max_value = MFKnapsack(n, capacity, weights, values, F);
    std::cout << "Maximum value that can be obtained: " << max_value << std::endl;

    return 0;
}