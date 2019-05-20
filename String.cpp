/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-20 22:56:55
 * Filename      : string.cpp
 * Description   : STL容器之string类常用接口的使用
 * string ( );
 * string ( const string& str  );
 * string ( const string& str, size_t pos, size_t n = npos  );
 * string ( const char * s, size_t n  );
 * string ( const char * s  );
 * string ( size_t n, char c  );
 * template<class InputIterator> string (InputIterator begin, InputIterator end);
 * *******************************************************/
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string s1;    //使用string类构造空对象
    string s2("hello world");        // 使用C语言字符串构造
    string s3(3, 'c');
    string s4("haha", 5);
    string s5(s4);    // 拷贝构造

    cout << s2.size() << endl;   // 返回字符串有效字符长度,相当于strlen()函数，不计算/0
    cout << s2.length() << endl;  // 与size()函数功能相同
    cout << s2.capacity() << endl;  // 返回容量
    s2.clear();

    if(s2.empty()) {
        cout << "字符串为空 " << endl;
    }
    else {
         cout << "字符串不为空"  << endl;
    }

    s3.resize(5,'H');   // 将s3中的有效个数换为5个，多余空间用H补充
   cout << s1.capacity() << endl;
    s1.reserve(10);
    cout << s1.capacity() << endl;

    return 0;
}

