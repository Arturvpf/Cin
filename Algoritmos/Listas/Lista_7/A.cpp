#include <iostream>
#include <vector>
using namespace std;

bool Valid(int x, int y, int N, vector<pair<int, int>>& row) {
    if (x < 1 || x > N || y < row[x].first || y > row[x].second)
    	return false;

    return true;
}

void BackTracking(int x, int y, int CurrCount, int N, vector<vector<bool>>& Board, vector<pair<int, int>>& row, int& Count) {
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    if (CurrCount > Count)
        Count = CurrCount;

    for (int d = 0; d < 8; d++) {
        int newX = x + dx[d];
        int newY = y + dy[d];

        if (Valid(newX, newY, N, row) && !Board[newX][newY]) {
            Board[newX][newY] = true;
            BackTracking(newX, newY, CurrCount + 1, N, Board, row, Count);
            Board[newX][newY] = false;
        }
    }
}

void PrintSquares(int t, int TotalSquares, int Count) {
    cout << "Case " << t << ", " << TotalSquares - Count;
    ((TotalSquares - Count) == 1) ? cout << " square" : cout << " squares";
    cout << " can not be reached." << endl;
}

int main() {
    int N;
    int t = 1;

    cin >> N;

    while (N) {//quando n for 0, o while sai
        vector<pair<int, int>> row(N + 1);
        vector<vector<bool>> Board(N + 1, vector<bool>(N + 1));
        int TotalSquares = 0;
        int Count = 0;

        for (int i = 1; i <= N; i++) {
            int col, tam;
            cin >> col >> tam;
            row[i] = make_pair(col + 1, col + tam);
            TotalSquares += tam;

            for (int j = row[i].first; j <= row[i].second; j++) {
                Board[i][j] = false;
            }
        }

        Board[1][1] = true;
        BackTracking(1, 1, 1, N, Board, row, Count);

        PrintSquares(t, TotalSquares, Count);
		t++;
        cin >> N;
    }

    return 0;
}
