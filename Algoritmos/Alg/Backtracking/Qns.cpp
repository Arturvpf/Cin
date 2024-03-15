#include <iostream>
#define N 4
/*
Na função valid:

M[N][N]: Esta é a matriz que representa o tabuleiro de xadrez. Se M[i][j] é 1, então uma rainha está presente na posição (i, j). Se M[i][j] é 0, então a posição (i, j) está vazia.
row e col: Estas são as coordenadas da posição atual no tabuleiro. A função valid verifica se é seguro colocar uma rainha na posição (row, col).
Na função qns:

l: Este é o índice da coluna atual. A função qns tenta colocar uma rainha em cada linha da coluna l.
M[N][N]: Esta é a matriz que representa o tabuleiro de xadrez, da mesma forma que na função valid.
*/
using namespace std;

bool valid(int M[N][N], int row, int col) {
    for (int i = 0; i < col; i++)
        if (M[row][i])
            return false;
    for (int i=row, j=col; i>=0 && j>=0; i--, j--)
        if (M[i][j])
            return false;
    for (int i=row, j=col; j>=0 && i<N; i++, j--)
        if (M[i][j])
            return false;
    return true;
}

bool qns(int l, int M[N][N]) {
    if (l >= N)
        return true;
    for (int i = 0; i < N; i++) {
        if (valid(M, l, i)) {
            M[l][i] = 1;
            if (qns(l + 1, M))
                return true;
            M[l][i] = 0;
        }
    }
    return false;
}

int main() {
    int M[N][N] = { {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0} };

    if (qns(0, M) == false) {
        cout << "Solution does not exist";
        return false;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }

    return 0;
}