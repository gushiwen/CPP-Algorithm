#include <iostream>
#include <vector>
using namespace std;

void dfs(vector< vector<int> >& friends, int i, vector<bool>& visited) {
    visited[i] = true;
    for(int j = 0; j < friends.size(); ++j) {
        if(friends[i][j] == 1 && !visited[j]) {
            dfs(friends, j, visited);
        }
    }
}

int friendCircleNum(vector< vector<int> >& friends) {
    int n = friends.size(), counter = 0;
    vector<bool> visited(n, false);
    for(int i = 0; i < friends.size(); ++i){
        if(!visited[i]) {
            dfs(friends, i, visited);
            ++counter;
        }

    }
    return counter;
}

int main() {
    vector< vector<int> > friends = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };
    cout << friendCircleNum(friends) << endl;
    return 0;
}