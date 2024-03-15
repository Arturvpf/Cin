#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < N; i++) {
        for (int j = i - 1; j >= max(i - K, 0); j--) {
            dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
        }
    }

    cout << dp[N - 1] << endl;

    return 0;
}
