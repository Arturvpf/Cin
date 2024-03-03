#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> toposort(const vector<vector<int>>& adj, vector<int>& indegree) {
    int n = indegree.size();
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 1; i < n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> result;
    while(!q.empty()){
        int u = q.top();
        q.pop();
        result.push_back(u);
        for(int v : adj[u]){
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v);
            }
        }
    }
    return result;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1, 0);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    vector<int> result = toposort(adj, indegree);
    if(result.size() == n){
        for(int i = 0; i < n; i++){
            cout << result[i] << " ";
        }
    } else {
        cout << "Sandro fails.";
    }
    return 0;
}