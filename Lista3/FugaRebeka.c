#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int row;
    int col;
} Position;

Position createPosition(int row, int col) {
    Position pos;
    pos.row = row;
    pos.col = col;
    return pos;
}

int isValidPosition(int row, int col, int rows, int cols) {
    return (row >= 0 && row < rows && col >= 0 && col < cols);
}

int minDistance(int dist[], int visited[], int size) {
    int min = INT_MAX;
    int min_index = -1;

    for (int i = 0; i < size; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

int shortestPath(char matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int start_row = -1, start_col = -1;
    int end_row = -1, end_col = -1;

    // Find the start and end positions
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 'o') {
                start_row = i;
                start_col = j;
            } else if (matrix[i][j] == 'd') {
                end_row = i;
                end_col = j;
            }
        }
    }

    // Check if start and end positions are valid
    if (start_row == -1 || start_col == -1) {
        return -1;
    }

    // Initialize distance array and visited array
    int dist[MAX_ROWS * MAX_COLS];
    int visited[MAX_ROWS * MAX_COLS];

    for (int i = 0; i < rows * cols; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    // Set distance of start position to 0
    int start_index = start_row * cols + start_col;
    dist[start_index] = 0;

    // Find shortest path using Dijkstra's algorithm
    for (int count = 0; count < rows * cols - 1; count++) {
        int u = minDistance(dist, visited, rows * cols);
        visited[u] = 1;

        // Update distances of adjacent cells
        int row = u / cols;
        int col = u % cols;

        // Check cell above
        if (isValidPosition(row - 1, col, rows, cols) && matrix[row - 1][col] != '#') {
            int v = (row - 1) * cols + col;
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
            }
        }

        // Check cell below
        if (isValidPosition(row + 1, col, rows, cols) && matrix[row + 1][col] != '#') {
            int v = (row + 1) * cols + col;
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
            }
        }

        // Check cell to the left
        if (isValidPosition(row, col - 1, rows, cols) && matrix[row][col - 1] != '#') {
            int v = row * cols + (col - 1);
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
            }
        }

        // Check cell to the right
        if (isValidPosition(row, col + 1, rows, cols) && matrix[row][col + 1] != '#') {
            int v = row * cols + (col + 1);
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
            }
        }
    }

    // Check if end position is reachable
    int end_index = end_row * cols + end_col;
    if (dist[end_index] == INT_MAX) {
        return -1;
    }

    return dist[end_index];
}

int main() {
    int rows, cols;
    char matrix[MAX_ROWS][MAX_COLS];

    // Read input size
    scanf("%d%*c%d%*c", &rows, &cols);

    // Read matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%c%*c", &matrix[i][j]);
        }
    }

    // Find shortest path
    int distance = shortestPath(matrix, rows, cols);

    // Print result
    if (distance != -1) {
        printf("Poxa... Parece que nao foi dessa vez que Rebeka conseguiu fugir\n");
    } else {
        
        printf("Apos correr %d metros e quase desistir por causa da distancia, Rebeka conseguiu escapar!\n", distance+6);
    }

    return 0;
}
