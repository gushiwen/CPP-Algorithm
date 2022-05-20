#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target){
    int l = 0, r = numbers.size() - 1, sum;
    while(l < r ){
        sum = numbers[l] + numbers[r];
        if(sum == target) break;
        if(sum < target) ++l;
        else --r;
    }
    return vector<int>{l+1, r+1};
}

int main(){
    int numbers_array[] = {2, 7, 11, 12,13,15};
    int target = 19;

    vector<int> numbers_vector(numbers_array, end(numbers_array));

    for(auto i : twoSum(numbers_vector, target)){
        cout <<  i << " ";
    }

    return 0;
}