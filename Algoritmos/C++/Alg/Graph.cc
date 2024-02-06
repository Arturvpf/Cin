#include <vector>
#include <list>

class Grafo {
    int V;
    std::vector<std::list<std::pair<int, int>>> adj;
    std::vector<int> mark;

public:
    Grafo(int V) : V(V), adj(V), mark(V, 0) {}

    int n() { return V; }

    int e() {
        int total = 0;
        for (int v = 0; v < V; v++)
            total += adj[v].size();
        return total / 2;
    }

    int first(int v) {
        return adj[v].begin()->first;
    }

    int next(int v, int w) {
        auto it = find_if(adj[v].begin(), adj[v].end(), w { return pair.first == w; });
        if (it != adj[v].end() && ++it != adj[v].end())
            return it->first;
        return -1;
    }

    void setEdge(int i, int j, int wt) {
        adj[i].push_back({j, wt});
        adj[j].push_back({i, wt});
    }

    void delEdge(int i, int j) {
        adj[i].remove_if(j { return pair.first == j; });
        adj[j].remove_if(i { return pair.first == i; });
    }

    bool isEdge(int i, int j) {
        auto it = find_if(adj[i].begin(), adj[i].end(), j { return pair.first == j; });
        return it != adj[i].end();
    }

    int weight(int i, int j) {
        auto it = find_if(adj[i].begin(), adj[i].end(), j { return pair.first == j; });
        if (it != adj[i].end())
            return it->second;
        return -1;
    }

    void setMark(int v, int val) {
        mark[v] = val;
    }

    int getMark(int v) {
        return mark[v];
    }
};
