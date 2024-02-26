#include <climits>
#include <vector>
#include <queue>
#include <iostream>
#include <stack>
#include <list>

using namespace std;

#define UNVISITED 0
#define VISITED 1

#define INF INT_MAX
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
        void toposort(int v, stack<int>&s) {//for DFS 
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
        void Dijkstra(int s, vector<int> &D) {
            D.resize(numVertices);
            vector<int> P(numVertices);
            for(int i=0;i<numVertices;i++){
                D[i]=INF; P[i]=-1;
                marks[i]=UNVISITED;
            }
            
            D[s]=0;

            
        }
};


int main(){
    cout<<"teste"<<endl;
}