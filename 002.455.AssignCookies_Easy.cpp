//头文件
#include <iostream>
#include <vector>
using namespace std;

int getChildrenAmount(vector<int>& children, vector<int>& cookies) {

    /*
    for(int i=0; i<children.size(); i++)
    {
	    printf("children[%i]: %i\n", i, children[i]);
    }
    */
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());

    int child = 0, cookie = 0;
    while(child < children.size() && cookie < cookies.size()){
        if(children[child] <= cookies[cookie]){
            printf("(%i,%i)\n", children[child], cookies[cookie]);
            ++child;
        }
        ++cookie;
    }
    return child;
}

int main() {
    int a[4] = {1, 3, 5, 6};
    int b[3] = {1, 2, 1};
    //int b[6] = {1, 2, 3, 4, 5, 6};
    vector<int> children_vec(begin(a), end(a));
    vector<int> cookies_vec(begin(b), end(b));
    cout<<getChildrenAmount(children_vec, cookies_vec)<<endl;
    return 0;
}