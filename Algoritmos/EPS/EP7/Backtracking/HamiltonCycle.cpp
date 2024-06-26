#include<iostream>
#include<vector>
#define N 5
/*
Na função is_valid:

v: Este é o vértice que estamos tentando adicionar ao caminho.
graph[N][N]: Esta é a matriz de adjacência que representa o grafo. Se graph[i][j] é 1, então há uma aresta entre os vértices i e j. Se graph[i][j] é 0, então não há aresta entre os vértices i e j.
path: Este é o vetor que armazena o caminho atual.
pos: Esta é a posição atual no caminho.
Na função hamiltonian_cycle_util:

graph[N][N]: Esta é a matriz de adjacência que representa o grafo, da mesma forma que na função is_valid.
path: Este é o vetor que armazena o caminho atual.
pos: Esta é a posição atual no caminho.
Na função hamiltonian_cycle:

graph[N][N]: Esta é a matriz de adjacência que representa o grafo, da mesma forma que nas funções is_valid e hamiltonian_cycle_util.
path: Este é o vetor que armazena o caminho atual.

*/
using namespace std;

bool is_valid(int v, bool graph[N][N], vector<int> &path, int pos) {
    if (graph [path[pos-1]][v] == 0)
        return false;
    if (find(path.begin(), path.end(), v) != path.end())
        return false;
    return true;
}

bool hamiltonian_cycle_util(bool graph[N][N], vector<int> &path, int pos) {
    if (pos == N) {
        if (graph[path[pos-1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < N; v++) {
        if (is_valid(v, graph, path, pos)) {
            path[pos] = v;
            if (hamiltonian_cycle_util(graph, path, pos + 1) == true)
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

bool hamiltonian_cycle(bool graph[N][N]) {
    vector<int> path(N, -1);
    path[0] = 0;
    if (hamiltonian_cycle_util(graph, path, 1) == false) {
        cout << "\nSolution does not exist";
        return false;
    }
    for (int i = 0; i < N; i++)
        cout << path[i] << " ";
    cout << path[0] << endl;
    return true;
}

int main() {
    bool graph1[N][N] = {{0, 1, 1, 1, 0},
                         {1, 0, 1, 1, 1},
                         {1, 1, 0, 1, 0},
                         {1, 1, 1, 0, 1},
                         {0, 1, 0, 1, 0}};
    hamiltonian_cycle(graph1);
    return 0;
}