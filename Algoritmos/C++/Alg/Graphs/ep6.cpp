#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include<algorithm>
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
     * n O número de vértices do grafo.
     */
    Graph(int n) {
        adjacencyList.resize(n);
    }

    /**
     * Adiciona uma aresta direcionada com peso ao grafo.
     * 
     * from O vértice de origem da aresta.
     *  to O vértice de destino da aresta.
     *  weight O peso da aresta.
     */
    void addEdge(int from, int to, int weight) {
        adjacencyList[from].push_back({to, weight});
    }

    /**
     * Retorna o número de vértices do grafo.
     * 
     *O número de vértices do grafo.
     */
    int size() const {
        return adjacencyList.size();
    }

    /**
     * Retorna os vizinhos de um vértice no grafo.
     * 
     *  vertex O vértice de origem.
     *  Um vetor contendo os vizinhos do vértice.
     */
    const vector<Edge>& getNeighbors(int vertex) const {
        return adjacencyList[vertex];
    }
};

/**
 * Implementação do algoritmo de Dijkstra para encontrar o caminho mais curto em um grafo ponderado.
 * 
 * G O grafo.
 * s O vértice de origem.
 * D Um vetor para armazenar as distâncias mínimas do vértice de origem para cada vértice.
 * P Um vetor para armazenar os predecessores de cada vértice no caminho mais curto.
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
    unsigned int c;
    cin>>c;
    for(int L=0;L<c;L++){
        int v;//Vertices
        int a;//Edges
        int S;//Raiz
        cin>>v>>a;
        Graph G(v);
        for(int k=0;k<a;k++){
            int i,j,w;
            cin>>i>>j>>w;
            G.addEdge(i,j,w);

        }
        cin>>S;
        vector<int> D(v); // Vetor de distâncias
        vector<int> P(v); // Vetor de predecessores
        dijkstra(G,S,D,P);
        cout<<"Caso "<<L+1<<endl;
        //sort(D);
        for(int m=0;m<v;m++){
            if (D[m] == INF) {
                cout << "-1" << endl;  // Se não for possível alcançar, imprime -1
            } else {
                cout << D[m] << endl;
            }
        }

    }


    return 0;
}

