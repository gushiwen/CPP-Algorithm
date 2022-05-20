#include <iostream>
#include <vector>
using namespace std;

int dfs(vector< vector<int> >& altitudeList, int row, int col, int prevAltitude) {
    int m = altitudeList.size();
    int n = altitudeList[0].size();
    if (row < 0 || row >= m || col < 0 || col >= n || altitudeList[row][col] > prevAltitude) {
        return 0;
    }
    if (row == 0 || col == 0) return 1;
    if (row == m-1 || col == n-1) return 1;

    return dfs(altitudeList, row-1, col, altitudeList[row][col]) + dfs(altitudeList, row, col+1, altitudeList[row][col]) + dfs(altitudeList, row+1, col, altitudeList[row][col]) + dfs(altitudeList, row, col-1, altitudeList[row][col]);
}

void searchPosition(vector< vector<int> >& altitudeList) {
    int m = altitudeList.size();
    int n = altitudeList[0].size();
    cout << "m:" << m << " " << "n:" << n << endl;

    vector< vector<int> > positionStatus(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            positionStatus[i][j] = dfs(altitudeList, i, j, INT_MAX);
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            //if (positionStatus[i][j] >= 2) {
                //cout << "[" << i << ", " << j << "] ";
            //}
            cout << positionStatus[i][j] << " ";
        }
        cout << endl;
    }
}



int main() {
    vector< vector<int> > altitudeList = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };
    searchPosition(altitudeList);

    return 0;
}