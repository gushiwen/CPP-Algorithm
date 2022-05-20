#include <iostream>
#include <vector>
#include <string>
using namespace std;

void backtracking(vector< vector<string> >& answer, vector<string>& board, int n, int row, vector<bool>& column, vector<bool>& ldiag, vector<bool>& rdiag) {
    if(row == n) {
        answer.push_back(board);
        return;
    }
    for(int j = 0; j < n; ++j) {
        if(column[j] || ldiag[n-1-row+j] || rdiag[row+j]) {
            continue;
        }
        board[row][j] = 'Q';
        column[j] = true;
        ldiag[n-1-row+j] = true;
        rdiag[row+j] = true;
        // backtracking(answer, board, n, row - 1, column, ldiag, rdiag);
        backtracking(answer, board, n, row + 1, column, ldiag, rdiag);
        board[row][j] = '.';
        column[j] = false;
        ldiag[n-1-row+j] = false;
        rdiag[row+j] = false;
    }
}

vector< vector<string> > solveQueens(int n) {
    vector< vector<string> > answer;
    if (n == 0) {
        return answer;
    }
    vector<string> board(n, string(n, '.'));
    vector<bool> column(n, false);
    vector<bool> ldiag(2*n - 1, false);
    vector<bool> rdiag(2*n - 1, false);
    backtracking(answer, board, n, 0, column, ldiag, rdiag);
    return answer;
}

int main() {
    int n = 4;
    vector< vector<string> > answer = solveQueens(n);
    for (auto i : answer) {
        for (auto j : i) {
            cout << j << endl;
        }
        cout << endl;
    }
    return 0;
}