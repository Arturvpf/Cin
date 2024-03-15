#include <bits/stdc++.h>
using namespace std;

#define N 4
/*
Na estrutura Node:

parent: Este é um ponteiro para o nó pai na árvore de busca.
pathCost: Este é o custo do caminho da raiz até este nó.
cost: Este é o custo total estimado do caminho da raiz até a solução através deste nó.
workerID: Este é o índice do trabalhador que está sendo atribuído.
jobID: Este é o índice do trabalho que está sendo atribuído ao trabalhador.
assigned[N]: Este é um vetor booleano que indica quais trabalhos foram atribuídos.
Na função newNode:

x e y: Estes são os índices do trabalhador e do trabalho que estão sendo atribuídos.
assigned[]: Este é o vetor booleano que indica quais trabalhos foram atribuídos.
parent: Este é o nó pai na árvore de busca.
Na função calculateCost:

costMatrix[N][N]: Esta é a matriz de custos para atribuir cada trabalho a cada trabalhador.
x e y: Estes são os índices do trabalhador e do trabalho que estão sendo atribuídos.
assigned[]: Este é o vetor booleano que indica quais trabalhos foram atribuídos.
cost: Este é o custo total estimado para atribuir os trabalhos restantes.
available[N]: Este é um vetor booleano que indica quais trabalhos estão disponíveis para atribuição.
Na estrutura comp:

lhs e rhs: Estes são ponteiros para os nós que estão sendo comparados. A estrutura comp é usada para ordenar a fila de prioridade de nós na árvore de busca.


Na função printAssignments:

min: Este é um ponteiro para o nó que representa a solução mínima encontrada. A função imprime a atribuição de trabalhos a trabalhadores que leva a essa solução mínima.
Na função findMinCost:

costMatrix[N][N]: Esta é a matriz de custos para atribuir cada trabalho a cada trabalhador.
pq: Esta é uma fila de prioridade que armazena os nós que ainda precisam ser explorados na árvore de busca. Os nós são ordenados por seu custo total estimado.
assigned[N]: Este é um vetor booleano que indica quais trabalhos foram atribuídos.
root: Este é o nó raiz da árvore de busca.
min: Este é o nó com o menor custo total estimado na fila de prioridade.
A função findMinCost usa o método Branch and Bound para encontrar a atribuição de trabalhos a trabalhadores que minimiza o custo total. Ela retorna o custo mínimo encontrado.
*/
struct Node {
    Node* parent;
    int pathCost;
    int cost;
    int workerID;
    int jobID;
    bool assigned[N];
};

Node* newNode(int x, int y, bool assigned[], Node* parent) {
    Node* node = new Node;
    for (int j = 0; j < N; j++)
        node->assigned[j] = assigned[j];
    node->assigned[y] = true;
    node->parent = parent;
    node->workerID = x;
    node->jobID = y;
    return node;
}

int calculateCost(int costMatrix[N][N], int x, int y, bool assigned[]) {
    int cost = 0;
    bool available[N] = {true};
    for (int i = x + 1; i < N; i++) {
        int min = INT_MAX, minIndex = -1;
        for (int j = 0; j < N; j++) {
            if (!assigned[j] && available[j] && costMatrix[i][j] < min) {
                minIndex = j;
                min = costMatrix[i][j];
            }
        }
        cost += min;
        available[minIndex] = false;
    }
    return cost;
}

struct comp {
    bool operator()(const Node* lhs, const Node* rhs) const {
        return lhs->cost > rhs->cost;
    }
};

void printAssignments(Node *min) {
    if(min->parent==NULL)
        return;
    printAssignments(min->parent);
    cout << "Assign Worker " << char(min->workerID + 'A') << " to Job " << min->jobID << endl;
}

int findMinCost(int costMatrix[N][N]) {
    priority_queue<Node*, std::vector<Node*>, comp> pq;
    bool assigned[N] = {false};
    Node* root = newNode(-1, -1, assigned, NULL);
    root->pathCost = root->cost = 0;
    root->workerID = -1;
    pq.push(root);
    while (!pq.empty()) {
      Node* min = pq.top();
      pq.pop();
      int i = min->workerID + 1;
      if (i == N) {
          printAssignments(min);
          return min->cost;
      }
      for (int j = 0; j < N; j++) {
        if (!min->assigned[j]) {
          Node* child = newNode(i, j, min->assigned, min);
          child->pathCost = min->pathCost + costMatrix[i][j];
          child->cost = child->pathCost + calculateCost(costMatrix, i, j, child->assigned);
          pq.push(child);
        }
      }
    }
}

int main() {
    int costMatrix[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };
    cout << "\nOptimal Cost is " << findMinCost(costMatrix);
    return 0;
}