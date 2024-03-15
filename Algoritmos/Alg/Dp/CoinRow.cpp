#include <iostream>
#include <vector>
#include <algorithm>

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