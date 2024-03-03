#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
class Graph: public vector<vector<pair<int,int>>>{
    public:
    Graph(int n): vector<vector<pair<int,int>>>(n){}
    void add_edge(int u, int v, int w){
        (*this)[u].push_back({v,w});
        (*this)[v].push_back({u,w});
    }
    int dijkstra(int s, int t){
        vector<int> dist(size(), INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,s});
        dist[s] = 0;
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            for(auto [v,w]: (*this)[u]){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist[t];
    }
};

int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int n, m,S,T;
        cin >> n >> m>>S>>T;
        Graph g(n);
        for(int k=0;k<m;k++){
            int u,v,w;
            cin >> u >> v >> w;
            g.add_edge(u,v,w);
        }
        int Caso=g.dijkstra(S,T);
        if(Caso==INT_MAX){
            cout << "Case #" << i+1 << ": unreachable" << endl;
        }
        else cout << "Case #" << i+1 << ": " << Caso << endl;
    }
}