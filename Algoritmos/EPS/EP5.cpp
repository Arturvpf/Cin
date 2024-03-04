#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include <climits>
#include <vector>

using namespace std;

class Graph
{
private:
    int v;          // number of vertices
    list<int> *adj; // Pointer to an array containing adjacency lists

public:
    int *marks;
    Graph(int vertices);
    void setEdge(int, int);
    void BFS(int);
    void DFS(int);
    void searchSub();
    int first(int);
    int next(int, int);
    int countConnectedComponents();
    ~Graph(); // Destructor to deallocate memory
};

Graph::Graph(int vertices)
{
    v = vertices;
    adj = new list<int>[v];
    marks = new int[v];
}

void Graph::setEdge(int v, int w)
{
    adj[v].push_back(w); // add w to v's list
    adj[w].push_back(v); // add v to w's list for an undirected graph
}

int Graph::first(int v)
{
    if (!adj[v].empty())
        return adj[v].front();
    return v; // Indicates no adjacent vertex
}

int Graph::next(int v, int w)
{
    auto it = adj[v].begin();
    while (it != adj[v].end())
    {
        if (*it == w && ++it != adj[v].end())
        {
            return *it;
        }
        it++;
    }
    return v; // Indicates no more adjacent vertices
}

void Graph::BFS(int start)
{
    queue<int> Q;
    Q.push(start);
    marks[start] = 1; // Marcando o vértice inicial como visitado

    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        for (int w : adj[v])
        {
            if (marks[w] == 0)
            {
                marks[w] = 1; // Marcando o vértice como visitado antes de enfileirar
                Q.push(w);
            }
        }
    }
}


void Graph::DFS(int n)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;

    stack<int> s;
    visited[n] = true;
    s.push(n);

    list<int>::iterator i;

    while (!s.empty())
    {
        n = s.top();
        s.pop();
        for (i = adj[n].begin(); i != adj[n].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                s.push(*i);
            }
        }
    }

    delete[] visited;
}

int Graph::countConnectedComponents()
{
    int count = 0;
    for (int i = 0; i < v; i++)
    {
        if (marks[i] == 0)
        {
            BFS(i);
            count++;
        }
    }
    return count;
}

void Graph::searchSub()
{
    cout << countConnectedComponents() << endl;
}

Graph::~Graph()
{
    delete[] adj;
    delete[] marks;
}

int main()
{
    int c;
    cin >> c;
    for (int L = 0; L < c; L++)
    {
        int v, e;
        cin >> v >> e; //vertices and edges
        Graph g(v);    // Create a fresh graph object for each test case
        int i, j;
        for (int k = 0; k < e; k++)
        {
            cin >> i >> j;
            g.setEdge(i, j); // Set edges in the graph
        }
        g.searchSub();
    }
    return 0;
}
