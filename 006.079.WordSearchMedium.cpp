#include <iostream>
#include <vector>
using namespace std;

void backtracking(int i, int j, vector< vector<char> >& board, string& word, bool& find, vector< vector<bool> >& visited, int& pos) {
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j]) {
        return;
    }
    if(find || board[i][j] != word[pos]) {
        return;
    }
    if(pos == word.length() - 1) {
        find = true;
    }
    visited[i][j] = true;
    ++pos;
    backtracking(i - 1, j, board, word, find, visited, pos);
    backtracking(i, j + 1, board, word, find, visited, pos);
    backtracking(i + 1, j, board, word, find, visited, pos);
    backtracking(i, j - 1, board, word, find, visited, pos);
    visited[i][j] = false;
    --pos;
}

bool exist(vector< vector<char> >& board, string word) {
    if(board.empty()) return false;
    bool find = false;
    int m = board.size();
    int n = board[0].size();
    vector< vector<bool> > visited(m, vector<bool>(n, false));
    int pos = 0;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            backtracking(i, j, board, word, find, visited, pos);
        }
    }


    return find;
}

int main() {
    vector< vector<char> > board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };
    string word = "ABCCEA";
    cout << exist(board, word) << endl;
    return 0;
}