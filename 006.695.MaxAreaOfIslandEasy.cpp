#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(vector< vector<int> >& grid, int r, int c){
    if(r < 0 || r > grid.size() -1 || c < 0 || c > grid[0].size() -1 || grid[r][c] == 0) {
        return 0;
    }
    if(grid[r][c] == 1) {
        grid[r][c] = 0;
        return 1 + dfs(grid, r-1, c) + dfs(grid, r, c+1) + dfs(grid, r+1, c) + dfs(grid, r, c-1);
    }
    return 0;
}

int maxAreaOfIsland(vector< vector<int> >& grid) {
    if(grid.empty() || grid[0].empty()) return 0;
    int maxArea = 0;
    for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[0].size(); ++j){
            maxArea = max(maxArea, dfs(grid, i, j));
        }
    }
    return maxArea;
}

int main() {
    vector< vector<int> > grid = {
        {1,0,1,1,0,1,0,1},
        {1,0,1,1,0,1,1,1},
        {0,0,0,0,0,0,0,1}
    };
    cout << maxAreaOfIsland(grid) << endl;
}