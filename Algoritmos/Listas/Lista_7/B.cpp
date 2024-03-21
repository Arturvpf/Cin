#include <iostream>
#include <vector>

using namespace std;

bool backtrack(vector<vector<char>>& maze, vector<vector<bool>>& visited, int x, int y, int spikes) {
    int n = maze.size();
    int m = maze[0].size();

    if (x < 0 || x >= n || y < 0 || y >= m || spikes < 0 || maze[x][y] == '#' || visited[x][y]) {
        return false;
    }
    if (maze[x][y] == 'x') {
        return true;
    }
    visited[x][y] = true;

    if (backtrack(maze, visited, x + 1, y, (maze[x][y] == 's') ? spikes - 1 : spikes) ||
        backtrack(maze, visited, x - 1, y, (maze[x][y] == 's') ? spikes - 1 : spikes) ||
        backtrack(maze, visited, x, y + 1, (maze[x][y] == 's') ? spikes - 1 : spikes) ||
        backtrack(maze, visited, x, y - 1, (maze[x][y] == 's') ? spikes - 1 : spikes)) {
        return true;
    }

    visited[x][y] = false;

    return false;
}

string solveMaze(vector<vector<char>>& maze, int spikes) {  
    int n = maze.size();
    int m = maze[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '@') {
                if (backtrack(maze, visited, i, j, spikes)) {
                    return "SUCCESS";
                }
            }
        }
    }

    return "IMPOSSIBLE";
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

    string result = solveMaze(maze, j / 2); // Dividindo o número de spikes por 2
    cout << result<<endl;

    return 0;
}
