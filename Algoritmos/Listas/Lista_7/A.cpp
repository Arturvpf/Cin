#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//possiveis direcoes do cavalo
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool isValid(pair<int,int>pos, int n, int m, vector<vector<bool>>& board, vector<vector<bool>>& visited) {
    int x=pos.first;
    int y=pos.second;
    // Verifique se a posição está dentro do tabuleiro
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }
    // Verifique se o cavaleiro pode se mover para a posição
    if (!board[x][y] || visited[x][y]) {
        return false;
    }
    return true;
}
void backtrack(vector<vector<bool>>& board, vector<vector<bool>>& visited, pair<int,int> pos, int& accessible) {
    int x=pos.first;
    int y=pos.second;
    visited[x][y] = true;
    accessible++;

    // Tente mover o cavaleiro para todas as direções possíveis
    for (int i = 0; i < 8; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        // Se a nova célula é válida, não foi visitada e está no tabuleiro, mova o cavaleiro para lá
        if (isValid(make_pair(newX, newY), board.size(), board[0].size(), board, visited)) {
            backtrack(board, visited, make_pair(newX, newY), accessible);
        }
    }
    
    
}


int intializeTable(vector<pair<int,int>> v,int n)
{
    vector<vector<bool>> board(10, vector<bool>(10, false));
    int totalSquares = 0;
    for (int i = 0; i < n; i++) {
    for (int j = v[i].first; j < min(v[i].first + v[i].second, 10); j++) {
        board[i][j] = true;
        totalSquares++;
    }
}
    vector<vector<bool>> visited(10, vector<bool>(10, false));
    int accessible = 0;
    backtrack(board, visited, make_pair(0,0), accessible);
    return totalSquares-accessible;

}

int main() {
    vector<int> Case;
    
    while(true) {
        Case.resize(Case.size() + 1); //resize the vector to add a new element 
        int n;
        cin >> n;

        if(n == 0) break;

        vector<pair<int,int>> v(n); //first integer of each pair indicates the number of squares skipped at the beginning of the row
        for(int i = 0; i < n; i++){ //second integer indicates the number of squares in the row
            cin >> v[i].first >> v[i].second;
        }
        pair<vector<vector<bool>>, int> result = initializeTable(v, n);
        vector<vector<bool>> board = result.first;
        int totalSquares = result.second;
        vector<vector<bool>> visited(10, vector<bool>(10, false));
        int accessible = 0;
        backtrack(board, visited, make_pair(0,0), accessible);
        Case.back() = totalSquares - accessible;
    }
    for(int i=0; i<Case.size()-1; i++){
        cout<<"Case " << i+1<<", " << Case[i]<<" squares can not be reached." << endl;
    }
}