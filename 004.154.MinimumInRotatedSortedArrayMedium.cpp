#include <iostream>
#include <vector>
using namespace std;

int searchMinimum(vector<int>& nums){
    int start = 0, end = nums.size() - 1, middle;
    while(start <= end){
        middle = (start + end) / 2;
        // nums[middle] <= nums[end] <= nums[start] 连接点在左边(包括middle)，右边递增
        // nums[middle] >= nums[start] 连接点在右边（包括middle），左边递增
        // nums[middle] == nums[start] 无法判断连接点位置
        // 未旋转时，左右都递增，优先找左边
        cout << "start:" << start << " end:" << end << " middle:" << middle << endl;
        if(nums[middle] == nums[start]){
            ++start;
        } else if(nums[middle] <= nums[end]){
            end = middle;
        } else {
            start = middle;
        }
    }
    cout << middle << endl;
    return nums[middle];
}

int main(){
    vector<int> nums{2,5,6,0,0,1,2};
    for(auto i : nums) cout << i << " ";
    cout << endl;
    for(int i = 0; i < nums.size(); ++i) cout << i << " ";
    cout << endl;
    cout << searchMinimum(nums);
    return 0;
}