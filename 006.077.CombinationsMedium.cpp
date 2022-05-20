#include <iostream>
#include <vector>
using namespace std;

void permute(int n, int k, int pos, int& count, vector<int>& nums, vector< vector<int> >& results) {
    if(count > k) {
        results.push_back(nums);
        return;
    }

    for(int i = pos; i <= n; ++i) {
        nums[count-1] = i;
        ++count;
        permute(n, k, i + 1, count, nums, results);
        --count;
    }

}

vector< vector<int> > combinate(int n, int k) {
    vector<int> nums(k, 0);
    int count = 1;
    vector< vector<int> > results;
    permute(n, k, 1, count, nums, results);
    return results;
}

int main() {
    int n = 4;
    int k = 3;
    vector< vector<int> > results = combinate(n, k);
    for (auto i : results) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}