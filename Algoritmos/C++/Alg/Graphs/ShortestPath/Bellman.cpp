#include <iostream>
#include <vector>
#include <climits>
using namespace std;
//Quando usar?
//Bellman-Ford algorithm
//Let G be a weighted graph and v ∈ V (source), finds the shortest path
//from v to all other nodes in V
//Bellman-Ford algorithm: can be used on
//weighted graphs with negative cycles

class Graph {
    int V;
    vector<vector<int>> edges;

public:
    /**
     * Construtor da classe Graph.
     * @param vertices O número de vértices do grafo.
     */
    Graph(int vertices) : V(vertices), edges(vertices, vector<int>(vertices, 0)) {}

    /**
     * Adiciona uma aresta direcionada com peso ao grafo.
     * @param u O vértice de origem.
     * @param v O vértice de destino.
     * @param weight O peso da aresta.
     */
    void addEdge(int u, int v, int weight) {
        edges[u][v] = weight;
    }

    /**
     * Algoritmo de Bellman-Ford para encontrar os menores caminhos a partir de um vértice de origem.
     * @param source O vértice de origem.
     * @param distances Um vetor para armazenar as distâncias mínimas.
     */
    void BellmanFord(int source, vector<int>& distances) {
        int n = V;
        for (int i = 0; i < n; i++) {
            distances[i] = INT_MAX;
        }
        distances[source] = 0;

        for (int k = 0; k < n - 1; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (distances[j] > distances[i] + edges[i][j]) {
                        distances[j] = distances[i] + edges[i][j];
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (distances[j] > distances[i] + edges[i][j]) {
                    cout << "Negative cycle detected" << endl;
                    return;
                }
            }
        }
    }
};

int main() {
    int V = 5; // Número de vértices
    Graph g(V);

    // Adiciona arestas ao grafo
    g.addEdge(0, 1, 6);
    g.addEdge(0, 2, 7);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 3, -4);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 3, 9);
    g.addEdge(2, 4, -3);
    g.addEdge(3, 1, 2);
    g.addEdge(4, 0, 3);
    g.addEdge(4, 3, 7);

    int source = 0;
    vector<int> distances(V);

    g.BellmanFord(source, distances);

    // Imprime as distâncias a partir do vértice de origem
    for (int i = 0; i < V; i++) {
        cout << "Distância da origem ao vértice " << i << ": " << distances[i] << endl;
    }

    return 0;
}
