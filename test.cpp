/*
#include <iostream>
using namespace std;

int main(){
    cout << "i++: " << endl;
    for(int i=0; i<10; ++i){
        cout << i << endl;
    }

    cout << "++i: " << endl;
    for(int i=0; i<10; ++i){
        cout << i << endl;
    }
    return 0;
}
*/

/*
#include <numeric>  
#include <vector>
using namespace std;

int main(){
    int arr[]={10,20,30,40,50};  
    vector<int> va(&arr[0],&arr[5]);  
    int sum=accumulate(va.begin(),va.end(),0);  //sum = 150 
    printf("%d", sum);
    return 0;
}
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    vector<int> numbers_vector;
    numbers_vector.push_back(2);
    numbers_vector.push_back(7);
    numbers_vector.push_back(11);
    numbers_vector.push_back(15);
    for(auto i : numbers_vector){
        cout <<  i << " ";
    }

    cout << endl;
    
    int numbers_array2[] = {1, 2, 3, 4};
    //vector<int> numbers_vector2(numbers_array2, numbers_array2 + 4);
    vector<int> numbers_vector2(numbers_array2, end(numbers_array2));
    for(auto i : numbers_vector2){
        cout <<  i << " ";
    }
    cout << endl;

    cout << ceil(9/2) << " " << ceil(9/2.0) << endl;
    cout << "向上取整 (a+b-1)/b: " << (9+2-1)/2 << endl;
    return 0;
}