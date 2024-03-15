#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int S, vector<pair<int, int>>& items) {
    int N = items.size();
    vector<vector<int>> dp(N + 1, vector<int>(S + 1, 0));

    for (int i = 1; i <= N; i++) {
        int size = items[i - 1].first;
        int value = items[i - 1].second;

        for (int j = 1; j <= S; j++) {
            if (size <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - size] + value);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[N][S];
}

int main() {
    int S, N;
    cin >> S >> N;

    vector<pair<int, int>> items(N);
    for (int i = 0; i < N; i++) {
        cin >> items[i].first >> items[i].second;
    }

    int maxTotalValue = knapsack(S, items);
    cout << maxTotalValue << endl;

    return 0;
}
