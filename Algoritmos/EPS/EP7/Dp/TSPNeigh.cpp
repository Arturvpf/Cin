#include <iostream>
#include <vector>
#include <climits>
/*
Na função nearestNeighbour:

graph: É uma matriz de adjacência que representa o grafo, onde graph[i][j] é a distância entre a cidade i e a cidade j.
startNode: É a cidade onde o caixeiro viajante começa.
visited: É um vetor que mantém o controle de quais cidades já foram visitadas.
totalDistance: É a distância total do ciclo encontrado.
currentNode: É a cidade atual que o caixeiro viajante está visitando.
nearestNode: É a cidade mais próxima ainda não visitada.
shortestDistance: É a distância mais curta para a cidade mais próxima ainda não visitada.
Na função main:

graph: É uma matriz de adjacência que representa o grafo, onde graph[i][j] é a distância entre a cidade i e a cidade j.
totalDistance: É a distância total do ciclo encontrado pelo algoritmo do vizinho mais próximo.
Além disso, INT_MAX é uma constante que representa o maior valor possível para um int. É usada para inicializar shortestDistance para garantir que qualquer distância no grafo será menor que shortestDistance na primeira comparação.
*/

int nearestNeighbour(std::vector<std::vector<int>>& graph, int startNode) {
    std::vector<bool> visited(graph.size(), false);
    visited[startNode] = true;

    int totalDistance = 0;
    int currentNode = startNode;

    std::cout << startNode << " ";

    for (int count = 0; count < graph.size() - 1; count++) {
        int nearestNode = -1;
        int shortestDistance = INT_MAX;

        for (int adjNode = 0; adjNode < graph.size(); adjNode++) {
            if (!visited[adjNode] && graph[currentNode][adjNode] < shortestDistance) {
                nearestNode = adjNode;
                shortestDistance = graph[currentNode][adjNode];
            }
        }

        totalDistance += shortestDistance;
        visited[nearestNode] = true;
        currentNode = nearestNode;

        std::cout << nearestNode << " ";
    }

    totalDistance += graph[currentNode][startNode]; // Return to start node

    std::cout << startNode << std::endl; // Print start node again to show full cycle

    return totalDistance;
}

int main() {
    std::vector<std::vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int totalDistance = nearestNeighbour(graph, 0);

    std::cout << "Total distance: " << totalDistance << std::endl;

    return 0;
}