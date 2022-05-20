#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(int i, int j, int m, int n, vector< vector<int> >& islands, queue< pair<int, int> >& points) {
    if(i < 0 || i >= islands.size() || j < 0 || j >= islands.size() || islands[i][j] == 2) {
        return;
    }
    if (islands[i][j] == 0) {
        // record the positions to leave this island
        points.push({i, j});
        islands[i][j] = 2;
        cout << "(" << i << ", " << j << ") ";
        return;
    }
    islands[i][j] = 2;
    dfs(i - 1, j, m, n, islands, points);
    dfs(i + 1, j, m, n, islands, points);
    dfs(i, j - 1, m, n, islands, points);
    dfs(i, j + 1, m, n, islands, points);

}

int shortestPath(vector< vector<int> >& islands) {
    int m = islands.size();
    int n = islands[0].size();
    // vector< vector<bool> > visited(m, vector<bool>(n, false));
    queue< pair<int, int> > points;
    
    // dfs to find the 1st island and mark it
    bool foundFirst = false;
    for(int i = 0; i < m; ++i) {
        if (foundFirst) break;
        for(int j = 0; j < n; ++j) {
            // touch the 1st idland
            if (!foundFirst && islands[i][j] == 1) {
                // dfs this island
                dfs(i, j, m, n, islands, points);
                foundFirst = true;
                break;
            }
        }
    }

    cout << endl;
    for (auto i : islands) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    // bfs to find the 2nd island
    int x, y;
    int level = 0;
    vector<int> direction{-1, 0, 1, 0, -1};

    while (!points.empty()) {
        ++level;
        int pointersLength = points.size();
        while (pointersLength--) {
            auto [r, c] = points.front();
            points.pop();
            for (int k = 0; k < 4; ++k) {
                x = r + direction[k], y = c + direction[k+1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (islands[x][y] == 2) {
                        continue;
                    }
                    if (islands[x][y] == 1) {
                        cout << endl;
                        for (auto i : islands) {
                            for (auto j : i) {
                                cout << j << " ";
                            }
                            cout << endl;
                        }
                        return level;
                    }
                    points.push({x, y});
                    cout << "(" << x << ", " << y <<") ";
                    islands[x][y] = 2;
                }

            }
        }

    }

    return 0;
}
int main() {
    vector< vector<int> > islands{
        {1,1,1,1,1},
        {1,0,0,0,1},
        {1,0,1,0,1},
        {1,0,0,0,1},
        {1,1,1,1,1}
    };
    cout << shortestPath(islands);
    return 0;
}