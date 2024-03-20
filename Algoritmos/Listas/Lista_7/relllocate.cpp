#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool isValid(int x, int y, int n, const vector<vector<int>>& chessboard) {
    return x >= 0 && x < n && y >= 0 && y < chessboard[x].size();
}

int countUnreachableSquares(int x, int y, int n, vector<vector<int>>& chessboard) {
    int count = 0;
    chessboard[x][y] = -1; // Mark the current square as visited

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isValid(nx, ny, n, chessboard) && chessboard[nx][ny] != -1) {
            count += countUnreachableSquares(nx, ny, n, chessboard);
        }
    }

    return count + 1;
}

int main() {
    int caseNumber = 1;
    int n;

    while (cin >> n && n != 0) {
        vector<vector<int>> chessboard(n);

        for (int i = 0; i < n; i++) {
            int skip, squares;
            cin >> skip >> squares;

            chessboard[i].resize(squares);
        }

        int unreachableSquares = countUnreachableSquares(0, 0, n, chessboard);

        cout << "Case " << caseNumber << ", " << unreachableSquares << " squares can not be reached." << endl;

        caseNumber++;
    }

    return 0;
}
