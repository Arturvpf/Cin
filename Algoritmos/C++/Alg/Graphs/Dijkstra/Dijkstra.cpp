#include <iostream>
#include <vector>
#include <queue>
#include <limits>
//Quando usar?
//Dijkstra’s algorithm
//Let G be a weighted graph and v ∈ V (source), finds the shortest path
//from v to all other nodes in V
//cannot be used on
//weighted graphs with negative weights

using namespace std;

const int INF = numeric_limits<int>::max();

class Graph {
private:
    struct Edge {
        int to;
        int weight;
    };

    vector<vector<Edge>> adjacencyList;

public:
    /**
     * Construtor da classe Graph.
     * 
     *  n O número de vértices do grafo.
     */
    Graph(int n) {
        adjacencyList.resize(n);
    }

    /**
     * Adiciona uma aresta direcionada com peso ao grafo.
     * 
     * from O vértice de origem da aresta.
     * to O vértice de destino da aresta.
     * weight O peso da aresta.
     */
    void addEdge(int from, int to, int weight) {
        adjacencyList[from].push_back({to, weight});
    }

    /**
     * Retorna o número de vértices do grafo.
     * 
     *  O número de vértices do grafo.
     */
    int size() const {
        return adjacencyList.size();
    }

    /**
     * Retorna os vizinhos de um vértice no grafo.
     * 
     *  vertex O vértice de origem.
     * @return Um vetor contendo os vizinhos do vértice.
     */
    const vector<Edge>& getNeighbors(int vertex) const {
        return adjacencyList[vertex];
    }
};

/**
 * Implementação do algoritmo de Dijkstra para encontrar o caminho mais curto em um grafo ponderado.
 * 
 *  G O grafo.
 *  s O vértice de origem.
 *  D Um vetor para armazenar as distâncias mínimas do vértice de origem para cada vértice.
 *  P Um vetor para armazenar os predecessores de cada vértice no caminho mais curto.
 */
void dijkstra(const Graph& G, int s, vector<int>& D, vector<int>& P) {
    int n = G.size();
    D.assign(n, INF);
    P.assign(n, -1);
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    D[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        for (const auto& e : G.getNeighbors(u)) {
            int v = e.to;
            int weight = e.weight;

            if (!visited[v] && D[v] > D[u] + weight) {
                D[v] = D[u] + weight;
                P[v] = u;
                pq.push({D[v], v});
            }
        }
    }
}

int main() {
    int n = 5; // Número de vértices
    Graph G(n);

    // Adiciona as arestas ao grafo
    G.addEdge(0, 1, 10);
    G.addEdge(0, 2, 5);
    G.addEdge(1, 2, 2);
    G.addEdge(1, 3, 1);
    G.addEdge(2, 1, 3);
    G.addEdge(2, 3, 9);
    G.addEdge(2, 4, 2);
    G.addEdge(3, 4, 4);
    G.addEdge(4, 3, 6);

    int source = 0; // Vértice de origem

    vector<int> D(n); // Vetor de distâncias
    vector<int> P(n); // Vetor de predecessores

    dijkstra(G, source, D, P);

    // Imprime as distâncias mínimas a partir do vértice de origem
    cout << "Distâncias mínimas a partir do vértice " << source << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Vértice " << i << ": " << D[i] << endl;
    }

    return 0;
}
