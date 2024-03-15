#include <iostream>
#include <vector>
#include <algorithm>
/*
Na estrutura Edge:

u, v: São os vértices que formam a aresta.
weight: É o peso da aresta.
Na função find_set:

v: É o vértice cujo conjunto disjunto estamos procurando.
Na função make_set:

v: É o vértice para o qual estamos criando um novo conjunto disjunto.
Na função union_sets:

a, b: São os vértices cujos conjuntos disjuntos estamos unindo.
Na função constructMST:

edges: É um vetor de todas as arestas no grafo.
n: É o número total de vértices no grafo.
result: É um vetor das arestas que são incluídas na árvore de extensão mínima.
Além disso, temos duas variáveis globais parent e rank:

parent: É um vetor onde parent[i] é o representante do conjunto disjunto que contém o vértice i.
rank: É um vetor onde rank[i] é a profundidade da árvore de conjuntos disjuntos que contém o vértice i. É usado para otimizar a união de dois conjuntos disjuntos.
Na função find_set:

v: É o vértice cujo conjunto disjunto estamos procurando.
Na função make_set:

v: É o vértice para o qual estamos criando um novo conjunto disjunto.
Na função union_sets:

a, b: São os vértices cujos conjuntos disjuntos estamos unindo.
Na função constructMST:

edges: É um vetor de todas as arestas no grafo.
n: É o número total de vértices no grafo.
result: É um vetor das arestas que são incluídas na árvore de extensão mínima.
Além disso, temos duas variáveis globais parent e rank:

parent: É um vetor onde parent[i] é o representante do conjunto disjunto que contém o vértice i.
rank: É um vetor onde rank[i] é a profundidade da árvore de conjuntos disjuntos que contém o vértice i. É usado para otimizar a união de dois conjuntos disjuntos.
Na função preOrderWalk:

v: É o vértice atual que estamos visitando na caminhada de pré-ordem.
adj: É um vetor de listas de adjacência que representa o grafo.
visited: É um vetor que mantém o controle de quais vértices já foram visitados.
result: É um vetor que armazena a ordem dos vértices visitados.
Na função TSPMST:

edges: É um vetor de todas as arestas no grafo.
n: É o número total de vértices no grafo.
mst: É um vetor das arestas que são incluídas na árvore de extensão mínima.
adj: É um vetor de listas de adjacência que representa a MST.
visited: É um vetor que mantém o controle de quais vértices já foram visitados na caminhada de pré-ordem.
cycle: É um vetor que armazena a ordem dos vértices visitados na caminhada de pré-ordem, que forma o ciclo hamiltoniano.
*/

// Representação do grafo
struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

std::vector<int> parent;
std::vector<int> rank;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            std::swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

// Construção da MST usando o algoritmo de Kruskal
std::vector<Edge> constructMST(std::vector<Edge>& edges, int n) {
    std::vector<Edge> result;
    parent.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; i++)
        make_set(i);

    std::sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }

    return result;
}

// Caminhada de pré-ordem na MST
void preOrderWalk(int v, std::vector<std::vector<int>>& adj, std::vector<bool>& visited, std::vector<int>& result) {
    visited[v] = true;
    result.push_back(v);
    for (int u : adj[v]) {
        if (!visited[u])
            preOrderWalk(u, adj, visited, result);
    }
}

std::vector<int> TSPMST(std::vector<Edge>& edges, int n) {
    std::vector<Edge> mst = constructMST(edges, n); // Constrói a MST
    std::vector<std::vector<int>> adj(n);
    for (Edge e : mst) {
        adj[e.u].push_back(e.v);
        adj[e.v].push_back(e.u);
    }
    std::vector<bool> visited(n, false);
    std::vector<int> cycle;
    preOrderWalk(0, adj, visited, cycle); // Realiza a caminhada de pré-ordem na MST
    return cycle;
}