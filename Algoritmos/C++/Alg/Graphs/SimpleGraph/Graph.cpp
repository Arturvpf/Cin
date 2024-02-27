#include <iostream>
#include <vector>
#include <list>
#include <stack>
#define UNVISITED 0
#define VISITED 1
using namespace std;

class Graph {
    private:
        int numVertices;
        vector<vector<int>> Matrix; //Adjacency matrix
        vector<int> marks;
        int numEdge;
    public:
        
        void nEdge() {
            int count = 0;
            for (int i = 0; i < numVertices; i++) {
                for (int j = 0; j < numVertices; j++) {
                    if (Matrix[i][j] != 0) {
                        count++;
                    }
                }
            }
            numEdge= count;
        }
        void create_Graph(int n) {
            marks.resize(n);
            Matrix.resize(n, vector<int>(n));
            numVertices = n;
            numEdge = 0;
        }
        int first(int v) {  
            for (int i = 0; i < numVertices; i++) {
                if (Matrix[v][i] != 0) {
                    return i;
                }
            }
            return numVertices;
        }
        int next(int v, int w) { 
            for (int i = w + 1; i < numVertices; i++) {
                if (Matrix[v][i] != 0) {
                    return i;
                }
            }
            return numVertices;
        }
        void setEdge(int i, int j) {
            
            int weight=Graph::weight(i,j);
            if(weight==0){
                return;
            }
            if (Matrix[i][j] == 0) {
                numEdge++;
            }
            Matrix[i][j] = weight;
        }
        void delEdge(int i, int j) {
            if (Matrix[i][j] != 0) {
                numEdge--;
            }
            Matrix[i][j] = 0;
        }
        int getV() {
            return numVertices;
        }
        void graphTraverse() {
            for (int i = 0; i < numVertices; i++) {
                marks[i] = UNVISITED;
            }
            for (int i = 0; i < numVertices; i++) {
                if (marks[i] == UNVISITED) {
                    DFS(i);//DFS or BFS
                }
            }
        }
        bool isEdge(int i, int j) {
            return Matrix[i][j] != 0;
        }
        int weight(int i, int j) {  
            return Matrix[i][j];
        }
        void DFS(int v) {   
            marks[v] = VISITED;
            for (int w = first(v); w < numVertices; w = next(v, w)) {
                if (marks[w] == UNVISITED) {
                    DFS(w);
                }
            }
        }
        int getMark(int i) {
            return marks[i];
        }
        void BFS(int start) {   
            vector<int> queue;
            for (int i = 0; i < numVertices; i++) {
                marks[i] = UNVISITED;
            }
            queue.push_back(start);
            marks[start] = VISITED;
            while (!queue.empty()) {
                int v = queue.front();
                queue.erase(queue.begin());
                for (int w = first(v); w < numVertices; w = next(v, w)) {
                    if (marks[w] == UNVISITED) {
                        marks[w] = VISITED;
                        queue.push_back(w);
                    }
                }
            }
        }
        void toposort(int v, stack<int>& s) {//for DFS 
            marks[v] = VISITED;
            int w=first(v);
            while(w<numVertices){
                if(marks[w]==UNVISITED){
                    toposort(w,s);
                }
                w=next(v,w);
            }
            s.push(v);
        }
};
int main() {
    Graph g;
    g.create_Graph(5); // Cria um grafo com 5 vértices

    // Adiciona algumas arestas ao grafo
    g.setEdge(0, 1);
    g.setEdge(0, 2);
    g.setEdge(1, 3);
    g.setEdge(2, 3);
    g.setEdge(3, 4);

    // Testa a função DFS
    cout << "DFS a partir do vértice 0:" << endl;
    g.DFS(0);
    cout << endl;

    // Testa a função BFS
    cout << "BFS a partir do vértice 0:" << endl;
    g.BFS(0);
    cout << endl;

    // Testa a função toposort
    cout << "Ordenação topológica do grafo:" << endl;
    stack<int> s;
    for (int i = 0; i < g.getV(); i++) {
        if (g.getMark(i) == UNVISITED) {
            g.toposort(i, s);
        }
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}


