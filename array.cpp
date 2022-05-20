#include <iostream>
using namespace std;

/*
//对于字符串数组，使用strlen()函数来获取字符串数组的长度。
int main(){
    char a1[] = "fwegweasdasdwqew";
    cout << strlen(a1) << endl;
}
*/

template<class T>

int length(T& arr)
{
    //cout << sizeof(arr[0]) << endl;
    //cout << sizeof(arr) << endl;
    return sizeof(arr) / sizeof(arr[0]);
}

int main()
{
    int arr[] = { 1,5,9,10,9,2 };
    // 方法一
    cout << "数组的长度为：" << length(arr) << endl;
    // 方法二
    cout << end(arr) << endl;
    cout << begin(arr) << endl;
    cout << "数组的长度为：" << end(arr)-begin(arr) << endl;
    return 0;
}

/*
//在C++中，如果要多次获取不同数组的长度，为了避免重复写代码，可以定义一个求数组长度的模板。
template <class T>
int getlength(T& array)
{
 	return (sizeof(array) / sizeof(array[0]));
}

//数组作为函数参数传递的时候，传递的是指针，所以不能正确的求出子函数中传递进去的数组的长度。

int GetSize(int data[]) {
    return sizeof(data);
}
int main() {
    int data1[] = {1,2,3,4,5};
    int size1 = sizeof(data1);

    int *data2 = data1;
    int size2 = sizeof(data2);
    
    int size3 = GetSize(data1);
    
    cout<<size1<<" "<<size2<<" "<<size3<<endl;
    return 0;

}
*/