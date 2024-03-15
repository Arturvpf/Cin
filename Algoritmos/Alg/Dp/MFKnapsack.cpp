#include <iostream>
#include <vector>
#include <algorithm>

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