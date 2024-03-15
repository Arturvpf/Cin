#include<bits/stdc++.h>
using namespace std;
#define N 4

int tsp(int graph[N][N], bool v[], int currPos, int n, int count, int cost, int ans) {
    if (count == n && graph[currPos][0]) {
        ans = min(ans, cost + graph[currPos][0]);
        return ans;
    }
    for (int i = 0; i < n; i++) {
        if (!v[i] && graph[currPos][i]) {
            v[i] = true;
            ans = tsp(graph, v, i, n, count + 1, cost + graph[currPos][i], ans);
            v[i] = false;
        }
    }
    return ans;
}

int main() {
    int graph[N][N] = {
        { 0, 10, 15, 20 },
        { 10, 0, 35, 25 },
        { 15, 35, 0, 30 },
        { 20, 25, 30, 0 }
    };
    bool v[N];
    for (int i = 0; i < N; i++)
        v[i] = false;
    v[0] = true;
    int ans = INT_MAX;
    ans = tsp(graph, v, 0, N, 1, 0, ans);
    cout << ans;
    return 0;
}