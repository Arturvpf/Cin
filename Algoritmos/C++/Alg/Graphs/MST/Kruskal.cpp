#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * Classe que representa um grafo.
 */
class Graph {
private:
    int numVertices; // Número de vértices do grafo
    vector<pair<int, pair<int, int>>> edges; // Vetor de arestas do grafo

public:
    /**
     * Construtor da classe Graph.
     * @param numVertices O número de vértices do grafo.
     */
    Graph(int numVertices) : numVertices(numVertices) {}

    /**
     * Adiciona uma aresta ao grafo.
     * @param u O vértice de origem da aresta.
     * @param v O vértice de destino da aresta.
     * @param weight O peso da aresta.
     */
    void addEdge(int u, int v, int weight) {
        edges.push_back({weight, {u, v}});
    }

    /**
     * Encontra o conjunto ao qual um vértice pertence.
     * @param parent O vetor de pais dos vértices.
     * @param i O índice do vértice.
     * @return O índice do conjunto ao qual o vértice pertence.
     */
    int find(int parent[], int i) {
        if (parent[i] == i)
            return i;
        return find(parent, parent[i]);
    }

    /**
     * Une dois conjuntos em um único conjunto.
     * @param parent O vetor de pais dos vértices.
     * @param rank O vetor de classificação dos vértices.
     * @param x O índice do primeiro conjunto.
     * @param y O índice do segundo conjunto.
     */
    void unionSet(int parent[], int rank[], int x, int y) {
        int xRoot = find(parent, x);
        int yRoot = find(parent, y);

        if (rank[xRoot] < rank[yRoot])
            parent[xRoot] = yRoot;
        else if (rank[xRoot] > rank[yRoot])
            parent[yRoot] = xRoot;
        else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }

    /**
     * Executa o algoritmo de Kruskal para encontrar a árvore geradora mínima do grafo.
     */
    void kruskalMST() {
        vector<pair<int, pair<int, int>>> result; // Vetor de arestas da árvore geradora mínima
        int parent[numVertices]; // Vetor de pais dos vértices
        int rank[numVertices]; // Vetor de classificação dos vértices

        // Inicializa os vetores de pais e classificação
        for (int i = 0; i < numVertices; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        // Ordena as arestas em ordem crescente de peso
        sort(edges.begin(), edges.end());

        int edgeCount = 0; // Contador de arestas adicionadas à árvore geradora mínima
        int i = 0;
        while (edgeCount < numVertices - 1) {
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            int weight = edges[i].first;

            int uRoot = find(parent, u);
            int vRoot = find(parent, v);

            // Verifica se a adição da aresta não forma um ciclo
            if (uRoot != vRoot) {
                result.push_back({weight, {u, v}});
                unionSet(parent, rank, uRoot, vRoot);
                edgeCount++;
            }

            i++;
        }

        // Imprime a árvore geradora mínima
        cout << "Minimum Spanning Tree:\n";
        for (auto edge : result) {
            cout << edge.second.first << " - " << edge.second.second << " : " << edge.first << "\n";
        }
    }
};

/**
 * Função principal do programa.
 */
int main() {
    int numVertices = 6;
    Graph G(numVertices);

    // Adiciona as arestas do grafo
    G.addEdge(0, 1, 4);
    G.addEdge(0, 2, 3);
    G.addEdge(1, 2, 1);
    G.addEdge(1, 3, 2);
    G.addEdge(2, 3, 4);
    G.addEdge(3, 4, 2);
    G.addEdge(4, 5, 6);

    // Executa o algoritmo de Kruskal para encontrar a árvore geradora mínima
    G.kruskalMST();

    return 0;
}
