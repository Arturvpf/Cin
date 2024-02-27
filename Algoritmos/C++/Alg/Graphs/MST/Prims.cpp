#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Graph class to represent the graph
class Graph {
private:
    int numVertices;
    vector<vector<pair<int, int>>> adjacencyList;

public:
    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjacencyList.resize(numVertices);
    }

    void addEdge(int u, int v, int weight) {
        adjacencyList[u].push_back(make_pair(v, weight));
        adjacencyList[v].push_back(make_pair(u, weight));
    }

    vector<pair<int, int>>& getNeighbors(int vertex) {
        return adjacencyList[vertex];
    }
    int getNumVertices() {
        return numVertices;
    }
};

// Function to implement Prim's algorithm
void prim(Graph& G, vector<int>& D, vector<int>& V) { // D is the distance array and V is the visited array
    int n = G.getNumVertices();

    // Initialize distance and visited arrays
    for (int i = 0; i < n; i++) {
        D[i] = INT_MAX;
        V[i] = -1;
    }

    // Create a priority queue to store vertices with their distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start with vertex 0
    D[0] = 0;
    pq.push(make_pair(0, 0));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // If the vertex is already visited, skip it
        if (V[u] != -1) {
            continue;
        }

        // Mark the vertex as visited
        V[u] = 1;

        // Process all neighbors of the current vertex
        for (auto neighbor : G.getNeighbors(u)) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // If the neighbor is not visited and the weight is smaller than the current distance, update the distance
            if (V[v] == -1 && D[v] > weight) {
                D[v] = weight;
                pq.push(make_pair(D[v], v));
            }
        }
    }
}

int main() {
    int numVertices = 5;
    Graph G(numVertices);

    // Add edges to the graph
    G.addEdge(0, 1, 2);
    G.addEdge(0, 3, 6);
    G.addEdge(1, 2, 3);
    G.addEdge(1, 3, 8);
    G.addEdge(1, 4, 5);
    G.addEdge(2, 4, 7);
    G.addEdge(3, 4, 9);

    vector<int> D(numVertices);
    vector<int> V(numVertices);

    prim(G, D, V);

    // Print the minimum spanning tree
    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 1; i < numVertices; i++) {
        cout << V[i] << " - " << i << " : " << D[i] << endl;
    }

    return 0;
}