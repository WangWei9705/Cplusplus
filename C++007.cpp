/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-16 15:38:03
 * Filename      : C++007.cpp
 * Description   : C++动态内存管理 
 * *******************************************************/

#include <iostream>
using namespace std;
class Data {
public:
    Data(int year = 2019, int month = 5, int day = 16) {
       cout << "Data::Data" << this << endl;
        _year = year;
        _month = month;
        _day = day;
    }

    ~Data() {
        cout << "Data::~Data" << this << endl;
    }
private:
    int _year;
    int _month;
    int _day;
};


int main() {

    Data* d1 = new Data;
    cout << d1 << endl;
    delete d1;

    Data* d2 = new Data[5];
    cout << d2 << endl;
    delete[] d2; 
    return 0;
}

#if 0
int main()
{
    // new运算符——申请空间——>调用构造函数将所申请的空间构造成一个完整的对象
    // delete 运算符——调用析构函数清理对象中的资源——>释放空间
    int* p1 = new int;      // 在堆上申请一个int 类型的空间
    delete p1;
    int* p2 = new int(10);           // 在申请空间的同时给p2初始化为10
    cout << *p2 << endl;
    delete p2;
    int* p3 = new int[5];
    delete[] p3;
   //  int* p4 = new int[5] {0,1,2,4,5};     // 申请5个连续的int型空间并依次初始化为1 2 3 4 5 
   //  cout << *p4 << endl;
   //  delete[] p4;

    return 0;
}
#endif
