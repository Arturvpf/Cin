#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Graph class to represent the teams and their relationships
class Graph {
private:
    vector<vector<int>> adjList;
    vector<string> names;

public:
    Graph(int numVertices) {
        adjList.resize(numVertices);
        names.resize(numVertices);
    }

    // Add an edge between two team members
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Perform BFS traversal to calculate the ranking numbers
    vector<int> calculateRankings(int start) {
        vector<int> rankings(adjList.size(), -1);
        queue<int> q;
        q.push(start);
        rankings[start] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbor : adjList[curr]) {
                if (rankings[neighbor] == -1) {
                    rankings[neighbor] = rankings[curr] + 1;
                    q.push(neighbor);
                }
            }
        }

        return rankings;
    }

    const string& getName(int index) {
        return names[index];
    }

    void setName(int index, const string& name) {
        names[index] = name;
    }
};

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        Graph graph(N * 3);
        vector<int> rankings;

        for (int i = 0; i < N; i++) {
            string member1, member2, member3;
            cin >> member1 >> member2 >> member3;

            int index1 = i * 3;
            int index2 = i * 3 + 1;
            int index3 = i * 3 + 2;

            graph.setName(index1, member1);
            graph.setName(index2, member2);
            graph.setName(index3, member3);

            graph.addEdge(index1, index2);
            graph.addEdge(index1, index3);
            graph.addEdge(index2, index3);
        }

        int start = 0;
        rankings = graph.calculateRankings(start);

        // Sort the contestants lexicographically by name
        vector<int> contestants;
        for (int i = 0; i < rankings.size(); i++) {
            contestants.push_back(i);
        }
        sort(contestants.begin(), contestants.end(), [&](int a, int b) {
            return graph.getName(a) < graph.getName(b);
        });

        cout << contestants.size() << endl;
        for (int contestant : contestants) {
            cout << graph.getName(contestant) << " ";
            if (rankings[contestant] == 0) {
                cout << "0" << endl;
            } else if (rankings[contestant] == 1) {
                cout << "1" << endl;
            } else {
                cout << "undefined" << endl;
            }
        }
    }

    return 0;
}
