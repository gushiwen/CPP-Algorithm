#include <iostream>
#include <vector>
using namespace std;


void backtracking(vector<int>& nums, int level, vector< vector<int> >& results){
    int len = nums.size();
    if(level == len - 1) {
        results.push_back(nums);
        return;
    }
    for(int i = level; i < len; ++i){
        swap(nums[level], nums[i]);
        backtracking(nums, level + 1, results);
        swap(nums[i], nums[level]);
    }
}

vector<vector<int> > permute(vector<int>& nums) {
    vector< vector<int> > results;
    backtracking(nums, 0, results);
    return results;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector< vector<int> > results = permute(nums);
    for(auto i : results) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}