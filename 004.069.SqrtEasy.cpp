#include <iostream>
using namespace std;

int getSqrt(int a){
    if(a == 0) return a;
    int l = 1, r = a, mid, sqrt;
    while(l <= r){
        mid = (l+r)/2;
        sqrt = a/mid;

        cout << "l:" << l << " r:" << r << " mid:" << mid << " sqrt:" << sqrt << endl;
        /*
        l:1 r:8 mid:4 sqrt:2
        l:1 r:3 mid:2 sqrt:4
        l:3 r:3 mid:3 sqrt:2 //sqrt<mid返回mid-1->r
        2

        l:1 r:12 mid:6 sqrt:2
        l:1 r:5 mid:3 sqrt:4
        l:4 r:5 mid:4 sqrt:3 // sqrt<mid返回mid-1->r
        3
        */

        if(sqrt == mid){
            return mid;
        } else if(sqrt < mid){
            r = mid -1;
        } else{
            l = mid + 1;
        }
    }
    return r;
}

int main(){
    cout << getSqrt(15) << endl;
}