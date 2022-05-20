#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int>& nums, int target){
    int start = 0, end = nums.size() - 1, middle;
    while(start <= end){
        middle = (start + end) / 2;
        if(nums[middle] == target) return true;
        // nums[middle] <= nums[end] <= nums[start] 连接点在左边，右边递增
        // nums[middle] >= nums[start] 连接点在右边，左边递增
        // nums[middle] == nums[start] 无法判断连接点位置
        // 未旋转时，左右都递增
        if(nums[middle] == nums[start]){
            ++start;
        } else if(nums[middle] <= nums[end]){
            if(target >= nums[middle + 1] && target <= nums[end]){
                start = middle + 1;
            } else{
                end = middle - 1;
            }
        } else {
            if(target >= nums[start] && target <= nums[middle - 1]){
                end = middle - 1;
            } else{
                start = middle + 1;
            }
        }
    }
    return false;
}

int main(){
    vector<int> nums{2,5,6,0,0,1,2};
    int target = 9;
    cout << search(nums, target);
    return 0;
}