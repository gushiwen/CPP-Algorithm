#include <iostream>
#include <vector>
using namespace std;

int removeOverlappingIntervals(vector< vector<int> >& intervals) {
    int size = intervals.size();
    if(size < 2){
        return size;
    }

    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
        return a[1] < b[1];
    });

    int total = 0;
    int prev = intervals[0][1];
    for(int i = 1; i < size; ++i){
        if(prev > intervals[i][0]){
            ++total;
        }
        else{
            prev = intervals[i][1];
        }
    }

    return total;
}

int main(){
    int intervals_array[3][2] = {{1,2}, {2,4}, {1,3}};
    vector<vector<int> > intervals_vector(3, vector<int>(2));
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 2; ++j){
            intervals_vector[i][j] = intervals_array[i][j];
        }
    }
    cout << removeOverlappingIntervals(intervals_vector) << endl;

    return 0;
}