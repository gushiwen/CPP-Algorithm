#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int lower_bound(vector<int>& nums, int target){
    int l = 0, r = nums.size() - 1, mid;
    while(l < r){
        mid = (l + r)/2;
        cout << "l:" << l << " r:" << r << " mid:" << mid << " -> " << "nums[" << mid << "]:" << nums[mid] << " target:" << target << endl;
        if(target <= nums[mid]){
            r = mid;
        } else{
            l = mid + 1;
        }
    }
    return l;
}

int upper_bound(vector<int>& nums, int target){
    int l = 0, r = nums.size() - 1, mid;
    while(l < r){
        mid = (l + r + 2 -1 )/2; // 向上取整 (a+b-1)/b or ceil((l + r)/2.0)
        cout << "l:" << l << " r:" << r << " mid:" << mid << " -> " << "nums[" << mid << "]:" << nums[mid] << " target:" << target << endl;
        if(target < nums[mid]){
            r = mid - 1;
        } else{
            l = mid;
        }
    }
    return l;
}

vector<int> searchRange(vector<int>& nums, int target){
    if(nums.empty()) return vector<int>{-1, -1};
    int lower = lower_bound(nums, target);
    cout << endl;
    int upper = upper_bound(nums, target);
    if(lower == nums.size() || nums[lower] != target){
        return vector<int>{-1, -1};
    }

    return vector<int>{lower, upper};
}

int main(){
    vector<int>nums{5,7,7,8,8,8};
    int target = 8;
    
    for(auto i : nums){
        cout << i << " ";
    }
    cout << endl;

    for(int i = 0; i < nums.size(); ++i){
        cout << i << " ";
    }
    cout << endl;

    for(auto i : searchRange(nums, target)){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}