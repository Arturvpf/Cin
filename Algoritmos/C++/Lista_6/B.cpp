#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Graph {
    struct Edge {
        int u, v, w;
        bool operator<(Edge const& other) {
            return w < other.w;
        }
    };
    int V;
    vector<int> parent, rank;
    vector<Edge> edges;

public:
    Graph(int V) {
        this->V = V;
        parent.resize(V);
        rank.resize(V, 0);
        for (int i = 0; i < V; i++)
            parent[i] = i;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }

    int kruskalMST() {
        sort(edges.begin(), edges.end());

        int max_edge = 0;
        for (Edge e : edges) {
            if (find_set(e.u) != find_set(e.v)) {
                max_edge = max(max_edge, e.w);
                union_sets(e.u, e.v);
            }
        }

        bool possible = true;
        for (int i = 0; i < V; i++) {
            if (find_set(i) != find_set(0)) {
                possible = false;
                break;
            }
        }

        if (possible)
            return max_edge;
        else
            return -1; // return -1 if not possible
    }
};

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0)
            break;

        Graph g(n);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            g.addEdge(u, v, w);
        }

        int result = g.kruskalMST();
        if (result != -1)
            cout << result << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}