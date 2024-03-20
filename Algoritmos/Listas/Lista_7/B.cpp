#include <iostream>
#include <vector>

using namespace std;

// Function to check if the given position is valid
bool isValid(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

// Backtracking function
bool backtrack(vector<vector<char>>& maze, vector<vector<bool>>& visited, int x, int y, int j) {
    int n = maze.size();
    int m = maze[0].size();

    // Base cases
    if (!isValid(x, y, n, m) || maze[x][y] == '#' || visited[x][y] || j < 0) {
        return false;
    }
    //Este é um caso base para a função de backtracking. Se a posição atual (x, y) não for válida (ou seja, fora dos limites do labirinto ou já visitada) 
    //ou se a posição atual for um obstáculo ('#') ou se o contador j for menor que 0, a função retorna false.

    if (maze[x][y] == 'x') {
        return true;
    }
    //Este é outro caso base. Se a posição atual (x, y) for o destino ('x'), a função retorna true.

    // Mark the current position as visited
    visited[x][y] = true;
    //Aqui, a posição atual (x, y) é marcada como não visitada. Isso é feito para que outros caminhos possíveis 
    //possam passar por essa posição.
    // Recursive calls in all four directions
    bool result = backtrack(maze, visited, x + 1, y, j - 1) ||
                  backtrack(maze, visited, x - 1, y, j - 1) ||
                  backtrack(maze, visited, x, y + 1, j - 1) ||
                  backtrack(maze, visited, x, y - 1, j - 1);
                  /*Aqui, a função faz chamadas recursivas em todas as quatro direções (para cima, para baixo, para a esquerda e para a direita). 
                  Se qualquer uma dessas chamadas retornar true, a função também retornará true.*/

    // Mark the current position as unvisited
    visited[x][y] = false;

    return result;
}

// Function to solve the maze problem
string solveMaze(vector<vector<char>>& maze, int j) {  /*Esta é a função principal que resolve o problema do labirinto.
                                                        Ela recebe o labirinto e um contador j como entrada. A variável n 
                                                        é usada para armazenar o tamanho do labirinto.*/
    int n = maze.size();
    int m = maze[0].size();

    // Find the starting position
    int startX, startY;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '@') {
                startX = i;
                startY = j;
                break;
            }
        }
    }

    // Create a visited matrix to keep track of visited positions
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // Call the backtracking function to check if Jarmtin can make it through
    if (backtrack(maze, visited, startX, startY, j)) {
        return "SUCCESS";
    } else {
        return "IMPOSSIBLE";
    }
}

int main() {
    int n, m, j;
    cin >> n >> m >> j;

    vector<vector<char>> maze(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    string result = solveMaze(maze, j);
    cout << result << endl;

    return 0;
}
