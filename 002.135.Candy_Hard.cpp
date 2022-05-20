#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int getCandyAmount(vector<int>& ratings){
    int size = ratings.size();
    if(size < 2) {
        return size;
    }
    
    vector<int> num(size, 1);
    for (int i = 1; i < size; ++i) {
        if(ratings[i] > ratings[i-1]) {
            num[i] = num[i-1] + 1;
        }

    }
    for(int i = size-1; i > 0; --i){
        if((ratings[i-1] > ratings[i]) && (num[i-1] <= num[i])){
            num[i-1] = num[i] + 1;
        }
    }

    return accumulate(num.begin(), num.end(), 0);
}

int main(){
    int children_ratings[] = {1, 0, 2};
    vector<int> cr(&children_ratings[0], &children_ratings[3]);
    cout << getCandyAmount(cr) << endl;
    return 0;
}