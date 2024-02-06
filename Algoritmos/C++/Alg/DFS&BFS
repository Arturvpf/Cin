#include <iostream>
#include <list>
#include <queue>
#include <stack>

using namespace std;

class Grafo {
    int V; 
    list<int> *adj; 

public:
    Grafo(int V); 
    void adicionarAresta(int v, int w); 
    void BFS(int s); 
    void DFS(int s); 
};

Grafo::Grafo(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Grafo::adicionarAresta(int v, int w) {
    adj[v].push_back(w); 
}

void Grafo::BFS(int s) {
    bool *visitado = new bool[V];
    for(int i = 0; i < V; i++)
        visitado[i] = false;

    queue<int> fila;
    visitado[s] = true;
    fila.push(s);

    while(!fila.empty()) {
        s = fila.front();
        cout << s << " ";
        fila.pop();

        list<int>::iterator i;
        for(i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visitado[*i]) {
                fila.push(*i);
                visitado[*i] = true;
            }
        }
    }
}

void Grafo::DFS(int s) {
    bool *visitado = new bool[V];
    for (int i = 0; i < V; i++)
        visitado[i] = false;

    stack<int> pilha;
    visitado[s] = true;
    pilha.push(s);

    while (!pilha.empty()) {
        s = pilha.top();
        cout << s << " ";
        pilha.pop();

        list<int>::iterator i;
        for(i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visitado[*i]) {
                pilha.push(*i);
                visitado[*i] = true;
            }
        }
    }
}

// Exemplo de uso
int main() {
    Grafo g(4);
    g.adicionarAresta(0, 1);
    g.adicionarAresta(0, 2);
    g.adicionarAresta(1, 2);
    g.adicionarAresta(2, 0);
    g.adicionarAresta(2, 3);
    g.adicionarAresta(3, 3);

    cout << "Busca em Largura (BFS) a partir do vértice 2:\n";
    g.BFS(2);

    cout << "\nBusca em Profundidade (DFS) a partir do vértice 2:\n";
    g.DFS(2);

    return 0;
}
