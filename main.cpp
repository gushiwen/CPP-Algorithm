/*
#include <iostream>
using namespace std;
*/

/* 
int main(){
    cout << "Hello World!" << endl;
    return 0;

}
*/

/*
int main()
{
    int a = 2;
    int b = 3;
    int c = a+b;
    cout<<"c="<<c<<endl;
    return 0;
}
*/

/*
#include <iostream>
using namespace std;

int main()
{
   cout << "Size of char : " << sizeof(char) << endl;
   cout << "Size of int : " << sizeof(int) << endl;
   cout << "Size of short int : " << sizeof(short int) << endl;
   cout << "Size of long int : " << sizeof(long int) << endl;
   cout << "Size of float : " << sizeof(float) << endl;
   cout << "Size of double : " << sizeof(double) << endl;
   cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
   return 0;
}
*/

/*
#include <iostream>
#include <cstring>

using namespace std;

int main ()
{
    char str1[11] = "Hello";
    char str2[11] = "World";
    char str3[11];
    int  len ;

    // 复制 str1 到 str3
    strcpy( str3, str1);
    cout << "strcpy( str3, str1) : " << str3 << endl;

    // 连接 str1 和 str2
    strcat( str1, str2);
    cout << "strcat( str1, str2): " << str1 << endl;

    // 连接后，str1 的总长度
    len = strlen(str1);
    cout << "strlen(str1) : " << len << endl;
    return 0;
}
*/

/*
#include <iostream>
#include <vector>
 
int main()
{
	std::vector<double>x(6);
	std::vector<double>y(6);
	for (int i = 0; i < 6; i++)
	{
		x[i] = i;
	}
	printf("%f\n",x[2]);
	return 0;
}
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a[5] = {1,2,3,4,5};
    /*
    for(int i=0; i<5; i++)
    {
	    printf("a[%i]: %i\n", i, a[i]);
    }
    */
    //printf("a[2]: %i\n",a[2]);

    //vector<int> b(5,1);
	//printf("b[.]: %i\n",b[2]);


    //通过数组a的地址初始化，注意地址是从0到5（左闭右开区间）
    vector<int> b(a, a+5);
    /*
    for(int i=0; i<b.size(); i++)
    {
	    printf("b[%i]: %i\n", i, b[i]);
    }
    */

    //b.insert(b.begin(), 6, 6);
    b.insert(b.begin(), 6, 6);
    for(int i=0; i<b.size(); i++)
    {
	    printf("b[%i]: %i\n", i, b[i]);
    }

	return 0;
}