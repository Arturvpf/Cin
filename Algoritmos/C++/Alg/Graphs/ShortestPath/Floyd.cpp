#include <iostream>
#include <vector>
using namespace std;
#define INF 99999
//Quando usar?
//Floyd-Warshall algorithm
//Let G be a weighted graph, finds the shortest path between all pairs of
//nodes in G
//All-pairs shortest paths
//can be used on weighted graphs with negative
//weights (but no negative cycles)

class Graph {
private:
    int V; // número de vértices
    vector<vector<int>> adjMatrix; // matriz de adjacência

public:
    /**
     * Construtor da classe Graph.
     * @param vertices O número de vértices do grafo.
     */
    Graph(int vertices) : V(vertices) {
        adjMatrix.resize(V, vector<int>(V, INF)); // inicializa a matriz de adjacência com valores infinitos
    }

    /**
     * Adiciona uma aresta ao grafo.
     * @param src O vértice de origem.
     * @param dest O vértice de destino.
     * @param weight O peso da aresta.
     */
    void addEdge(int src, int dest, int weight) {
        adjMatrix[src][dest] = weight; // define o peso da aresta na matriz de adjacência
    }

    /**
     * Executa o algoritmo de Floyd-Warshall para encontrar os menores caminhos entre todos os pares de vértices.
     */
    void floydWarshall() {
        vector<vector<int>> dist = adjMatrix; // cria uma cópia da matriz de adjacência para armazenar as distâncias

        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j]; // atualiza a distância mínima entre os vértices i e j
                    }
                }
            }
        }

        // Imprime as distâncias mínimas
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INF) {
                    cout << "INF ";
                } else {
                    cout << dist[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int V = 4; // Número de vértices
    Graph g(V);

    // Adiciona as arestas ao grafo
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 0, 1);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 1, 1);
    g.addEdge(3, 2, 2);

    // Executa o algoritmo de Floyd-Warshall
    g.floydWarshall();

    return 0;
}
