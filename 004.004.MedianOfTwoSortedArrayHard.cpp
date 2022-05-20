#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        int m = A.size(), n = B.size();
        // 如果是奇数
        if ((m + n) % 2 == 1) {
            return getKth(A, 0, A.size() - 1, B, 0, B.size() - 1, (m + n) / 2  + 1);
        }
        // 如果是偶数    
        int left = getKth(A, 0, A.size() - 1, B, 0, B.size() - 1, (m + n) / 2);
        int right = getKth(A, 0, A.size() - 1, B, 0, B.size() - 1, (m + n) / 2 + 1);
        return (left + right) / 2.0;  
    }
private:
    int getKth(vector<int>& A, int start1, int end1, vector<int>& B, int start2, int end2, int k) {
        cout << "A: " << " ";
        for(auto i : A){
            cout << i << " ";
        }
        cout << " start1:" << start1 << " ";
        cout << " end1:" << end1 << "";
        cout << " k:" << k << "";
        cout << endl;

        cout << "B: " << " ";
        for(auto i : B){
            cout << i << " ";
        }
        cout << " start2:" << start2 << " ";
        cout << " end2:" << end2 << "";
        cout << " k:" << k << "";
        cout << endl;

        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        // 让 len1 的长度小于 len2，这样就能保证如果有数组空了，一定是 len1 
        if (len1 > len2) {
            return getKth(B, start2, end2, A, start1, end1, k);
        }
        // A数组排除完毕
        if (len1 == 0) {
            return B[start2 + k - 1];
        } 
        // 已经找到第k小的数
        if (k == 1) {
            return min(A[start1], B[start2]);
        }
        // 开始二分
        int i = start1 + min(len1, k / 2) - 1;
        int j = start2 + min(len2, k / 2) - 1;

        cout << "i:" << i << " " << " A[i]:" << A[i] << " ";
        cout << "j:" << j << " " << " B[j]:" << B[j] << " ";
        cout << endl;
        cout << endl;

        if (A[i] > B[j]) {
            return getKth(A, start1, end1, B, j + 1, end2, k - (j - start2 + 1));
        }
        else {
            return getKth(A, i + 1, end1, B, start2, end2, k - (i - start1 + 1));
        }
    }
};

int main(){
    vector<int> num1{1,2,6,8,10};
    vector<int> num2{3,4,5,9,20};
    Solution solution;
    cout << solution.findMedianSortedArrays(num1, num2) << endl;;
    return 0;
}