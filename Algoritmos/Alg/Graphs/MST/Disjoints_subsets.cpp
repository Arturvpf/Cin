#include <iostream>
#include <vector>
using namespace std;

// Classe para representar conjuntos disjuntos
class DisjointSets {
public:
    vector<int> parent; // Vetor para armazenar o representante de cada conjunto
    vector<int> rank; // Vetor para armazenar o rank (altura da árvore) de cada conjunto

    // Construtor
    DisjointSets(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Inicialmente, cada elemento é seu próprio representante
            rank[i] = 0; // Inicialmente, cada conjunto tem rank 0
        }
    }

    // Função para encontrar o representante de um conjunto
    int find(int x) {
        // Se x não é o representante de seu conjunto, então o representante de x é o representante do representante de x
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Função para unir dois conjuntos
    void union_sets(int x, int y) {
        int xRoot = find(x); // Encontra o representante do conjunto de x
        int yRoot = find(y); // Encontra o representante do conjunto de y

        // Se os conjuntos são diferentes, realiza a união
        if (xRoot != yRoot) {
            // União pelo rank
            if (rank[xRoot] < rank[yRoot]) {
                parent[xRoot] = yRoot;
            } else if (rank[xRoot] > rank[yRoot]) {
                parent[yRoot] = xRoot;
            } else {
                parent[yRoot] = xRoot;
                rank[xRoot] = rank[xRoot] + 1;
            }
        }
    }
};