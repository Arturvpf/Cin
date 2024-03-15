#include <iostream>
#include <vector>
#include <algorithm>

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