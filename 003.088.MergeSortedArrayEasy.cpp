#include <iostream>
#include <vector>
using namespace std;

void mergeSortedArray(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int position = m-- + n-- - 1;
    while(m >=0 && n >= 0){
        nums1[position--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
    }
    while(n >=0){
        nums1[position--] = nums2[n--];
    }
}

int main(){
    int nums1_array[] = {1, 2, 3, 0, 0, 0};
    int m = 3;
    int nums2_array[] = {2, 5, 6};
    int n = 3;

    vector<int> nums1(nums1_array, end(nums1_array));
    vector<int> nums2(nums2_array, end(nums2_array));
    mergeSortedArray(nums1, m, nums2, n);

    for(auto i : nums1){
        cout << i << ' ';
    }
}