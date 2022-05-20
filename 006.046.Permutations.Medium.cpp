#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > permute(vector<int> nums);
void backtracking(vector<int>& nums, int level, vector< vector<int> >& ans);

int main() {
    vector<int> nums = {1, 2, 3};
    vector< vector<int> > ans = permute(nums);

    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[0].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

vector< vector<int> > permute(vector<int> nums) {
    vector< vector<int> > ans;
    backtracking(nums, 0, ans);
    return ans;
}

void backtracking(vector<int>& nums, int level, vector< vector<int> >& ans) {
    if (level == nums.size() - 1) {
        ans.push_back(nums);

        cout << "ans.push_back(\"[";
        for (int i = 0; i < nums.size(); ++i) {
            cout << nums[i];
            if (i < nums.size() - 1) cout << " ";
        }
        cout << "]\")" << endl;

        return;
    }

    for (int i = level; i < nums.size(); ++i) {
        swap(nums[i], nums[level]);
        cout << "swap(nums[" << i << "]:" << nums[i] << ", " << "nums[" << level << "]:" << nums[level] << ")" << endl;
        backtracking(nums, level + 1, ans);
        swap(nums[i], nums[level]);
        cout << "swap(nums[" << i << "]:" << nums[i] << ", " << "nums[" << level << "]:" << nums[level] << ")" << endl;
    }
}
